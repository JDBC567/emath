#pragma once
#include<immintrin.h>
#include<array>
#include <bit>
#include <iostream>

namespace emath {
    class Vector4f {
    public:
        Vector4f() {
            v=_mm_setzero_ps();
        }
        explicit Vector4f(const float x) {
            v=_mm_set1_ps(x);
        }
        Vector4f(const float x,const float y,const float z,const float w) {
            v=_mm_set_ps(w,z,y,x);
        }
        explicit Vector4f(const float x[4]) {
            v=_mm_loadu_ps(&x[0]);
        }
        explicit Vector4f(const std::array<float,4> x) {
            v=_mm_loadu_ps(x.data());
        }
        explicit Vector4f(const __m128 x) {
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
        void setW(const float w) {
            reinterpret_cast<float*>(&v)[3]=w;
        }

        float getX() const {
            return _mm_cvtss_f32(v);
        }
        float getY() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,1)));
        }
        float getZ() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,2)));
        }
        float getW() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,3)));
        }

        Vector4f swizzleXXXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,0,0)));
        }
        Vector4f swizzleXXXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,0,0)));
        }
        Vector4f swizzleXXXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,0,0)));
        }
        Vector4f swizzleXXXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,0,0)));
        }
        Vector4f swizzleXXYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,0,0)));
        }
        Vector4f swizzleXXYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,0,0)));
        }
        Vector4f swizzleXXYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,0,0)));
        }
        Vector4f swizzleXXYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,0)));
        }
        Vector4f swizzleXXZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,0,0)));
        }
        Vector4f swizzleXXZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,0,0)));
        }
        Vector4f swizzleXXZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,0,0)));
        }
        Vector4f swizzleXXZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,0)));
        }
        Vector4f swizzleXXWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,0,0)));
        }
        Vector4f swizzleXXWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,0,0)));
        }
        Vector4f swizzleXXWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,0,0)));
        }
        Vector4f swizzleXXWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,0,0)));
        }
        Vector4f swizzleXYXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,1,0)));
        }
        Vector4f swizzleXYXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,1,0)));
        }
        Vector4f swizzleXYXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,1,0)));
        }
        Vector4f swizzleXYXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,1,0)));
        }
        Vector4f swizzleXYYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,1,0)));
        }
        Vector4f swizzleXYYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,1,0)));
        }
        Vector4f swizzleXYYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,1,0)));
        }
        Vector4f swizzleXYYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,1,0)));
        }
        Vector4f swizzleXYZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,1,0)));
        }
        Vector4f swizzleXYZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,1,0)));
        }
        Vector4f swizzleXYZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,1,0)));
        }
        Vector4f swizzleXYWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,1,0)));
        }
        Vector4f swizzleXYWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,1,0)));
        }
        Vector4f swizzleXYWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,1,0)));
        }
        Vector4f swizzleXYWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,1,0)));
        }
        Vector4f swizzleXZXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,2,0)));
        }
        Vector4f swizzleXZXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,2,0)));
        }
        Vector4f swizzleXZXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,2,0)));
        }
        Vector4f swizzleXZXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,0)));
        }
        Vector4f swizzleXZYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,2,0)));
        }
        Vector4f swizzleXZYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,2,0)));
        }
        Vector4f swizzleXZYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,2,0)));
        }
        Vector4f swizzleXZYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,2,0)));
        }
        Vector4f swizzleXZZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,2,0)));
        }
        Vector4f swizzleXZZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,2,0)));
        }
        Vector4f swizzleXZZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,2,0)));
        }
        Vector4f swizzleXZZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,2,0)));
        }
        Vector4f swizzleXZWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,2,0)));
        }
        Vector4f swizzleXZWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,2,0)));
        }
        Vector4f swizzleXZWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,2,0)));
        }
        Vector4f swizzleXZWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,2,0)));
        }
        Vector4f swizzleXWXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,3,0)));
        }
        Vector4f swizzleXWXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,3,0)));
        }
        Vector4f swizzleXWXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,3,0)));
        }
        Vector4f swizzleXWXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,3,0)));
        }
        Vector4f swizzleXWYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,3,0)));
        }
        Vector4f swizzleXWYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,3,0)));
        }
        Vector4f swizzleXWYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,3,0)));
        }
        Vector4f swizzleXWYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,3,0)));
        }
        Vector4f swizzleXWZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,3,0)));
        }
        Vector4f swizzleXWZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,3,0)));
        }
        Vector4f swizzleXWZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,3,0)));
        }
        Vector4f swizzleXWZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,3,0)));
        }
        Vector4f swizzleXWWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,3,0)));
        }
        Vector4f swizzleXWWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,3,0)));
        }
        Vector4f swizzleXWWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,3,0)));
        }
        Vector4f swizzleXWWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,3,0)));
        }
        Vector4f swizzleYXXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,0,1)));
        }
        Vector4f swizzleYXXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,0,1)));
        }
        Vector4f swizzleYXXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,0,1)));
        }
        Vector4f swizzleYXXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,0,1)));
        }
        Vector4f swizzleYXYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,0,1)));
        }
        Vector4f swizzleYXYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,0,1)));
        }
        Vector4f swizzleYXYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,0,1)));
        }
        Vector4f swizzleYXYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,1)));
        }
        Vector4f swizzleYXZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,0,1)));
        }
        Vector4f swizzleYXZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,0,1)));
        }
        Vector4f swizzleYXZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,0,1)));
        }
        Vector4f swizzleYXZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,1)));
        }
        Vector4f swizzleYXWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,0,1)));
        }
        Vector4f swizzleYXWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,0,1)));
        }
        Vector4f swizzleYXWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,0,1)));
        }
        Vector4f swizzleYXWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,0,1)));
        }
        Vector4f swizzleYYXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,1,1)));
        }
        Vector4f swizzleYYXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,1,1)));
        }
        Vector4f swizzleYYXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,1,1)));
        }
        Vector4f swizzleYYXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,1,1)));
        }
        Vector4f swizzleYYYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,1,1)));
        }
        Vector4f swizzleYYYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,1,1)));
        }
        Vector4f swizzleYYYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,1,1)));
        }
        Vector4f swizzleYYYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,1,1)));
        }
        Vector4f swizzleYYZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,1,1)));
        }
        Vector4f swizzleYYZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,1,1)));
        }
        Vector4f swizzleYYZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,1,1)));
        }
        Vector4f swizzleYYZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,1)));
        }
        Vector4f swizzleYYWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,1,1)));
        }
        Vector4f swizzleYYWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,1,1)));
        }
        Vector4f swizzleYYWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,1,1)));
        }
        Vector4f swizzleYYWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,1,1)));
        }
        Vector4f swizzleYZXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,2,1)));
        }
        Vector4f swizzleYZXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,2,1)));
        }
        Vector4f swizzleYZXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,2,1)));
        }
        Vector4f swizzleYZXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,1)));
        }
        Vector4f swizzleYZYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,2,1)));
        }
        Vector4f swizzleYZYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,2,1)));
        }
        Vector4f swizzleYZYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,2,1)));
        }
        Vector4f swizzleYZYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,2,1)));
        }
        Vector4f swizzleYZZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,2,1)));
        }
        Vector4f swizzleYZZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,2,1)));
        }
        Vector4f swizzleYZZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,2,1)));
        }
        Vector4f swizzleYZZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,2,1)));
        }
        Vector4f swizzleYZWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,2,1)));
        }
        Vector4f swizzleYZWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,2,1)));
        }
        Vector4f swizzleYZWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,2,1)));
        }
        Vector4f swizzleYZWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,2,1)));
        }
        Vector4f swizzleYWXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,3,1)));
        }
        Vector4f swizzleYWXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,3,1)));
        }
        Vector4f swizzleYWXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,3,1)));
        }
        Vector4f swizzleYWXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,3,1)));
        }
        Vector4f swizzleYWYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,3,1)));
        }
        Vector4f swizzleYWYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,3,1)));
        }
        Vector4f swizzleYWYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,3,1)));
        }
        Vector4f swizzleYWYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,3,1)));
        }
        Vector4f swizzleYWZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,3,1)));
        }
        Vector4f swizzleYWZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,3,1)));
        }
        Vector4f swizzleYWZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,3,1)));
        }
        Vector4f swizzleYWZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,3,1)));
        }
        Vector4f swizzleYWWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,3,1)));
        }
        Vector4f swizzleYWWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,3,1)));
        }
        Vector4f swizzleYWWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,3,1)));
        }
        Vector4f swizzleYWWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,3,1)));
        }
        Vector4f swizzleZXXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,0,2)));
        }
        Vector4f swizzleZXXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,0,2)));
        }
        Vector4f swizzleZXXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,0,2)));
        }
        Vector4f swizzleZXXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,0,2)));
        }
        Vector4f swizzleZXYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,0,2)));
        }
        Vector4f swizzleZXYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,0,2)));
        }
        Vector4f swizzleZXYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,0,2)));
        }
        Vector4f swizzleZXYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,2)));
        }
        Vector4f swizzleZXZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,0,2)));
        }
        Vector4f swizzleZXZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,0,2)));
        }
        Vector4f swizzleZXZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,0,2)));
        }
        Vector4f swizzleZXZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,2)));
        }
        Vector4f swizzleZXWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,0,2)));
        }
        Vector4f swizzleZXWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,0,2)));
        }
        Vector4f swizzleZXWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,0,2)));
        }
        Vector4f swizzleZXWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,0,2)));
        }
        Vector4f swizzleZYXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,1,2)));
        }
        Vector4f swizzleZYXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,1,2)));
        }
        Vector4f swizzleZYXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,1,2)));
        }
        Vector4f swizzleZYXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,1,2)));
        }
        Vector4f swizzleZYYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,1,2)));
        }
        Vector4f swizzleZYYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,1,2)));
        }
        Vector4f swizzleZYYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,1,2)));
        }
        Vector4f swizzleZYYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,1,2)));
        }
        Vector4f swizzleZYZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,1,2)));
        }
        Vector4f swizzleZYZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,1,2)));
        }
        Vector4f swizzleZYZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,1,2)));
        }
        Vector4f swizzleZYZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,2)));
        }
        Vector4f swizzleZYWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,1,2)));
        }
        Vector4f swizzleZYWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,1,2)));
        }
        Vector4f swizzleZYWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,1,2)));
        }
        Vector4f swizzleZYWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,1,2)));
        }
        Vector4f swizzleZZXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,2,2)));
        }
        Vector4f swizzleZZXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,2,2)));
        }
        Vector4f swizzleZZXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,2,2)));
        }
        Vector4f swizzleZZXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,2)));
        }
        Vector4f swizzleZZYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,2,2)));
        }
        Vector4f swizzleZZYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,2,2)));
        }
        Vector4f swizzleZZYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,2,2)));
        }
        Vector4f swizzleZZYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,2,2)));
        }
        Vector4f swizzleZZZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,2,2)));
        }
        Vector4f swizzleZZZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,2,2)));
        }
        Vector4f swizzleZZZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,2,2)));
        }
        Vector4f swizzleZZZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,2,2)));
        }
        Vector4f swizzleZZWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,2,2)));
        }
        Vector4f swizzleZZWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,2,2)));
        }
        Vector4f swizzleZZWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,2,2)));
        }
        Vector4f swizzleZZWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,2,2)));
        }
        Vector4f swizzleZWXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,3,2)));
        }
        Vector4f swizzleZWXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,3,2)));
        }
        Vector4f swizzleZWXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,3,2)));
        }
        Vector4f swizzleZWXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,3,2)));
        }
        Vector4f swizzleZWYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,3,2)));
        }
        Vector4f swizzleZWYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,3,2)));
        }
        Vector4f swizzleZWYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,3,2)));
        }
        Vector4f swizzleZWYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,3,2)));
        }
        Vector4f swizzleZWZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,3,2)));
        }
        Vector4f swizzleZWZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,3,2)));
        }
        Vector4f swizzleZWZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,3,2)));
        }
        Vector4f swizzleZWZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,3,2)));
        }
        Vector4f swizzleZWWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,3,2)));
        }
        Vector4f swizzleZWWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,3,2)));
        }
        Vector4f swizzleZWWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,3,2)));
        }
        Vector4f swizzleZWWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,3,2)));
        }
        Vector4f swizzleWXXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,0,3)));
        }
        Vector4f swizzleWXXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,0,3)));
        }
        Vector4f swizzleWXXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,0,3)));
        }
        Vector4f swizzleWXXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,0,3)));
        }
        Vector4f swizzleWXYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,0,3)));
        }
        Vector4f swizzleWXYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,0,3)));
        }
        Vector4f swizzleWXYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,0,3)));
        }
        Vector4f swizzleWXYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,0,3)));
        }
        Vector4f swizzleWXZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,0,3)));
        }
        Vector4f swizzleWXZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,0,3)));
        }
        Vector4f swizzleWXZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,0,3)));
        }
        Vector4f swizzleWXZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,0,3)));
        }
        Vector4f swizzleWXWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,0,3)));
        }
        Vector4f swizzleWXWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,0,3)));
        }
        Vector4f swizzleWXWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,0,3)));
        }
        Vector4f swizzleWXWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,0,3)));
        }
        Vector4f swizzleWYXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,1,3)));
        }
        Vector4f swizzleWYXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,1,3)));
        }
        Vector4f swizzleWYXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,1,3)));
        }
        Vector4f swizzleWYXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,1,3)));
        }
        Vector4f swizzleWYYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,1,3)));
        }
        Vector4f swizzleWYYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,1,3)));
        }
        Vector4f swizzleWYYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,1,3)));
        }
        Vector4f swizzleWYYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,1,3)));
        }
        Vector4f swizzleWYZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,1,3)));
        }
        Vector4f swizzleWYZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,1,3)));
        }
        Vector4f swizzleWYZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,1,3)));
        }
        Vector4f swizzleWYZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,1,3)));
        }
        Vector4f swizzleWYWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,1,3)));
        }
        Vector4f swizzleWYWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,1,3)));
        }
        Vector4f swizzleWYWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,1,3)));
        }
        Vector4f swizzleWYWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,1,3)));
        }
        Vector4f swizzleWZXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,2,3)));
        }
        Vector4f swizzleWZXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,2,3)));
        }
        Vector4f swizzleWZXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,2,3)));
        }
        Vector4f swizzleWZXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,2,3)));
        }
        Vector4f swizzleWZYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,2,3)));
        }
        Vector4f swizzleWZYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,2,3)));
        }
        Vector4f swizzleWZYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,2,3)));
        }
        Vector4f swizzleWZYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,2,3)));
        }
        Vector4f swizzleWZZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,2,3)));
        }
        Vector4f swizzleWZZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,2,3)));
        }
        Vector4f swizzleWZZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,2,3)));
        }
        Vector4f swizzleWZZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,2,3)));
        }
        Vector4f swizzleWZWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,2,3)));
        }
        Vector4f swizzleWZWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,2,3)));
        }
        Vector4f swizzleWZWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,2,3)));
        }
        Vector4f swizzleWZWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,2,3)));
        }
        Vector4f swizzleWWXX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,0,3,3)));
        }
        Vector4f swizzleWWXY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,0,3,3)));
        }
        Vector4f swizzleWWXZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,0,3,3)));
        }
        Vector4f swizzleWWXW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,0,3,3)));
        }
        Vector4f swizzleWWYX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,1,3,3)));
        }
        Vector4f swizzleWWYY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,3,3)));
        }
        Vector4f swizzleWWYZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,1,3,3)));
        }
        Vector4f swizzleWWYW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,1,3,3)));
        }
        Vector4f swizzleWWZX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,2,3,3)));
        }
        Vector4f swizzleWWZY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,2,3,3)));
        }
        Vector4f swizzleWWZZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,3,3)));
        }
        Vector4f swizzleWWZW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,2,3,3)));
        }
        Vector4f swizzleWWWX() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(0,3,3,3)));
        }
        Vector4f swizzleWWWY() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,3,3,3)));
        }
        Vector4f swizzleWWWZ() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,3,3,3)));
        }
        Vector4f swizzleWWWW() const{
            return Vector4f(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,3,3)));
        }

        Vector4f operator+(const Vector4f& rhs) const {
            return Vector4f(_mm_add_ps(v,rhs.v));
        }
        Vector4f operator+(const float rhs) const {
            return Vector4f(_mm_add_ps(v,_mm_set1_ps(rhs)));
        }
        void operator+=(const Vector4f& rhs) {
            v=_mm_add_ps(v,rhs.v);
        }
        void operator+=(const float rhs) {
            v=_mm_add_ps(v,_mm_set1_ps(rhs));
        }
        Vector4f operator-(const Vector4f& rhs) const {
            return Vector4f(_mm_sub_ps(v,rhs.v));
        }
        Vector4f operator-(const float rhs) const {
            return Vector4f(_mm_sub_ps(v,_mm_set1_ps(rhs)));
        }
        void operator-=(const Vector4f& rhs) {
            v=_mm_sub_ps(v,rhs.v);
        }
        void operator-=(const float rhs) {
            v=_mm_sub_ps(v,_mm_set1_ps(rhs));
        }
        Vector4f operator*(const Vector4f& rhs) const{
            return Vector4f(_mm_mul_ps(v,rhs.v));
        }
        Vector4f operator*(const float rhs) const {
            return Vector4f(_mm_mul_ps(v,_mm_set1_ps(rhs)));
        }
        void operator*=(const Vector4f& rhs) {
            v=_mm_mul_ps(v,rhs.v);
        }
        void operator*=(const float rhs) {
            v=_mm_mul_ps(v,_mm_set1_ps(rhs));
        }
        Vector4f operator/(const Vector4f& rhs) const{
            return Vector4f(_mm_div_ps(v,rhs.v));
        }
        Vector4f operator/(const float rhs) const {
            return Vector4f(_mm_div_ps(v,_mm_set1_ps(rhs)));
        }
        void operator/=(const Vector4f& rhs) {
            v=_mm_div_ps(v,rhs.v);
        }
        void operator/=(const float rhs) {
            v=_mm_div_ps(v,_mm_set1_ps(rhs));
        }
        Vector4f operator&(const Vector4f& rhs) const {
            return Vector4f(_mm_and_ps(v,rhs.v));
        }
        void operator&=(const Vector4f& rhs) {
            v=_mm_and_ps(v,rhs.v);
        }
        Vector4f operator|(const Vector4f& rhs) const {
            return Vector4f(_mm_or_ps(v,rhs.v));
        }
        void operator|=(const Vector4f& rhs) {
            v=_mm_or_ps(v,rhs.v);
        }
        bool operator==(const Vector4f& rhs) const {
            constexpr float epsilon=0.0000001f;
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto array=reinterpret_cast<const float*>(&tmp);
            if(array[0]<epsilon)
            {
                if(array[1]<epsilon)
                {
                    if(array[2]<epsilon)
                    {
                        if(array[3]<epsilon)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        bool operator!=(const Vector4f& rhs) const {
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            constexpr float epsilon=0.0000001f;
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto array=reinterpret_cast<const float*>(&tmp);
            if(array[0]>epsilon)
            {
                if(array[1]>epsilon)
                {
                    if(array[2]>epsilon)
                    {
                        if(array[3]>epsilon)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        Vector4f operator-() const {
            const auto negate_const=_mm_set1_ps(std::bit_cast<float>(0x80000000));
            return Vector4f(_mm_xor_ps(v,negate_const));
        }

        float dot(const Vector4f& rhs) const {
            const auto tmp=_mm_mul_ps(v,rhs.v);
            auto tmp_shf = _mm_movehdup_ps(tmp);
            auto tmp_sum = _mm_add_ps(tmp, tmp_shf);
            tmp_shf = _mm_movehl_ps(tmp_shf, tmp_sum);
            tmp_sum = _mm_add_ss(tmp_sum, tmp_shf);
            return _mm_cvtss_f32(tmp_sum);
        }
        Vector4f reflect(const Vector4f& normal) const {
            const auto const_2=_mm_set1_ps(2.0f);
            const auto tmp=_mm_mul_ps(v,normal.v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(0,0,0,0));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(1,1,1,1));
            const auto tmp_shf3=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(2,2,2,2));
            const auto tmp_shf4=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,3,3,3));
            const auto tmp_add1=_mm_add_ps(tmp_shf1,tmp_shf2);
            const auto tmp_add2=_mm_add_ps(tmp_shf3,tmp_shf4);
            const auto dot=_mm_add_ps(tmp_add1,tmp_add2);
            return Vector4f(_mm_sub_ps(v,_mm_mul_ps(_mm_mul_ps(const_2,dot),normal.v)));
        }
        float magnitude() const {
            const auto tmp=_mm_mul_ps(v,v);
            auto tmp_shf = _mm_movehdup_ps(tmp);
            auto tmp_sum = _mm_add_ps(tmp, tmp_shf);
            tmp_shf = _mm_movehl_ps(tmp_shf, tmp_sum);
            tmp_sum = _mm_add_ss(tmp_sum, tmp_shf);
            return sqrtf(_mm_cvtss_f32(tmp_sum));
        }
        float magnitudeSquared() const {
            const auto tmp=_mm_mul_ps(v,v);
            auto tmp_shf = _mm_movehdup_ps(tmp);
            auto tmp_sum = _mm_add_ps(tmp, tmp_shf);
            tmp_shf = _mm_movehl_ps(tmp_shf, tmp_sum);
            tmp_sum = _mm_add_ss(tmp_sum, tmp_shf);
            return _mm_cvtss_f32(tmp_sum);
        }
        void normalize() {
            const auto tmp=_mm_mul_ps(v,v);
            const auto tmp_shf1=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(0,0,0,0));
            const auto tmp_shf2=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(1,1,1,1));
            const auto tmp_shf3=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(2,2,2,2));
            const auto tmp_shf4=_mm_shuffle_ps(tmp,tmp,_MM_SHUFFLE(3,3,3,3));
            const auto tmp_add1=_mm_add_ps(tmp_shf1,tmp_shf2);
            const auto tmp_add2=_mm_add_ps(tmp_shf3,tmp_shf4);
            const auto mag=_mm_rsqrt_ps(_mm_add_ps(tmp_add1,tmp_add2));
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
        bool equal(const Vector4f& rhs,const float epsilon) const {
            const auto abs_const=_mm_set1_ps(std::bit_cast<float>(0x7FFFFFFF));
            const auto tmp=_mm_and_ps(_mm_sub_ps(v,rhs.v),abs_const);
            const auto array=reinterpret_cast<const float*>(&tmp);
            if(array[0]<epsilon)
            {
                if(array[1]<epsilon)
                {
                    if(array[2]<epsilon)
                    {
                        if(array[3]<epsilon)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        std::array<float,4> getArray() const {
            std::array<float,4> array={};
            memcpy(array.data(),&v,16);
            return array;
        }
        void print() const {
            const auto array=reinterpret_cast<const float*>(&v);
            std::cout<<array[0]<<" "<<array[1]<<" "<<array[2]<<" "<<array[3]<<"\n";
        }

        __m128 v;

        friend std::ostream& operator<<(std::ostream& os,const Vector4f& vector);
    };

    inline std::ostream& operator<<(std::ostream& os,const Vector4f& vector) {
        const auto array=reinterpret_cast<const float*>(&vector.v);
        os<<array[0]<<" "<<array[1]<<" "<<array[2]<<" "<<array[3];
        return os;
    }
}