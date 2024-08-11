#pragma once
#include<immintrin.h>
#include<array>
#include<bit>
#include<iostream>

namespace emath {
    class Vector2f {
    public:
        Vector2f() {
            v=_mm_setzero_ps();
        }
        explicit Vector2f(const float x) {
            v=_mm_set1_ps(x);
        }
        Vector2f(const float x,const float y) {
            v=_mm_set_ps(0.0f,0.0f,y,x);
        }
        explicit Vector2f(const std::array<float,2> x) {
            v=_mm_set_ps(0.0f,0.0f,x[1],x[0]);
        }
        explicit Vector2f(const __m128 x) {
            v=x;
        }

        void setX(const float x) {
            reinterpret_cast<float*>(&v)[0]=x;
        }
        void setY(const float y) {
            reinterpret_cast<float*>(&v)[1]=y;
        }

        float getX() const {
            return _mm_cvtss_f32(v);
        }
        float getY() const {
                return _mm_extract_ps(v,1);
        }

        Vector2f swizzleXX() const {
            return Vector2f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,0)));
        }
        Vector2f swizzleYX() const {
            return Vector2f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,1)));
        }
        Vector2f swizzleYY() const {
            return Vector2f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,1)));
        }

        Vector2f operator+(const Vector2f& rhs) const{
            return Vector2f(_mm_add_ps(v,rhs.v));
        }
        Vector2f operator+(const float rhs) const {
            return Vector2f(_mm_add_ps(v,_mm_set1_ps(rhs)));
        }
        void operator+=(const Vector2f& rhs){
            v=_mm_add_ps(v,rhs.v);
        }
        void operator+=(const float rhs) {
            v=_mm_add_ps(v,_mm_set1_ps(rhs));
        }
        Vector2f operator-(const Vector2f& rhs) const{
            return Vector2f(_mm_sub_ps(v,rhs.v));
        }
        Vector2f operator-(const float rhs) const {
            return Vector2f(_mm_sub_ps(v,_mm_set1_ps(rhs)));
        }
        void operator-=(const Vector2f& rhs) {
            v=_mm_sub_ps(v,rhs.v);
        }
        void operator-(const float rhs) {
            v=_mm_sub_ps(v,_mm_set1_ps(rhs));
        }
        Vector2f operator*(const Vector2f& rhs) const {
            return Vector2f(_mm_mul_ps(v,rhs.v));
        }
        Vector2f operator*(const float rhs) const {
            return Vector2f(_mm_mul_ps(v,_mm_set1_ps(rhs)));
        }
        void operator*=(const Vector2f& rhs) {
            v=_mm_mul_ps(v,rhs.v);
        }
        void operator*=(const float rhs) {
            v=_mm_mul_ps(v,_mm_set1_ps(rhs));
        }
        Vector2f operator/(const Vector2f& rhs) const {
            return Vector2f(_mm_div_ps(v,rhs.v));
        }
        Vector2f operator/(const float rhs) const {
            return Vector2f(_mm_div_ps(v,_mm_set1_ps(rhs)));
        }
        void operator/=(const Vector2f& rhs) {
            v=_mm_div_ps(v,rhs.v);
        }
        void operator/=(const float rhs) {
            v=_mm_div_ps(v,_mm_set1_ps(rhs));
        }
        Vector2f operator&(const Vector2f& rhs) const{
            return Vector2f(_mm_and_ps(v,rhs.v));
        }
        void operator&=(const Vector2f& rhs) {
            v=_mm_and_ps(v,rhs.v);
        }
        Vector2f operator|(const Vector2f& rhs) const {
            return Vector2f(_mm_or_ps(v,rhs.v));
        }
        void operator|=(const Vector2f& rhs) {
            v=_mm_or_ps(v,rhs.v);
        }
        bool operator==(const Vector2f& rhs) const{
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            constexpr auto epsilon=0.000001f;
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto arr=reinterpret_cast<const float*>(&tmp);
            if(arr[0]<epsilon)
            {
                if(arr[1]<epsilon)
                {
                    return true;
                }
            }
            return false;
        }
        bool operator!=(const Vector2f& rhs) const {
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            constexpr auto epsilon=0.000001f;
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto arr=reinterpret_cast<const float*>(&tmp);
            if(arr[0]>epsilon)
            {
                if(arr[1]>epsilon)
                {
                    return true;
                }
            }
            return false;
        }
        Vector2f operator-() const{
            const auto negate_const=_mm_set1_ps(std::bit_cast<float>(0x80000000));
            return Vector2f(_mm_xor_ps(v,negate_const));
        }
        
        float dot(const Vector2f& rhs) const{
            const auto tmp=_mm_mul_ps(v,rhs.v);
            const auto tmp_shf=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,2,1,1));
            return _mm_cvtss_f32(_mm_add_ss(tmp,tmp_shf));
        }
        Vector2f reflect(const Vector2f& normal) const{
            const auto const_2=_mm_set1_ps(2.0f);
            const auto tmp=_mm_mul_ps(v,normal.v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,0,0,0));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            const auto dot=_mm_add_ps(tmp_shf1,tmp_shf2);
            return Vector2f(_mm_sub_ps(v,_mm_mul_ps(_mm_mul_ps(const_2,dot),normal.v)));
        }
        float magnitude() const {
            const auto tmp=_mm_mul_ps(v,v);
            const auto tmp_shf=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            return sqrtf(_mm_cvtss_f32(_mm_add_ss(tmp,tmp_shf)));
        }
        float magnitudeSquared() const {
            const auto tmp=_mm_mul_ps(v,v);
            const auto tmp_shf=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            return _mm_cvtss_f32(_mm_add_ss(tmp,tmp_shf));
        }
        void normalize() {
            const auto tmp=_mm_mul_ps(v,v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,0,0,0));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            const auto mag=_mm_invsqrt_ps(_mm_add_ps(tmp_shf1,tmp_shf2));
            v=_mm_mul_ps(v,mag);
        }
        void abs() {
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            v=_mm_and_ps(v,abs_const);
        }
        void negate() {
            const auto negate_const=_mm_set1_ps(std::bit_cast<float>(0x80000000));
            v=_mm_xor_ps(v,negate_const);
        }
        bool equal(const Vector2f& rhs,const float epsilon) const {
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto arr=reinterpret_cast<const float*>(&tmp);
            if(arr[0]<epsilon)
            {
                if(arr[1]<epsilon)
                {
                    return true;
                }
            }
            return false;
        }
        std::array<float,2> getArray() const {
            std::array<float,2> array={};
            memcpy(array.data(),&v,8);
            return array;
        }
        void print() const {
            const auto array=reinterpret_cast<const float*>(&v);
            std::cout<<array[0]<<" "<<array[1]<<"\n";
        }

        friend std::ostream& operator<<(std::ostream& os,const Vector2f& vector);

        __m128 v;
    };

    inline std::ostream& operator<<(std::ostream& os,const Vector2f& vector) {
        const auto array=reinterpret_cast<const float*>(&vector.v);
        os<<array[0]<<" "<<array[1];
        return os;
    }
}