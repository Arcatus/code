#include <cstdio>
#include <cmath>

#include "math3d.h"

Vector3 operator+(const Vector3& left, const Vector3& right)
{
	return { left.x + right.x, left.y + right.y, left.z + right.z };
}

Vector3 operator-(const Vector3& left, const Vector3& right)
{
	return { left.x - right.x, left.y - right.y, left.z - right.z };
}

Vector3 operator*(float factor, const Vector3& vector)
{
	return { factor * vector.x, factor * vector.y, factor * vector.z };
}

void Vector3InitToZero(Vector3* vector)
{
	vector->x = 0.0f; vector->y = 0.0f; vector->z = 0.0f;
}

void Vector3Normalize(Vector3* vector)
{
	float component1 = vector->x * vector->x;
	float component2 = vector->y * vector->y;
	float component3 = vector->z * vector->z;
	float norma = sqrt( component1 + component2 + component3 );
	vector->x /= norma;
	vector->y /= norma;
	vector->z /= norma;
}

float Vector3ScalarProduct(Vector3* v1, Vector3* v2)
{
	return ( v1->x * v1->x + v1->y * v2->y + v1->z * v2->z );
}

void Vector3CrossProduct(Vector3* v1, Vector3* v2, Vector3* result)
{
	result->x = v1->y*v2->z - v2->z*v2->y;
	result->y = v1->x*v2->z - v1->z*v2->x;
	result->z = v1->x*v2->y - v1->y*v2->x;
}

void Matrix3x3InitToZero(Matrix3x3* matrix)
{
	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
		matrix->m[i][j] = 0.0f;
}

void Matrix3x3MakeIdentity(Matrix3x3* matrix)
{
	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
		if ( i == j )
			matrix->m[i][j] = 1.0f;
		else
			matrix->m[i][j] = 0.0f;
}
void Matrix3x3Multiplication(Matrix3x3* op1, Matrix3x3* op2, Matrix3x3* result)
{
	for( int i = 0; i < 4; ++i)
	for( int j = 0; j < 4; ++j)
		result->m[i][j] = 0.0f;
	
	for( int i = 0; i < 3; ++i)
	for( int j = 0; j < 3; ++j)
	for (int l = 0; l < 3; ++l)
		result->m[i][j] += op1->m[i][l] * op2->m[l][j];
}

void Matrix3x3MultiplicationByVector(Matrix3x3* matrix, Vector3* vect, Vector3* result)
{
	float* vf[3] = { &vect->x, &vect->y, &vect->z };
	float* vd[3] = { &result->x, &result->y, &result->z };

    for (int i = 0; i < 3; ++i) 
    for (int j = 0; j < 3; ++j)
    	*vd[i] += matrix->m[i][j] * (*vf[j]);
}

void Matrix3x3MakeRotation(Vector3* axis, float angle, Matrix3x3* result)
{
    result->m[0][0] = cos(angle) + (axis->x * axis->x) * (1 - cos(angle)) ;
    result->m[0][1] = axis->x * axis->y * (1 - cos(angle)) - axis->z * sin(angle);
    result->m[0][2] = axis->x * axis->z * (1 - cos(angle)) + axis->y * sin(angle);
    result->m[1][0] = axis->x * axis->y * (1 - cos(angle)) + axis->z * sin(angle);
    result->m[1][1] = cos(angle) + (axis->y* axis->y ) * (1 - cos(angle));
    result->m[1][2] = axis->y * axis->z * (1 - cos(angle)) - axis->x * sin(angle);
    result->m[2][0] = axis->x * axis->z * (1 - cos(angle)) - axis->y * sin(angle);
    result->m[2][1] = axis->y * axis->z * (1 - cos(angle)) + axis->x * sin(angle);
    result->m[2][2] = cos(angle) + (axis->z* axis->z ) * (1 - cos(angle));
}

void Matrix3x3MakeRotationY(float angle, Matrix3x3* result)
{
    result->m[0][0] = cos(angle);
    result->m[0][1] = 0.0f;
    result->m[0][2] = sin(angle);
    result->m[1][0] = 0.0f;
    result->m[1][1] = 1;
    result->m[1][2] = 0.0f;
    result->m[2][0] = -sin(angle);
    result->m[2][1] = 0.0f;
    result->m[2][2] = cos(angle);
}

void Matrix4x4InitToZero(Matrix4x4* matrix)
{
    for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
		matrix->m[i][j] = 0.0f;
}

void Matrix4x4MakeIdentity(Matrix4x4* matrix)
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
		if ( i == j )
			matrix->m[i][j] = 1.0f;
		else
			matrix->m[i][j] = 0.0f;
}

Matrix4x4 operator*(const Matrix4x4& op1, Matrix4x4& op2)
{
	Matrix4x4 mat;
	for( int i = 0; i < 4; ++i)
	for( int j = 0; j < 4; ++j)
		mat.m[i][j] = 0.0f;
	
	for( int i = 0; i < 4; ++i)
	for( int j = 0; j < 4; ++j)
	for (int l = 0; l < 4; ++l)
		mat.m[i][j] += op1.m[i][l] * op2.m[l][j];

    return mat;
}

void Matrix4x4MakeScaling(float scaleX, float scaleY, float scaleZ, Matrix4x4* result)
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
			result->m[i][j] = 0.0f;

	result->m[0][0] = scaleX;
	result->m[1][1] = scaleY;
	result->m[2][2] = scaleZ;
	result->m[3][3] = 1.0f;
}

void Matrix4x4MakeUniformScaling(float scale, Matrix4x4* result)
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
		if( i == j)
			result->m[i][j] = scale;
		else 
			result->m[i][j] = 0.0f;
	result->m[3][3] = 1.0f;	
}

void Matrix4x4MakeTranslation(float offsetX, float offsetY, float offsetZ, Matrix4x4* result)
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 3; ++j)
		if( i == j)
			result->m[i][j] = 1.0f;
		else 
			result->m[i][j] = 0.0f;

	result->m[0][3] = offsetX;
	result->m[1][3] = offsetY;
	result->m[2][3] = offsetZ;
	result->m[3][3] = 1.0f;	
}

/*

int main()
{
	Matrix4x4 mat1, mat2, mat3;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			mat1.m[i][j] = rand() % 10;
			mat2.m[i][j] = rand() % 10;
		}
	mat3 = mat1 * mat2;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%.0f ",mat1.m[i][j]);
		}printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%.0f ",mat2.m[i][j]);
		}printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%.0f ",mat3.m[i][j]);
		}printf("\n");
	}

	return 0;
}

*/