#pragma once
#include<immintrin.h>
#include<array>
#include<bit>
#include<iostream>
#include<math.h>

namespace emath {
    class Vector3f {
    public:
        Vector3f() {
            v=_mm_setzero_ps();
        }
        explicit Vector3f(const float x) {
            v=_mm_set1_ps(x);
        }
        Vector3f(const float x,const float y,const float z) {
            v=_mm_set_ps(0.0f,z,y,x);
        }
        explicit Vector3f(const float x[3]) {
            v=_mm_set_ps(0.0f,x[2],x[1],x[0]);
        }
        explicit Vector3f(const std::array<float,3> x) {
            v=_mm_set_ps(0.0f,x[2],x[1],x[0]);
        }
        explicit Vector3f(const __m128 x) {
            v=x;
        }

        void setX(const float x) {
            reinterpret_cast<float*>(&v)[0]=x;
        }
        void setY(const float y) {
            reinterpret_cast<float*>(&v)[1]=y;
        }
        void setZ(const float z) {
            reinterpret_cast<float*>(&v)[2]=z;
        }

        float getX() const {
            return _mm_cvtss_f32(v);
        }
        float getY() const {
            return  _mm_extract_ps(v,1);
        }
        float getZ() const {
            return _mm_extract_ps(v,2);
        }

