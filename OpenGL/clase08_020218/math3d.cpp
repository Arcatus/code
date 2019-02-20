/* @Autor Ramirez Martinez Carlos Alberto Ing. Computacio'n*/
/* @UEA Gra'ficas por computadora*/

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

void Vector3InitToZero(Vector3& vector)
{
	vector.x = 0.0f; vector.y = 0.0f; vector.z = 0.0f;
}

void Vector3Normalize(Vector3& vector)
{
	float component1 = vector.x * vector.x;
	float component2 = vector.y * vector.y;
	float component3 = vector.z * vector.z;
	float norma = sqrt( component1 + component2 + component3 );
	vector.x /= norma;
	vector.y /= norma;
	vector.z /= norma;
}

float Vector3ScalarProduct(Vector3& v1, Vector3& v2)
{
	return { v1.x * v1.x + v1.y * v2.y + v1.z * v2.z };
}

void Matrix3x3InitToZero(Matrix3x3& matrix)
{
	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
		matrix.m[i][j] = 0.0f;
}

void Matrix3x3MakeIdentity(Matrix3x3& matrix)
{
	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
		if ( i == j )
			matrix.m[i][j] = 1.0f;
		else
			matrix.m[i][j] = 0.0f;
}
void Matrix3x3Multiplication(Matrix3x3& op1, Matrix3x3& op2, Matrix3x3& result)
{
	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
		result.m[i][j] = op1.m[i][j] * op2.m[i][j];
}