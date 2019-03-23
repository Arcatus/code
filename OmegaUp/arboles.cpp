//#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <string>
//#include <algorithm>
//#include <string>
#include <vector>

struct node
{	
	int data = 0;
	node *left = nullptr;
	node *right = nullptr;

};

class btree
{
public:
	void start(const int& x);
	void addNode(const int& x);
	void initPreorder(){preOrden(root);}
	void print();
private:
	node *root;
	std::vector<int> v;
	void preOrden(node* t);
};

void btree::print()
{
	printf("%d\n",(int)v.size());
	for (auto& i : v)
	{
		printf("%d ",i);
	}
}

void btree::preOrden( node* t )
{
	if ( t != nullptr )
	if ( t->left == nullptr && t->right == nullptr ){
		v.push_back( t->data );
	}
	else {
		preOrden( t->left );
		preOrden( t->right );
	}
}

void btree::start(const int& x)
{
	root = (node*) malloc (sizeof(node));
	root->data = x;
}

void btree::addNode(const int& x)
{
	node *tmp = (node*) malloc (sizeof(node));

	tmp->data = x;

	node* posicionador = root;

	bool shouldClose = false;

	while( ! shouldClose )
	if ( tmp->data < posicionador->data )
		if ( posicionador->left == nullptr ){
			posicionador->left = tmp;
			shouldClose = true;
		}
		else posicionador = posicionador->left;
	else
		if ( posicionador->right == nullptr ){
			posicionador->right = tmp;
			shouldClose = true;
		}
		else posicionador = posicionador->right;
}

int main()
{
	int n, t;
	scanf("%d",&n);

	btree miArbol;

	scanf("%d",&t);

	miArbol.start(t);

	for (int i = 1; i < n; ++i)
	{
		scanf("%d",&t);

		miArbol.addNode(t);
	}		

	miArbol.initPreorder();

	miArbol.print();
}