        Vector3f swizzleXXX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,0,0)));
        }
        Vector3f swizzleXXY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,0)));
        }
        Vector3f swizzleXXZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,0)));
        }
        Vector3f swizzleXYX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,1,0)));
        }
        Vector3f swizzleXYY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,1,0)));
        }
        Vector3f swizzleXZX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,0)));
        }
        Vector3f swizzleXZY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,2,0)));
        }
        Vector3f swizzleXZZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,2,0)));
        }
        Vector3f swizzleYXX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,0,1)));
        }
        Vector3f swizzleYXY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,1)));
        }
        Vector3f swizzleYXZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,1)));
        }
        Vector3f swizzleYYX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,1,1)));
        }
        Vector3f swizzleYYY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,1,1)));
        }
        Vector3f swizzleYYZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,1)));
        }
        Vector3f swizzleYZX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,1)));
        }
        Vector3f swizzleYZY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,2,1)));
        }
        Vector3f swizzleYZZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,2,1)));
        }
        Vector3f swizzleZXX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,0,2)));
        }
        Vector3f swizzleZXY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,2)));
        }
        Vector3f swizzleZXZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,2)));
        }
        Vector3f swizzleZYX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,1,2)));
        }
        Vector3f swizzleZYY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,1,2)));
        }
        Vector3f swizzleZYZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,2)));
        }
        Vector3f swizzleZZX() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,2)));
        }
        Vector3f swizzleZZY() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,2,2)));
        }
        Vector3f swizzleZZZ() const{
            return Vector3f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,2,2)));
        }

        Vector3f operator+(const Vector3f& rhs) const{
            return Vector3f(_mm_add_ps(v,rhs.v));
        }
        Vector3f operator+(const float rhs) const {
            return Vector3f(_mm_add_ps(v,_mm_set1_ps(rhs)));
        }
        void operator+=(const Vector3f& rhs){
            v=_mm_add_ps(v,rhs.v);
        }
        void operator+=(const float rhs) {
            v=_mm_add_ps(v,_mm_set1_ps(rhs));
        }
        Vector3f operator-(const Vector3f& rhs) const{
            return Vector3f(_mm_sub_ps(v,rhs.v));
        }
        Vector3f operator-(const float rhs) const {
            return Vector3f(_mm_sub_ps(v,_mm_set1_ps(rhs)));
        }
        void operator-=(const Vector3f& rhs) {
            v=_mm_sub_ps(v,rhs.v);
        }
        void operator-(const float rhs) {
            v=_mm_sub_ps(v,_mm_set1_ps(rhs));
        }
        Vector3f operator*(const Vector3f& rhs) const {
            return Vector3f(_mm_mul_ps(v,rhs.v));
        }
        Vector3f operator*(const float rhs) const {
            return Vector3f(_mm_mul_ps(v,_mm_set1_ps(rhs)));
        }
        void operator*=(const Vector3f& rhs) {
            v=_mm_mul_ps(v,rhs.v);
        }
        void operator*=(const float rhs) {
            v=_mm_mul_ps(v,_mm_set1_ps(rhs));
        }
        Vector3f operator/(const Vector3f& rhs) const {
            return Vector3f(_mm_div_ps(v,rhs.v));
        }
        Vector3f operator/(const float rhs) const {
            return Vector3f(_mm_div_ps(v,_mm_set1_ps(rhs)));
        }
        void operator/=(const Vector3f& rhs) {
            v=_mm_div_ps(v,rhs.v);
        }
        void operator/=(const float rhs) {
            v=_mm_div_ps(v,_mm_set1_ps(rhs));
        }
        Vector3f operator&(const Vector3f& rhs) const{
            return Vector3f(_mm_and_ps(v,rhs.v));
        }
        void operator&=(const Vector3f& rhs) {
            v=_mm_and_ps(v,rhs.v);
        }
        Vector3f operator|(const Vector3f& rhs) const {
            return Vector3f(_mm_or_ps(v,rhs.v));
        }
        void operator|=(const Vector3f& rhs) {
            v=_mm_or_ps(v,rhs.v);
        }
        bool operator==(const Vector3f& rhs) const{
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            constexpr auto epsilon=0.000001f;
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto array=reinterpret_cast<const float*>(&tmp);
            if(array[0]<epsilon)
            {
                if(array[1]<epsilon)
                {
                    if(array[2]<epsilon)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool operator!=(const Vector3f& rhs) const {
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            constexpr auto epsilon=0.000001f;
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto array=reinterpret_cast<const float*>(&tmp);
            if(array[0]<epsilon)
            {
                if(array[1]<epsilon)
                {
                    if(array[2]<epsilon)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        Vector3f operator-() const{
            const auto negate_const=_mm_set1_ps(std::bit_cast<float>(0x80000000));
            return Vector3f(_mm_xor_ps(v,negate_const));
        }

        float dot(const Vector3f& rhs) const {
            const auto tmp=_mm_mul_ps(v,rhs.v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,2,1,1));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,2,1,2));
            return _mm_cvtss_f32(_mm_add_ss(tmp,_mm_add_ss(tmp_shf1,tmp_shf2)));
        }
        Vector3f cross(const Vector3f& rhs) const {
            const auto tmp_shf1=_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,1));
            const auto tmp_shf2=_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,2));
            const auto tmp_shf3=_mm_shuffle_ps(rhs.v,rhs.v,_MM_SHUFFLE(3,1,0,2));
            const auto tmp_shf4=_mm_shuffle_ps(rhs.v,rhs.v,_MM_SHUFFLE(3,0,2,1));
            const auto tmp_mul1=_mm_mul_ps(tmp_shf1,tmp_shf3);
            const auto tmp_mul2=_mm_mul_ps(tmp_shf2,tmp_shf4);
            return Vector3f(_mm_sub_ps(tmp_mul1,tmp_mul2));
        }
        Vector3f reflect(const Vector3f& normal) const {
            const auto const_2=_mm_set1_ps(2.0f);
            const auto tmp=_mm_mul_ps(v,normal.v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,0,0,0));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            const auto tmp_shf3=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,2,2,2));
            const auto dot=_mm_add_ps(tmp_shf1,_mm_add_ps(tmp_shf2,tmp_shf3));
            return Vector3f(_mm_sub_ps(v,_mm_mul_ps(_mm_mul_ps(const_2,dot),normal.v)));
        }
        float magnitude() const {
            const auto tmp=_mm_mul_ps(v,v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,2,2,2));
            return sqrtf(_mm_cvtss_f32(_mm_add_ss(tmp,_mm_add_ss(tmp_shf1,tmp_shf2))));
        }
        float magnitudeSquared() const {
            const auto tmp=_mm_mul_ps(v,v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,2,2,2));
            return _mm_cvtss_f32(_mm_add_ss(tmp,_mm_add_ss(tmp_shf1,tmp_shf2)));
        }
        void normalize() {
            const auto tmp=_mm_mul_ps(v,v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,0,0,0));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,1,1,1));
            const auto tmp_shf3=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,2,2,2));
            const auto mag=_mm_rsqrt_ps(_mm_add_ps(tmp_shf1,_mm_add_ps(tmp_shf2,tmp_shf3)));
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
        bool equal(const Vector3f& rhs,const float epsilon) const {
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto array=reinterpret_cast<const float*>(&tmp);
            if(array[0]<epsilon)
            {
                if(array[1]<epsilon)
                {
                    if(array[2]<epsilon)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        std::array<float,3> getArray() const {
            std::array<float,3> array={};
            memcpy(array.data(),&v,12);
            return array;
        }
        void print() const {
            const auto array=reinterpret_cast<const float*>(&v);
            std::cout<<array[0]<<" "<<array[1]<<" "<<array[2]<<"\n";
        }

        friend std::ostream& operator<<(std::ostream& os,const Vector3f& vector);

        __m128 v;
    };

    inline std::ostream& operator<<(std::ostream& os,const Vector3f& vector) {
        const auto array=reinterpret_cast<const float*>(&vector.v);
        os<<array[0]<<" "<<array[1]<<" "<<array[2];
        return os;
    }
}
