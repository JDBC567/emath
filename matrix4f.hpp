#pragma once

#include<immintrin.h>
#include<array>
#include<iostream>

#include "vector4f.hpp"
#include"vector3f.hpp"

namespace emath {
    ///Column major matrix
    class Matrix4f {
    public:
        Matrix4f()
        {
            v0=_mm_set_ps(0.0f,0.0f,0.0f,1.0f);
            v1=_mm_set_ps(0.0f,0.0f,1.0f,0.0f);
            v2=_mm_set_ps(0.0f,1.0f,0.0f,0.0f);
            v3=_mm_set_ps(1.0f,0.0f,0.0f,0.0f);
        }
        explicit Matrix4f(const float x) {
            v0=_mm_set1_ps(x);
            v1=_mm_set1_ps(x);
            v2=_mm_set1_ps(x);
            v3=_mm_set1_ps(x);
        }
        explicit Matrix4f(const std::array<std::array<float,4>,4>& array) {
            v0=_mm_set_ps(array[0][0],array[0][1],array[0][2],array[0][3]);
            v1=_mm_set_ps(array[1][0],array[1][1],array[1][2],array[1][3]);
            v2=_mm_set_ps(array[2][0],array[2][1],array[2][2],array[2][3]);
            v3=_mm_set_ps(array[3][0],array[3][1],array[3][2],array[3][3]);
        }
        explicit Matrix4f(const std::array<float,16>& array) {
            v0=_mm_set_ps(array[0],array[1],array[2],array[3]);
            v1=_mm_set_ps(array[4],array[5],array[6],array[7]);
            v2=_mm_set_ps(array[8],array[9],array[10],array[11]);
            v3=_mm_set_ps(array[12],array[13],array[14],array[15]);
        }
        explicit Matrix4f(const std::array<Vector4f,4>& array) {
            v0=array[0].v;
            v1=array[1].v;
            v2=array[2].v;
            v3=array[3].v;
        }
        Matrix4f(const Vector4f& c1,const Vector4f& c2,const Vector4f& c3,const Vector4f& c4) {
            v0=c1.v;
            v1=c2.v;
            v2=c3.v;
            v3=c4.v;
        }
        explicit Matrix4f(const std::array<__m128,4>& array) {
            v0=array[0];
            v1=array[1];
            v2=array[2];
            v3=array[3];
        }
        Matrix4f(const __m128& c1,const __m128& c2,const __m128& c3,const __m128& c4) {
            v0=c1;
            v1=c2;
            v2=c3;
            v3=c4;
        }

        void setM00(const float m00)  {
            reinterpret_cast<float*>(&v0)[0]=m00;
        }
        void setM01(const float m01)  {
            reinterpret_cast<float*>(&v0)[1]=m01;
        }
        void setM02(const float m02)  {
            reinterpret_cast<float*>(&v0)[2]=m02;
        }
        void setM03(const float m03)  {
            reinterpret_cast<float*>(&v0)[3]=m03;
        }
        void setM10(const float m10)  {
            reinterpret_cast<float*>(&v1)[0]=m10;
        }
        void setM11(const float m11)  {
            reinterpret_cast<float*>(&v1)[1]=m11;
        }
        void setM12(const float m12)  {
            reinterpret_cast<float*>(&v1)[2]=m12;
        }
        void setM13(const float m13)  {
            reinterpret_cast<float*>(&v1)[3]=m13;
        }
        void setM20(const float m20)  {
            reinterpret_cast<float*>(&v2)[0]=m20;
        }
        void setM21(const float m21)  {
            reinterpret_cast<float*>(&v2)[1]=m21;
        }
        void setM22(const float m22)  {
            reinterpret_cast<float*>(&v2)[2]=m22;
        }
        void setM23(const float m23)  {
            reinterpret_cast<float*>(&v2)[3]=m23;
        }
        void setM30(const float m30)  {
            reinterpret_cast<float*>(&v3)[0]=m30;
        }
        void setM31(const float m31)  {
            reinterpret_cast<float*>(&v3)[1]=m31;
        }
        void setM32(const float m32)  {
            reinterpret_cast<float*>(&v3)[2]=m32;
        }
        void setM33(const float m33)  {
            reinterpret_cast<float*>(&v3)[3]=m33;
        }

