#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

short op;
char a;
string token;

unordered_map<string,short> token_bag;

enum { T, F, NOT, AND, OR, NOR, NAND, XOR, XNOR };

short getToken()
{
	token = "";
	a = cin.get();
	while( !isalpha(a) ) {
		a = cin.get();
	}	
	while(isalpha(a)) {
		token += a;
		a = cin.get();
	}
	return token_bag[token];
}

short solve()
{
	op = getToken();

	if (op == T) {
		return 1;
	} else if (op == F) { 

		return 0;
	} else if ( op == NOT ) { 

		return !solve();

	} else if( op == OR ) { 

		return solve() | solve();

	} else if( op == AND ) { 

		return solve() & solve();

	} else if( op == NAND ) {

		return !( solve() & solve() );

	} else if( op == NOR ) {

		return !(solve() | solve());
		
	} else if( op == XOR ) { 

		return solve() ^ solve();
		
	} else if( op == XNOR ){
		
		return !(solve()^solve());
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	token_bag["AND"] = AND;
	token_bag["TRUE"] = T;
	token_bag["FALSE"] = F;
	token_bag["OR"] = OR;
	token_bag["NOR"] = NOR;
	token_bag["XOR"] = XOR;
	token_bag["NAND"] = NAND;
	token_bag["NOT"] = NOT;
	token_bag["XNOR"] = XNOR;

	if ( solve() == 1 )
		cout << "TRUE" << '\n';
	else
		cout << "FALSE" << '\n';

	return 0;
}