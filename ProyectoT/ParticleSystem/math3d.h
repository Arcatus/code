#ifndef MATH3D_H
#define MATH3D_H

#include <cmath>

struct Vector3
{
    float x;
    float y;
    float z;
};

struct Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct Matrix3x3
{
    float m[3][3];
};

struct Matrix4x4
{
    float m[4][4];
};

Vector3 operator+(const Vector3& left, const Vector3& right);

Vector3 operator-(const Vector3& left, const Vector3& right);

Vector3 operator*(float factor, const Vector3& vector);

void Vector3InitToZero(Vector3* vector);

void Vector3Normalize(Vector3* vector);

float Vector3ScalarProduct(Vector3* v1, Vector3* v2);

void Vector3CrossProduct(Vector3* v1, Vector3* v2, Vector3* result);

void Matrix3x3InitToZero(Matrix3x3* matrix);

void Matrix3x3MakeIdentity(Matrix3x3* matrix);

void Matrix3x3Multiplication(Matrix3x3* op1, Matrix3x3* op2, Matrix3x3* result);

void Matrix3x3MultiplicationByVector(Matrix3x3* matrix, Vector3* vector, Vector3* result);

void Matrix3x3MakeRotation(Vector3* axis, float angle, Matrix3x3* result);

void Matrix4x4InitToZero(Matrix4x4* matrix);

void Matrix4x4MakeIdentity(Matrix4x4* matrix);

void Matrix4x4Multiplication(Matrix4x4* op1, Matrix4x4* op2, Matrix4x4* result);

void Matrix4x4MultiplicationByVector(Matrix4x4* matrix, Vector4* vector, Vector4* result);

Matrix4x4 operator*(const Matrix4x4& op1, Matrix4x4& op2);

void Matrix4x4MakeScaling(float scaleX, float scaleY, float scaleZ, Matrix4x4* result);

void Matrix4x4MakeTranslation(float offsetX, float offsetY, float offsetZ, Matrix4x4* result);

void Matrix4x4MakeRotation(Vector3* axis, float angle, Matrix4x4* result);

void Matrix4x4MakeView(Vector3* position, Vector3* target, Vector3* up, Matrix4x4* view);

void Matrix4x4MakePerspective(float fov, float aspect, float near,
    float far, Matrix4x4* perspective);

void Matrix4x4MakePerspectiveSimple(float left, float right, float bottom,
    float top, float near, float far, Matrix4x4* perspective);

void Matrix4x4MakeOrthographic(float left, float right, float bottom, float top,
    float near, float far, Matrix4x4* ortho);

int factorial(int n);

float binomial_coefficient(int i, int n);

float bernstein_polynomial(int i, int n, float u);

#endif // MATH3D_H
