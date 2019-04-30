#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	

	string buffer;
	
	while(getline(cin,buffer))
	{	
		stringstream linea(buffer);
		
		while(linea >> buffer)
		{
			cout << string(buffer.rbegin(), buffer.rend()) << ' ';
		}
		cout << '\n';		
	}
	return 0;
}