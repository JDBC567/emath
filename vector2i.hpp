#pragma once

#include<immintrin.h>
#include<array>
#include<iostream>

namespace emath {
    class Vector2i {
    public:
        Vector2i() {
            v=_mm_set1_epi32(0);
        }
        explicit Vector2i(const int x) {
            v=_mm_set1_epi32(0);
        }
        Vector2i(const int x,const int y) {
            v=_mm_set_epi32(0,0,y,x);
        }
        explicit Vector2i(const std::array<int,2> x) {
            v=_mm_set_epi32(0,0,x[1],x[0]);
        }
        explicit Vector2i(const __m128i x) {
            v=x;
        }

        void setX(const int x) {
            reinterpret_cast<int*>(&v)[0]=x;
        }
        void setY(const int y) {
            reinterpret_cast<int*>(&v)[1]=y;
        }

        int getX() const {
            return _mm_cvtsi128_si32(v);
        }
        int getY() const {
            return _mm_extract_epi32(v,1);
        }

        Vector2i swizzleXX() const {
            return Vector2i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,0,0)));
        }
        Vector2i swizzleYX() const {
            return Vector2i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,0,1)));
        }
        Vector2i swizzleYY() const {
            return Vector2i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,1,1)));
        }

        Vector2i operator+(const Vector2i& rhs) const {
            return Vector2i(_mm_add_epi32(v,rhs.v));
        }
        Vector2i operator+(const int rhs) const {
            return Vector2i(_mm_add_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator+=(const Vector2i& rhs) {
            v=_mm_add_epi32(v,rhs.v);
        }
        void operator+=(const int rhs) {
            v=_mm_add_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector2i operator-(const Vector2i& rhs) const {
            return Vector2i(_mm_sub_epi32(v,rhs.v));
        }
        Vector2i operator-(const int rhs) const {
            return Vector2i(_mm_sub_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator-=(const Vector2i& rhs) {
            v=_mm_sub_epi32(v,rhs.v);
        }
        void operator-=(const int rhs) {
            v=_mm_sub_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector2i operator*(const Vector2i& rhs) const{
            return Vector2i(_mm_mul_epi32(v,rhs.v));
        }
        Vector2i operator*(const int rhs) const{
            return Vector2i(_mm_mul_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator*=(const Vector2i& rhs) {
            v=_mm_mul_epi32(v,rhs.v);
        }
        void operator*=(const int rhs) {
            v=_mm_mul_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector2i operator/(const Vector2i& rhs) const {
            return Vector2i(_mm_div_epi32(v,rhs.v));
        }
        Vector2i operator/(const int rhs) const {
            return Vector2i(_mm_div_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator/=(const Vector2i& rhs) {
            v=_mm_div_epi32(v,rhs.v);
        }
        void operator/=(const int rhs) {
            v=_mm_div_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector2i operator&(const Vector2i& rhs) const {
            return Vector2i(_mm_and_epi32(v,rhs.v));
        }
        void operator&=(const Vector2i& rhs) {
            v=_mm_and_epi32(v,rhs.v);
        }
        Vector2i operator|(const Vector2i& rhs) const {
            return Vector2i(_mm_or_epi32(v,rhs.v));
        }
        void operator|=(const Vector2i& rhs) {
            v=_mm_or_epi32(v,rhs.v);
        }
        bool operator==(const Vector2i& rhs) const {
            const auto arr1=reinterpret_cast<const int*>(&v);
            const auto arr2=reinterpret_cast<const int*>(&rhs.v);
            if(arr1[0]==arr2[0])
            {
                if(arr1[0]==arr2[0])
                {
                    return true;
                }
            }
            return false;
        }
        bool operator!=(const Vector2i& rhs) const {
            const auto arr1=reinterpret_cast<const int*>(&v);
            const auto arr2=reinterpret_cast<const int*>(&rhs.v);
            if(arr1[0]!=arr2[0])
            {
                if(arr1[1]!=arr2[1])
                {
                    return true;
                }
            }
            return false;
        }
        Vector2i operator-() const {
            const auto negate_const=_mm_set1_epi32(0x80000000);
            return Vector2i(_mm_xor_epi32(v,negate_const));
        }

        int dot(const Vector2i& rhs) const {
            const auto tmp=_mm_mul_epi32(v,rhs.v);
            const auto tmp_shf1=_mm_shuffle_epi32(tmp,_MM_SHUFFLE(3,2,1,1));
            return _mm_cvtsi128_si32(_mm_add_epi32(tmp,tmp_shf1));
        }
        void abs() {
            const auto abs_const=_mm_set1_epi32(0x7FFFFFFF);
            v=_mm_and_epi32(v,abs_const);
        }
        void negate() {
            const auto negate_const=_mm_set1_epi32(0x80000000);
            v=_mm_xor_epi32(v,negate_const);
        }
        void print() const {
            const auto array=reinterpret_cast<const int*>(&v);
            std::cout<<array[0]<<" "<<array[1]<<"\n";
        }

        friend std::ostream& operator<<(std::ostream& os,const Vector2i& vector);

        __m128i v;
    };

    inline std::ostream& operator<<(std::ostream& os,const Vector2i& vector) {
        const auto array=reinterpret_cast<const int*>(&vector.v);
        os<<array[0]<<" "<<array[1];
        return os;
    }
}