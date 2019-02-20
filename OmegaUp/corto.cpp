#include <cmath>
#include <cstdio>
#include <algorithm>

int main()
{
	float 	x1, y1,
			x2, y2,
			x3, y3,
			x4, y4;

	scanf("%f %f %f %f ", &x1,&y1,&x2,&y2);
	scanf("%f %f %f %f ", &x3,&y3,&x4,&y4);

	float arr[4];

	arr[0] = hypot(x1 - x2 ,y1 - y2);

	arr[1] = hypot(x2 - x3 ,y2 - y3);

	arr[2] = hypot(x3 - x4 ,y3 - y4);

	arr[3] = hypot(x4 - x1 ,y4 - y1);

	std::sort(arr,arr+4);

	printf("%f\n",arr[0]);

	return 0;
}