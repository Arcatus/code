#include <iostream>
#include <unordered_map>
using namespace std;

struct node{
	bool isLeaf;
	unordered_map<char,node*> map;
};

void insert(node*& root, const char *s) {
	node* actual = root;
	for(int i=0; s[i]; ++i) {
		if ( actual->map.find(s[i]) == actual->map.end() ) {
			actual->map[s[i]] = new node{false};
		}
		actual = actual->map[s[i]];
	}
	actual->isLeaf = true;
}

bool search(node* root, const char* s) {
	
	if( root == nullptr ) return false;
	
	node* actual = root;
	for (int i=0; s[i]; ++i) {
		if ( actual->map[s[i]] == nullptr ) {
			return false;
		}
		actual = actual->map[s[i]];
	}
	return actual->isLeaf;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	

	node* root = new node{false};

	const char palabra[] = { "hola" };

	insert(root, palabra);

	if ( search(root, palabra) ) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}