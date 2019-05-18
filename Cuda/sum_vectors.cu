#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

#define N 10

__global__ void  addKernel(int *a, int *b, int *c)
{
	int tid = blockIdx.x;

	if ( tid < N )
	{
		c[tid] = a[tid] + b[tid];
	}
}

int main()
{
	int *a, *b, *c;

	a = (int*) malloc(sizeof(int) * N);
	b = (int*) malloc(sizeof(int) * N);
	c = (int*) malloc(sizeof(int) * N);

	int *dev_a, *dev_b, *dev_c;

	
	if ( cudaErrorMemoryAllocation == cudaMalloc( (void**)&dev_a, N * sizeof(int) ) )
	{
		fprintf(stderr, "Error allocating memory\n");
		return -1;
	}
	if ( cudaErrorMemoryAllocation == cudaMalloc( (void**)&dev_b, N * sizeof(int) ) )
	{
		fprintf(stderr, "Error allocating memory\n");
		return -1;
	}
	if ( cudaErrorMemoryAllocation == cudaMalloc( (void**)&dev_c, N * sizeof(int) ) )
	{
		fprintf(stderr, "Error allocating memory\n");
		return -1;
	}
	

	for (int i=0; i < N; ++i)
	{
		a[i]= i;
		b[i]= i;
	}

	int retA = cudaMemcpy( dev_a, a, N*sizeof(int), cudaMemcpyDefault );

	if (retA == cudaSuccess) {
		printf("A is Ok!\n");
	} 
	else if ( retA == cudaErrorInvalidValue )
	{
		fprintf(stderr, "Invalid value\n");
		return -1;
	}
	else if ( retA == cudaErrorInvalidDevicePointer )
	{
		fprintf(stderr, "Invalid pointer\n");
		return -1;
	}
	else
	{
		fprintf(stderr, "Invalid direction\n");
		printf("Error type %x\n",retA );
		return -1;
	}


	if ( cudaMemcpy( dev_b, b, N*sizeof(int), cudaMemcpyHostToDevice ) != cudaSuccess )
	{
		fprintf(stderr, "Something goes wrong in dev_b\n");
	}

	addKernel<<<N,1>>>(dev_a, dev_b, dev_c);

	cudaMemcpy(c, dev_c, N*sizeof(int), cudaMemcpyDeviceToHost );

	for (int i=0;i<N;++i)
	{
		printf("%d + %d = %d\n",a[i], b[i], c[i]);
	}
	printf("\n");

	cudaFree( dev_a );
	cudaFree( dev_b );
	cudaFree( dev_c );

	return 0;
}