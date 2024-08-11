#pragma once

#include<immintrin.h>
#include<array>
#include<iostream>

namespace emath {
    class Vector3i {
    public:
        Vector3i() {
            v=_mm_set1_epi32(0);
        }
        explicit Vector3i(const int x) {
            v=_mm_set1_epi32(0);
        }
        Vector3i(const int x,const int y,const int z) {
            v=_mm_set_epi32(0,z,y,x);
        }
        explicit Vector3i(const std::array<int,3> x) {
            v=_mm_set_epi32(0,x[2],x[1],x[0]);
        }
        explicit Vector3i(const __m128i x) {
            v=x;
        }

        void setX(const int x) {
            reinterpret_cast<int*>(&v)[0]=x;
        }
        void setY(const int y) {
            reinterpret_cast<int*>(&v)[1]=y;
        }
        void setZ(const int z) {
            reinterpret_cast<int*>(&v)[2]=z;
        }

        int getX() const {
            return _mm_cvtsi128_si32(v);
        }
        int getY() const {
            return _mm_extract_epi32(v,1);
        }
        int getZ() const {
            return _mm_extract_epi32(v,2);
        }


        Vector3i swizzleXXX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,0,0)));
        }
        Vector3i swizzleXXY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,0,0)));
        }
        Vector3i swizzleXXZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,0,0)));
        }
        Vector3i swizzleXYX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,1,0)));
        }
        Vector3i swizzleXYY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,1,0)));
        }
        Vector3i swizzleXZX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,2,0)));
        }
        Vector3i swizzleXZY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,2,0)));
        }
        Vector3i swizzleXZZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,2,0)));
        }
        Vector3i swizzleYXX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,0,1)));
        }
        Vector3i swizzleYXY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,0,1)));
        }
        Vector3i swizzleYXZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,0,1)));
        }
        Vector3i swizzleYYX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,1,1)));
        }
        Vector3i swizzleYYY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,1,1)));
        }
        Vector3i swizzleYYZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,1,1)));
        }
        Vector3i swizzleYZX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,2,1)));
        }
        Vector3i swizzleYZY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,2,1)));
        }
        Vector3i swizzleYZZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,2,1)));
        }
        Vector3i swizzleZXX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,0,2)));
        }
        Vector3i swizzleZXY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,0,2)));
        }
        Vector3i swizzleZXZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,0,2)));
        }
        Vector3i swizzleZYX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,1,2)));
        }
        Vector3i swizzleZYY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,1,2)));
        }
        Vector3i swizzleZYZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,1,2)));
        }
        Vector3i swizzleZZX() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,0,2,2)));
        }
        Vector3i swizzleZZY() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,1,2,2)));
        }
        Vector3i swizzleZZZ() const {
            return Vector3i(_mm_shuffle_epi32(v,_MM_SHUFFLE(3,2,2,2)));
        }

        Vector3i operator+(const Vector3i& rhs) const {
            return Vector3i(_mm_add_epi32(v,rhs.v));
        }
        Vector3i operator+(const int rhs) const {
            return Vector3i(_mm_add_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator+=(const Vector3i& rhs) {
            v=_mm_add_epi32(v,rhs.v);
        }
        void operator+=(const int rhs) {
            v=_mm_add_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector3i operator-(const Vector3i& rhs) const {
            return Vector3i(_mm_sub_epi32(v,rhs.v));
        }
        Vector3i operator-(const int rhs) const {
            return Vector3i(_mm_sub_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator-=(const Vector3i& rhs) {
            v=_mm_sub_epi32(v,rhs.v);
        }
        void operator-=(const int rhs) {
            v=_mm_sub_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector3i operator*(const Vector3i& rhs) const{
            return Vector3i(_mm_mul_epi32(v,rhs.v));
        }
        Vector3i operator*(const int rhs) const{
            return Vector3i(_mm_mul_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator*=(const Vector3i& rhs) {
            v=_mm_mul_epi32(v,rhs.v);
        }
        void operator*=(const int rhs) {
            v=_mm_mul_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector3i operator/(const Vector3i& rhs) const {
            return Vector3i(_mm_div_epi32(v,rhs.v));
        }
        Vector3i operator/(const int rhs) const {
            return Vector3i(_mm_div_epi32(v,_mm_set1_epi32(rhs)));
        }
        void operator/=(const Vector3i& rhs) {
            v=_mm_div_epi32(v,rhs.v);
        }
        void operator/=(const int rhs) {
            v=_mm_div_epi32(v,_mm_set1_epi32(rhs));
        }
        Vector3i operator&(const Vector3i& rhs) const {
            return Vector3i(_mm_and_epi32(v,rhs.v));
        }
        void operator&=(const Vector3i& rhs) {
            v=_mm_and_epi32(v,rhs.v);
        }
        Vector3i operator|(const Vector3i& rhs) const {
            return Vector3i(_mm_or_epi32(v,rhs.v));
        }
        void operator|=(const Vector3i& rhs) {
            v=_mm_or_epi32(v,rhs.v);
        }
        bool operator==(const Vector3i& rhs) const {
            const auto arr1=reinterpret_cast<const int*>(&v);
            const auto arr2=reinterpret_cast<const int*>(&rhs.v);
            if(arr1[0]==arr2[0])
            {
                if(arr1[1]==arr2[1])
                {
                    if(arr1[2]==arr2[2])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool operator!=(const Vector3i& rhs) const {
            const auto arr1=reinterpret_cast<const int*>(&v);
            const auto arr2=reinterpret_cast<const int*>(&rhs.v);
            if(arr1[0]!=arr2[0])
            {
                if(arr1[1]!=arr2[1])
                {
                    if(arr1[2]!=arr2[2])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        Vector3i operator-() const {
            const auto negate_const=_mm_set1_epi32(0x80000000);
            return Vector3i(_mm_xor_epi32(v,negate_const));
        }

        int dot(const Vector3i& rhs) const {
            const auto tmp=_mm_mul_epi32(v,rhs.v);
            const auto tmp_shf1=_mm_shuffle_epi32(tmp,_MM_SHUFFLE(3,2,1,1));
            const auto tmp_shf2=_mm_shuffle_epi32(tmp,_MM_SHUFFLE(3,2,1,2));
            return _mm_cvtsi128_si32(_mm_add_epi32(tmp,_mm_add_epi32(tmp_shf1,tmp_shf2)));
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
            std::cout<<array[0]<<" "<<array[1]<<" "<<array[2]<<"\n";
        }

        friend std::ostream& operator<<(std::ostream& os,const Vector3i& vector);

        __m128i v;
    };

    inline std::ostream& operator<<(std::ostream& os,const Vector3i& vector) {
        const auto array=reinterpret_cast<const int*>(&vector.v);
        os<<array[0]<<" "<<array[1]<<" "<<array[2];
        return os;
    }
}