#include <iostream>

using namespace std;

int contador, m, b;
int generated;

char array[32+1];

void genera(int k)
{	
	if ( k == m ) {
		generated+=1;
			for(int i=0;i<m;++i) {
				//cout << array[i] << ' ';
			}
			//cout << '\n';w
		if (b == 0) {
			contador+=1;
		} 
		return;
	}

	if ( b > 0 && array[k-1] != '1') {
		b-=1;
		array[k] = '1';
		genera(k+1);
		b+=1;
	}
	array[k] = '0';
	genera(k+1);	
}

int main()
{
	cin >> m >> b;	

	genera(0);

	cout << generated << '\n';

	cout << contador << '\n';

	return 0;
}