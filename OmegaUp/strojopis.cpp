#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <string>

using namespace std;
int arr[8];
int main()
{	
	string buffer;

	cin >> buffer;	

	for (int i = 0; i < buffer.length(); ++i)
	{
		if ( buffer[i] == '1' || buffer[i]== 'Q' || buffer[i]== 'A'|| buffer[i]== 'Z' )
		{
			arr[0]++;
		}
		else if ( buffer[i] == '2' || buffer[i]== 'W' || buffer[i]== 'S'|| buffer[i]== 'X')
		{
			arr[1]++;
		}
		else if ( buffer[i] == '3' || buffer[i]== 'E' || buffer[i]== 'D'|| buffer[i]== 'C')
		{
			arr[2]++;
		}
		else if( buffer[i] == '4' || buffer[i]== 'R' || buffer[i]== 'F'|| buffer[i]== 'V' ||
				 buffer[i] == '5' || buffer[i]== 'T' || buffer[i]== 'G'|| buffer[i]== 'B')
		{
			arr[3]++;
		}
		else if ( buffer[i] == '6' || buffer[i]== 'Y' || buffer[i]== 'H'|| buffer[i]== 'N' ||
				  buffer[i] == '7' || buffer[i]== 'U' || buffer[i]== 'J'|| buffer[i]== 'M')
		{
			arr[4]++;
		}
		else if ( buffer[i] == '8' || buffer[i]== 'I' || buffer[i]== 'K'|| buffer[i]== ',')
		{
			arr[5]++;
		}
		else if( buffer[i] == '9' || buffer[i]== 'O' || buffer[i]== 'L'|| buffer[i]== '.' )
		{
			arr[6]++;
		}
		else if( buffer[i] == '0' || buffer[i]== 'P' || buffer[i]== ';'|| buffer[i]== '/' ||
				 buffer[i] == '-' || buffer[i]== '[' || buffer[i]== '\'' || buffer[i]== '=' || buffer[i]== ']' )
		{
			arr[7]++;
		}
		else 
		{
			return -1;
		}
	}

	for (int i =0; i < 8; ++i)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}