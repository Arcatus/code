#include<iostream>

using namespace std;

struct pedir_dato{	
	float temperatura[23];
	
}temp[100];

int main(){
	short int i;
	for( i=0;i<24;i++){
		fflush(stdin);
		cout<<"ingrese la temperatura de la hora"<<i<<":"<<endl;
		cin >> temp[i].temperatura[0];
	}
	return 0;
}