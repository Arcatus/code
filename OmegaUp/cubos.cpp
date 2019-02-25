#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
#include <stack>

int main()
{
	int n;
	scanf("%d",&n);

	int cubo;	

	scanf("%d",&cubo);

	int piso = 1;

	std::stack<int> mipila;

	mipila.emplace(cubo);

	for(int i = 1; i < n; ++i)
	{
		scanf("%d",&cubo);

		int cima = mipila.top();

		if (cima == cubo)
		{
			mipila.pop();
			mipila.emplace(cubo + cubo);
			while( mipila.size() >= 2 )
			{
				int a = mipila.top();
				mipila.pop();
				int b = mipila.top();
				mipila.pop();

				if( a == b )
				{
					mipila.emplace(a+a);
					piso--;
				}
				else
				{
					mipila.emplace(b);
					mipila.emplace(a);
					break;
				}
			}
		}
		else
		{
			mipila.emplace(cubo);
			piso++;
		}
	}

	printf("%d\n",piso);

	while( ! mipila.empty() )
	{
		std::cout << mipila.top()<<'\n';
		mipila.pop();
	}
}