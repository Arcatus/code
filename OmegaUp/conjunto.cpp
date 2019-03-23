//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>

//#define _DEBUG__ 0

class conjunto
{
private:
	int max;
	int n;
	bool *a;
public:
	void crea(const int& max_t);
	void inserta(const int& val);
	void extrae(const int& val);
	void destroy();
	int getMax(){return max;}
	int getN(){return n;}
};

void conjunto::destroy()
{	
	free(a);
	a = nullptr;
	max = 0;
	n = 0;
}

void conjunto::crea(const int& max_t )
{
	a = (bool*) malloc (max_t*sizeof(bool));

	std::fill(a,a+max_t,false);

	if ( a != nullptr )
		max = max_t;
	else{
		max = 0;
	}
	n = 0;
}

void conjunto::inserta(const int& val)
{
	if (a[val] == false)
	{
		a[val] = true;
		n++;
	}
}

void conjunto::extrae(const int& val)
{
	if (a[val]==true)
	{
		a[val] = false;
		n--;
	}
}

int main()
{
	int n, m;
	scanf("%d %d",&n,&m);

	conjunto s;

	s.crea(n);

	char opc; int pos;

	for (int i = 0; i < m; ++i)
	{
		getchar();

		opc = getchar();

		#ifdef _DEBUG__
		printf("opc:%c\n",opc);
		#endif

		if ( opc != 'C' )
		{
			scanf("%d",&pos); 
		}

		if ( opc == 'I' )
		{
			s.inserta(pos);
		}
		else if ( opc == 'E' )
		{
			s.extrae(pos);
		}
		else if ( opc == 'C' )
		{
			printf ("%d\n", s.getN());
		}
	}

	s.destroy();
}