        float getM00() const {
            return _mm_cvtss_f32(v0);
        }
        float getM01() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v0,v0,_MM_SHUFFLE(3,2,1,1)));
        }
        float getM02() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v0,v0,_MM_SHUFFLE(3,2,1,2)));
        }
        float getM03() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v0,v0,_MM_SHUFFLE(3,2,1,3)));
        }
        float getM10() const {
            return _mm_cvtss_f32(v1);
        }
        float getM11() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v1,v1,_MM_SHUFFLE(3,2,1,1)));
        }
        float getM12() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v1,v1,_MM_SHUFFLE(3,2,1,2)));
        }
        float getM13() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v1,v1,_MM_SHUFFLE(3,2,1,3)));
        }
        float getM20() const {
            return _mm_cvtss_f32(v2);
        }
        float getM21() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v2,v2,_MM_SHUFFLE(3,2,1,1)));
        }
        float getM22() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v2,v2,_MM_SHUFFLE(3,2,1,2)));
        }
        float getM23() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v2,v2,_MM_SHUFFLE(3,2,1,3)));
        }
        float getM30() const {
            return _mm_cvtss_f32(v3);
        }
        float getM31() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v3,v3,_MM_SHUFFLE(3,2,1,1)));
        }
        float getM32() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v3,v3,_MM_SHUFFLE(3,2,1,2)));
        }
        float getM33() const {
            return _mm_cvtss_f32(_mm_shuffle_ps(v3,v3,_MM_SHUFFLE(3,2,1,3)));
        }

        Matrix4f operator+(const Matrix4f& rhs) const {
            const auto add1=_mm_add_ps(v0,rhs.v0);
            const auto add2=_mm_add_ps(v1,rhs.v1);
            const auto add3=_mm_add_ps(v2,rhs.v2);
            const auto add4=_mm_add_ps(v3,rhs.v3);
            return Matrix4f(add1,add2,add3,add4);
        }
        void operator+=(const Matrix4f& rhs) {
            v0=_mm_add_ps(v0,rhs.v0);
            v1=_mm_add_ps(v1,rhs.v1);
            v2=_mm_add_ps(v2,rhs.v2);
            v3=_mm_add_ps(v3,rhs.v3);
        }
        Matrix4f operator-(const Matrix4f& rhs) const {
            const auto sub1=_mm_sub_ps(v0,rhs.v0);
            const auto sub2=_mm_sub_ps(v1,rhs.v1);
            const auto sub3=_mm_sub_ps(v2,rhs.v2);
            const auto sub4=_mm_sub_ps(v3,rhs.v3);
            return Matrix4f(sub1,sub2,sub3,sub4);
        }
        void operator-=(const Matrix4f& rhs) {
            v0=_mm_sub_ps(v0,rhs.v0);
            v1=_mm_sub_ps(v1,rhs.v1);
            v2=_mm_sub_ps(v2,rhs.v2);
            v3=_mm_sub_ps(v3,rhs.v3);
        }
        Matrix4f operator*(const Matrix4f& rhs) const {
            const auto rhsm00=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm01=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm02=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm03=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(3,3,3,3));
            const auto rhsm10=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm11=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm12=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm13=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(3,3,3,3));
            const auto rhsm20=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm21=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm22=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm23=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(3,3,3,3));
            const auto rhsm30=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm31=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm32=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm33=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(3,3,3,3));

            const auto mul00=_mm_mul_ps(v0,rhsm00);
            const auto mul01=_mm_mul_ps(v0,rhsm10);
            const auto mul02=_mm_mul_ps(v0,rhsm20);
            const auto mul03=_mm_mul_ps(v0,rhsm30);
            const auto mul10=_mm_mul_ps(v1,rhsm01);
            const auto mul11=_mm_mul_ps(v1,rhsm11);
            const auto mul12=_mm_mul_ps(v1,rhsm21);
            const auto mul13=_mm_mul_ps(v1,rhsm31);
            const auto mul20=_mm_mul_ps(v2,rhsm02);
            const auto mul21=_mm_mul_ps(v2,rhsm12);
            const auto mul22=_mm_mul_ps(v2,rhsm22);
            const auto mul23=_mm_mul_ps(v2,rhsm32);
            const auto mul30=_mm_mul_ps(v3,rhsm03);
            const auto mul31=_mm_mul_ps(v3,rhsm13);
            const auto mul32=_mm_mul_ps(v3,rhsm23);
            const auto mul33=_mm_mul_ps(v3,rhsm33);

            const auto add00_10=_mm_add_ps(mul00,mul10);
            const auto add20_30=_mm_add_ps(mul20,mul30);
            const auto add01_11=_mm_add_ps(mul01,mul11);
            const auto add21_31=_mm_add_ps(mul21,mul31);
            const auto add02_12=_mm_add_ps(mul02,mul12);
            const auto add22_32=_mm_add_ps(mul22,mul32);
            const auto add03_13=_mm_add_ps(mul03,mul13);
            const auto add23_33=_mm_add_ps(mul23,mul33);

            const auto res1=_mm_add_ps(add00_10,add20_30);
            const auto res2=_mm_add_ps(add01_11,add21_31);
            const auto res3=_mm_add_ps(add02_12,add22_32);
            const auto res4=_mm_add_ps(add03_13,add23_33);

            return Matrix4f(res1,res2,res3,res4);
        }
        Vector4f operator*(const Vector4f& rhs) const
        {
            const auto rhsx=_mm_shuffle_ps(rhs.v,rhs.v,_MM_SHUFFLE(0,0,0,0));
            const auto rhsy=_mm_shuffle_ps(rhs.v,rhs.v,_MM_SHUFFLE(1,1,1,1));
            const auto rhsz=_mm_shuffle_ps(rhs.v,rhs.v,_MM_SHUFFLE(2,2,2,2));
            const auto rhsw=_mm_shuffle_ps(rhs.v,rhs.v,_MM_SHUFFLE(3,3,3,3));

            const auto mul0=_mm_mul_ps(v0,rhsx);
            const auto mul1=_mm_mul_ps(v1,rhsy);
            const auto mul2=_mm_mul_ps(v2,rhsz);
            const auto mul3=_mm_mul_ps(v3,rhsw);

            const auto add0=_mm_add_ps(mul0,mul1);
            const auto add1=_mm_add_ps(mul2,mul3);

            return Vector4f(_mm_add_ps(add0,add1));
        }
        Matrix4f operator*(const float rhs) const {
            const auto rhsv=_mm_set1_ps(rhs);
            return Matrix4f(
                _mm_mul_ps(v0,rhsv),
                _mm_mul_ps(v1,rhsv),
                _mm_mul_ps(v2,rhsv),
                _mm_mul_ps(v3,rhsv)
            );
        }
        void operator*=(const Matrix4f& rhs)
        {
            const auto rhsm00=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm01=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm02=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm03=_mm_shuffle_ps(rhs.v0,rhs.v0,_MM_SHUFFLE(3,3,3,3));
            const auto rhsm10=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm11=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm12=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm13=_mm_shuffle_ps(rhs.v1,rhs.v1,_MM_SHUFFLE(3,3,3,3));
            const auto rhsm20=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm21=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm22=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm23=_mm_shuffle_ps(rhs.v2,rhs.v2,_MM_SHUFFLE(3,3,3,3));
            const auto rhsm30=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(0,0,0,0));
            const auto rhsm31=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(1,1,1,1));
            const auto rhsm32=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(2,2,2,2));
            const auto rhsm33=_mm_shuffle_ps(rhs.v3,rhs.v3,_MM_SHUFFLE(3,3,3,3));

            const auto mul00=_mm_mul_ps(v0,rhsm00);
            const auto mul01=_mm_mul_ps(v0,rhsm10);
            const auto mul02=_mm_mul_ps(v0,rhsm20);
            const auto mul03=_mm_mul_ps(v0,rhsm30);
            const auto mul10=_mm_mul_ps(v1,rhsm01);
            const auto mul11=_mm_mul_ps(v1,rhsm11);
            const auto mul12=_mm_mul_ps(v1,rhsm21);
            const auto mul13=_mm_mul_ps(v1,rhsm31);
            const auto mul20=_mm_mul_ps(v2,rhsm02);
            const auto mul21=_mm_mul_ps(v2,rhsm12);
            const auto mul22=_mm_mul_ps(v2,rhsm22);
            const auto mul23=_mm_mul_ps(v2,rhsm32);
            const auto mul30=_mm_mul_ps(v3,rhsm03);
            const auto mul31=_mm_mul_ps(v3,rhsm13);
            const auto mul32=_mm_mul_ps(v3,rhsm23);
            const auto mul33=_mm_mul_ps(v3,rhsm33);

            const auto add00_10=_mm_add_ps(mul00,mul10);
            const auto add20_30=_mm_add_ps(mul20,mul30);
            const auto add01_11=_mm_add_ps(mul01,mul11);
            const auto add21_31=_mm_add_ps(mul21,mul31);
            const auto add02_12=_mm_add_ps(mul02,mul12);
            const auto add22_32=_mm_add_ps(mul22,mul32);
            const auto add03_13=_mm_add_ps(mul03,mul13);
            const auto add23_33=_mm_add_ps(mul23,mul33);

            v0=_mm_add_ps(add00_10,add20_30);
            v1=_mm_add_ps(add01_11,add21_31);
            v2=_mm_add_ps(add02_12,add22_32);
            v3=_mm_add_ps(add03_13,add23_33);
        }
        void operator*=(const float rhs)
        {
            const auto rhsv=_mm_set1_ps(rhs);
            v0=_mm_mul_ps(v0,rhsv);
            v1=_mm_mul_ps(v1,rhsv);
            v2=_mm_mul_ps(v2,rhsv);
            v3=_mm_mul_ps(v3,rhsv);
        }

        void translation(const Vector3f& translation_vector) {
            v3=translation_vector.v;
            setM33(1.0f);
        }

        void rotationXYZ(const Vector3f& rotation_vector,const bool radians=false)
        {
            const auto radian_const=_mm_set1_ps(0.0174533);
            auto rotv=rotation_vector.v;
            if(!radians)
            {
                rotv=_mm_mul_ps(rotv,radian_const);
            }
            const auto cos=_mm_cos_ps(rotv);
            const auto sin=_mm_sin_ps(rotv);

            float cos_arr[4]={0.0f};
            float sin_arr[4]={0.0f};
            _mm_storeu_ps(&cos_arr[0],cos);
            _mm_storeu_ps(&sin_arr[0],sin);

            const float nm0=-sin_arr[0]*-sin_arr[1];
            const float nm1=cos_arr[0]*-sin_arr[1];

            float m0[4]={1.0f,0.0f,0.0f,0.0f};
            float m1[4]={0.0f,1.0f,0.0f,0.0f};
            float m2[4]={0.0f,0.0f,1.0f,0.0f};

            m2[0]=sin_arr[1];
            m2[1]=-sin_arr[0]*cos_arr[1];
            m2[2]=cos_arr[0]*cos_arr[1];
            m0[0]=cos_arr[1]*cos_arr[2];
            m0[1]=nm0*cos_arr[2]+cos_arr[0]*sin_arr[2];
            m0[2]=nm1*cos_arr[2]+sin_arr[0]*sin_arr[2];
            m1[0]=cos_arr[1]*-sin_arr[2];
            m1[1]=nm0*-sin_arr[2]+cos_arr[0]*cos_arr[2];
            m1[2]=nm1*-sin_arr[2]+sin_arr[0]*cos_arr[2];

            v0=_mm_loadu_ps(m0);
            v1=_mm_loadu_ps(m1);
            v2=_mm_loadu_ps(m2);
        }

        void rotationXYZ(const float x,const float y,const float z,const bool radians=false)
        {
            const auto radian_const=_mm_set1_ps(0.0174533);
            auto rotv=_mm_set_ps(0.0f,z,y,x);
            if(!radians)
            {
                rotv=_mm_mul_ps(rotv,radian_const);
            }
            const auto cos=_mm_cos_ps(rotv);
            const auto sin=_mm_sin_ps(rotv);

            float cos_arr[4]={0.0f};
            float sin_arr[4]={0.0f};
            _mm_storeu_ps(&cos_arr[0],cos);
            _mm_storeu_ps(&sin_arr[0],sin);

            const float nm0=-sin_arr[0]*-sin_arr[1];
            const float nm1=cos_arr[0]*-sin_arr[1];

            float m0[4]={1.0f,0.0f,0.0f,0.0f};
            float m1[4]={0.0f,1.0f,0.0f,0.0f};
            float m2[4]={0.0f,0.0f,1.0f,0.0f};

            m2[0]=sin_arr[1];
            m2[1]=-sin_arr[0]*cos_arr[1];
            m2[2]=cos_arr[0]*cos_arr[1];
            m0[0]=cos_arr[1]*cos_arr[2];
            m0[1]=nm0*cos_arr[2]+cos_arr[0]*sin_arr[2];
            m0[2]=nm1*cos_arr[2]+sin_arr[0]*sin_arr[2];
            m1[0]=cos_arr[1]*-sin_arr[2];
            m1[1]=nm0*-sin_arr[2]+cos_arr[0]*cos_arr[2];
            m1[2]=nm1*-sin_arr[2]+sin_arr[0]*cos_arr[2];

            v0=_mm_loadu_ps(m0);
            v1=_mm_loadu_ps(m1);
            v2=_mm_loadu_ps(m2);
        }

        void scaleXYZ(const Vector3f& scale_vector)
        {
            const auto scale_x=_mm_shuffle_ps(scale_vector.v,scale_vector.v,_MM_SHUFFLE(0,0,0,0));
            const auto scale_y=_mm_shuffle_ps(scale_vector.v,scale_vector.v,_MM_SHUFFLE(1,1,1,1));
            const auto scale_z=_mm_shuffle_ps(scale_vector.v,scale_vector.v,_MM_SHUFFLE(2,2,2,2));

            v0=_mm_mul_ps(v0,scale_x);
            v1=_mm_mul_ps(v1,scale_y);
            v2=_mm_mul_ps(v2,scale_z);
        }

        void scaleXYZ(const float x,const float y,const float z)
        {
            const auto scale_x=_mm_set1_ps(x);
            const auto scale_y=_mm_set1_ps(y);
            const auto scale_z=_mm_set1_ps(z);

            v0=_mm_mul_ps(v0,scale_x);
            v1=_mm_mul_ps(v1,scale_y);
            v2=_mm_mul_ps(v2,scale_z);
        }

        void transformation(const Vector3f& translation_vector,const Vector3f& rotation_vector,const Vector3f& scale_vector,const bool radians=false)
        {
            translation(translation_vector);
            rotationXYZ(rotation_vector,radians);
            scaleXYZ(scale_vector);
        }

        void print() const {
            const auto array1=reinterpret_cast<const float*>(&v0);
            const auto array2=reinterpret_cast<const float*>(&v1);
            const auto array3=reinterpret_cast<const float*>(&v2);
            const auto array4=reinterpret_cast<const float*>(&v3);
            for(int i=0;i<4;i++) {
                std::cout<<array1[i]<<" "<<array2[i]<<" "<<array3[i]<<" "<<array4[i]<<"\n";
            }
        }

        __m128 v0;
        __m128 v1;
        __m128 v2;
        __m128 v3;
    };
}
