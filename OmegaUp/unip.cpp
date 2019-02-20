#include <stdio.h>
#include <unordered_map>

struct nodo{
	long val;
	nodo* ant;
	nodo* sig;
};

int main()
{
	int n;

	scanf("%d",&n);

	if (n == 0)
	{
		return 0;
	}

	std::unordered_map<long,int*> l1, l2;

	int* a[100000];

	nodo* inicio = new nodo();

	scanf("%ld", &inicio->val );
	inicio->ant = nullptr;
	inicio->sig = nullptr;

	int numbers = 0;

	l1.insert(std::make_pair(inicio->val),a[numbers++]);

	for (int i = 1; i < n; ++i)
	{
		long 
		
	}

	return 0;
}