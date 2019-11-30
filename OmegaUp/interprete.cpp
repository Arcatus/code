#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct data{
	int valor;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string reg, opc, original;	
	unordered_map< string, data* > tabla_variables;

	int linea = 1;

	while( cin >> opc >> reg )
	{
		if ( opc[0] == 'V' ) {
			if ( tabla_variables.count( reg ) == 1 ) {
				cout << "ERROR L" << linea << '\n';
			} else {
				tabla_variables[reg] = new data{ 0 };
			}
		}
		else if ( opc[0] == 'P' )
		{
			if ( tabla_variables.count( reg ) == 1 ) {
				cout << tabla_variables[reg]->valor << '\n';
			} else {
				cout << "ERROR L" << linea << '\n';
			}
		}
		else if ( opc[0] == 'R' )
		{
			cin >> original;
			if ( tabla_variables.count(original) == 0 || tabla_variables.count(reg) == 1 ) {
				cout << "ERROR L" << linea << '\n';
			} else {		
				tabla_variables[reg] = tabla_variables[original];
			}
		}
		else 
		{
			if ( tabla_variables.count( reg ) == 1 ) {
				tabla_variables[reg]->valor+=1;
			} else {
				cout << "ERROR L" << linea << '\n';
			}
		}
		linea += 1;
	}
}