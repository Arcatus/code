#include <iostream>
#include <stack>

using namespace std;

struct node{
	int valor;
	node* izq = nullptr;
	node* der = nullptr;
};

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}

	node raiz;
	raiz.valor = arr[n-1];

	for ( int i=n-2; i>=0; i-- ) {
		node* actual = &raiz;
		do {
			if ( arr[i] < actual->valor ) {
				if ( actual->izq == nullptr ) {
					actual->izq = new node;
					actual->izq->valor = arr[i];
					break;
				}
				actual = actual->izq;

			} else {
				if ( actual->der == nullptr ) {
					actual->der = new node;
					actual->der->valor = arr[i];
					break;
				}
				actual = actual->der;
			}
		} while( true );
	}

	stack< node* > preOrder;

	preOrder.push( &raiz );

	while( !preOrder.empty() ) {

		node* actual = preOrder.top();
		
		cout << actual->valor << ' ';

		preOrder.pop();

		if ( actual->der != nullptr )
			preOrder.push( actual->der );

		if ( actual->izq != nullptr )
			preOrder.push( actual->izq );
	}
}