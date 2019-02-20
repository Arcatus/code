// ver 1.3

#include <cstdio>
#include <cmath>
#include <GL/glew.h>
#include <limits.h>

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
     GLfloat component1 = vector->x * vector->x;
     GLfloat component2 = vector->y * vector->y;
     GLfloat component3 = vector->z * vector->z;
     GLfloat norma = (GLfloat)sqrt( component1 + component2 + component3 );
     vector->x /= norma;
     vector->y /= norma;
     vector->z /= norma;
}

Vector3 Vector3Normalize(const Vector3& vector)
{
    Vector3 temp = vector;
    GLfloat c1 = vector.x * vector.x;
    GLfloat c2 = vector.y * vector.y;
    GLfloat c3 = vector.z * vector.z;
    GLfloat norma = (GLfloat)sqrt( c1 + c2 + c3 );
    temp.x /= norma;
    temp.y /= norma;
    temp.z /= norma;
    return temp;
}

float Vector3ScalarProduct(Vector3* v1, Vector3* v2)
{
     return ( v1->x * v2->x + v1->y * v2->y + v1->z * v2->z );
}

void Vector3CrossProduct(Vector3* v1, Vector3* v2, Vector3* result)
{
     result->x = (v1->y*v2->z) - (v1->z*v2->y);
     result->y = (v1->x*v2->z) - (v1->z*v2->x);
     result->z = (v1->x*v2->y) - (v1->y*v2->x);
}

Vector3 Vector3CrossProduct(const Vector3& v1,const Vector3& v2)
{
    Vector3 result;
    result.x = (v1.y*v2.z) - (v1.z*v2.y);
    result.y = (v1.x*v2.z) - (v1.z*v2.x);
    result.z = (v1.x*v2.y) - (v1.y*v2.x);
    return result;
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

void Matrix4x4MakeRotation(Vector3* axis, float angle, Matrix4x4* result)
{
     result->m[0][0] = cos(angle) + (axis->x * axis->x) * (1 - cos(angle)) ;
     result->m[0][1] = axis->x * axis->y * (1 - cos(angle)) - axis->z * sin(angle);
     result->m[0][2] = axis->x * axis->z * (1 - cos(angle)) + axis->y * sin(angle);
     result->m[0][3] = 0.0f;
     result->m[1][0] = axis->x * axis->y * (1 - cos(angle)) + axis->z * sin(angle);
     result->m[1][1] = cos(angle) + (axis->y* axis->y ) * (1 - cos(angle));
     result->m[1][2] = axis->y * axis->z * (1 - cos(angle)) - axis->x * sin(angle);
     result->m[1][3] = 0.0f;
     result->m[2][0] = axis->x * axis->z * (1 - cos(angle)) - axis->y * sin(angle);
     result->m[2][1] = axis->y * axis->z * (1 - cos(angle)) + axis->x * sin(angle);
     result->m[2][2] = cos(angle) + (axis->z* axis->z ) * (1 - cos(angle));
     result->m[2][3] = 0.0f;
     result->m[3][0] = 0.0f;
     result->m[3][1] = 0.0f;
     result->m[3][2] = 0.0f;
     result->m[3][3] = 1.0f;
}
void Matrix4x4MakeRotationY(float angle, Matrix4x4* result)
{
     for (int i = 0; i < 4; ++i)
     for (int j = 0; j < 4; ++j)
          result->m[i][j] = 0.0f;
     result->m[0][0] = cos(angle);
     result->m[0][2] = sin(angle);
     result->m[1][1] = 1.0f;
     result->m[2][0] = - sin(angle);
     result->m[2][2] = cos(angle);
     result->m[3][3] = 1.0f;	
}

void Matrix4x4MakeRotationZ(float angle, Matrix4x4* result)
{
    for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
        result->m[i][j] = 0.0f;

    result->m[0][0] = cos(angle);
    result->m[0][1] = - sin(angle);
    result->m[1][0] = sin(angle);
    result->m[1][1] = cos(angle);
    result->m[2][2] = 1.0f;
    result->m[3][3] = 1.0f;	
}

void Matrix4x4MakeView(Vector3* position, Vector3* target, Vector3* up, Matrix4x4* view)
{
    Vector3 f = *target - *position;
    Vector3 s = { };
    Vector3 v = { };
    Vector3CrossProduct(&f,up,&s);
    Vector3Normalize(&f); 
    f = -1 * f;
    Vector3Normalize(&s);
    Vector3CrossProduct(&s,&f,&v);
    view->m[0][0] = s.x;
    view->m[0][1] = s.y;
    view->m[0][2] = s.z;
    view->m[0][3] = - Vector3ScalarProduct(&s,position);
    view->m[1][0] = v.x;
    view->m[1][1] = v.y;
    view->m[1][2] = v.z;
    view->m[1][3] = - Vector3ScalarProduct(&v,position);
    view->m[2][0] = f.x; 
    view->m[2][1] = f.y; 
    view->m[2][2] = f.z; 
    view->m[2][3] = - Vector3ScalarProduct(&f,position);
    view->m[3][0] = 0.0f;
    view->m[3][1] = 0.0f;
    view->m[3][2] = 0.0f;
    view->m[3][3] = 1.0f;
}

void Matrix4x4MakePerspective(float fov, float aspect, float near, float far, Matrix4x4* perspective)
{
     for (int i = 0; i < 4; ++i)
     for (int j = 0; j < 4; ++j)
          perspective->m[i][j] = 0.0f;

     perspective->m[0][0] = (1/aspect) * (1/tan(fov/2));
     perspective->m[1][1] =  1/tan(fov/2);
     perspective->m[2][2] = -1.0f *  (far + near) / (far - near) ; 
     perspective->m[2][3] = -2.0f *  (far * near) / (far - near) ;
     perspective->m[3][2] = -1.0f;
}

int memFactorial[100] = { };

int factorial(int n)
{
     if ( n == 0)
          return 1;
     else if ( memFactorial[n] )
          return memFactorial[n];
     else {
          memFactorial[n] = n * factorial(n-1);
          return memFactorial[n];
	}
}

float binomial_coefficient(int k, int n)
{
     return (float) factorial(n) / (factorial(k) * factorial(n-k));
}

float bernstein_polynomial(int k, int n, float t)
{
     return (float) binomial_coefficient(k,n) * pow(t,k) * pow( 1 - t, n - k );
}

/*
int main()
{	
	Vector3 p = { 0, 3, 0}; 
    Vector3 e = { 0,-1, 0};
    Vector3 up = { 0, 0, 1};

    Vector3 f = e - p;
    Vector3Normalize(&f);
    Vector3 s;
    Vector3CrossProduct(&f,&up,&s);

    Vector3 v;
    Vector3CrossProduct(&s,&f,&v);

    printf("%.2f %.2f %.2f \n",f.x,f.y,f.z);
    printf("%.2f %.2f %.2f \n",s.x,s.y,s.z);
    printf("%.2f %.2f %.2f \n",v.x,v.y,v.z);

	return 0;
}
*/
