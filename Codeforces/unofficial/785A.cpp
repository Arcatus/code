#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	std::map<string,int> st;

	st.emplace( "Tetrahedron", 4);
	st.emplace( "Cube", 6);
	st.emplace( "Octahedron", 8);
	st.emplace( "Dodecahedron", 12);
	st.emplace( "Icosahedron", 20);

	unsigned long long res = 0;

	string ent;

	for (int i = 0; i < n; ++i) {
		cin >> ent; 
		res += st[ent];
	}

	cout<< res <<'\n';
}