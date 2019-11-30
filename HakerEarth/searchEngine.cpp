#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct node{
	bool isLeaf;
	int posibility;
	unordered_map<char,node*> map;
};

void insert(node* root, const char *s, int rank) {
	node* actual = root;
	for(int i=0; s[i]; ++i) {
		if ( actual->map.find(s[i]) == actual->map.end( ) ) {
			actual->map[s[i]] = new node{false, -1};
		}
		actual->posibility = max(actual->posibility, rank);
		actual = actual->map[s[i]];
	}
	actual->isLeaf = true;
}

int search(node* root, const char* s) {
	
	if( root == nullptr ) return false;
	
	node* actual = root;
	int rank=-1;
	for (int i=0; s[i]; ++i) {
		if ( actual->map[s[i]] == nullptr ) {
			return -1;
		}
		actual = actual->map[s[i]];
		rank = actual->posibility;
	}
	return rank;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	

	int n, q, r;

	cin >> n >> q;

	node* root = new node{false, -1};

	char palabra[1000000+1];

	while ( n-- ) {
		cin >> palabra >> r;
		insert(root, palabra, r);
	}

	while( q-- ) {
		cin >> palabra;
		int ans = search(root, palabra);
		cout << ans << '\n';
	}
}