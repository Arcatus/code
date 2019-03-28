#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int row[8], TC, a, b;

struct par
{
	int columna;
	int renglon;
};

par goal[8];

bool place(int r, int c) 
{
	for (int prev = 0; prev < c; prev++)
	{
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
		return false;
	}
	return true;
}

bool verif()
{
	if ( TC > 0)
	{
		for (int i = 0; i < TC; ++i)
		{
			if ( row[ goal[i].columna ] != goal[ i ].renglon )
			{
				return false;
			}
		}
	}
	return true;
}

void backtrack(int c) 
{
	if ( c == 8 && row[b] == a )
	{
		if ( verif() )
		{
			for (int i = 0; i < 8; ++i)
			{
				printf("%d %d\n",row[i]+1,i+1);
			}
		}
	}
	
	for (int r = 0; r < 8; r++)
	{
		if ( place(r, c) ) 
		{
			row[c] = r; 
			backtrack(c + 1);
		}
	}
}
int main() 
{
	int t;

	TC = 0;

	memset(goal, -1, sizeof goal);
	memset(row,   0, sizeof row);



	if (TC == 0)
	{
		a = 0;
		b = 0;

		goal[0].renglon = a;
		goal[0].columna = b;
		
		backtrack(0);
	}
	else
	{
		for (int i = 0; i < TC; ++i)
		{
			scanf("%d %d", &a, &b);
			a--; b--;
			goal[ i ].columna = b;
			goal[ i ].renglon = a;
		}

		backtrack(0);

		printf("0\n");
	}
}