#include <iostream> 
#include <algorithm>
#include <set>

using namespace std;

enum{ HORIZONTAL, VERTICAL };

int main()
{
	int n, m;

	cin >> n >> m;

	int x, y, turno = 0;

	set< pair<int, int> > dibujados;

	auto valida = [&](int x, int y){
		if ( x > y ) swap(x,y);

		if ( dibujados.find({ x, y }) == dibujados.end() ) {
			dibujados.emplace(x,y);
		}

		int posicion = ( y - 1  ==  x ) ? HORIZONTAL : VERTICAL;

		int ans = 0;

		if ( posicion == HORIZONTAL ) {
			if ( x - n > 0 ) {
				bool top   = (dibujados.find({ x-n, y-n }) != dibujados.end() )?1:0;
				bool left  = (dibujados.find({ x-n, x }) != dibujados.end() )?1:0;
				bool right = (dibujados.find({ y-n, y }) != dibujados.end() )?1:0;
				if ( top && left && right ) {
					ans += 1;
				}
			}
			if ( x + n < n*n ) {
				bool left  = (dibujados.find({ x, x+n }) != dibujados.end() )?1:0;
				bool right = (dibujados.find({ y, y+n }) != dibujados.end() )?1:0;
				bool bottom   = (dibujados.find({ x+n, y+n }) != dibujados.end() )?1:0;
				if ( left && right && bottom ) {
					ans += 1;
				}
			}
		} else {
			if ( x % n != 1 ) {
				bool top   = (dibujados.find({ x-1, x }) != dibujados.end() )?1:0;
				bool left  = (dibujados.find({ x-1, x-1+n }) != dibujados.end() )?1:0;
				bool bottom = (dibujados.find({ x-1+n, y }) != dibujados.end() )?1:0;
				if ( top && bottom && left ) {
					ans += 1;
				}
			}
			if ( x % n != 0 ) {
				bool top   = (dibujados.find({ x, x+1 }) != dibujados.end() )?1:0;
				bool right = (dibujados.find({ x+1, x+1+n }) != dibujados.end() )?1:0;
				bool bottom   = (dibujados.find({ y, x+1+n }) != dibujados.end() )?1:0;
				if ( top && right && bottom ) {
					ans += 1;
				}
			}
		}
		return ans;
	};
	
	int player1 = 0, player2 = 0;

	for(int i=0; i<m; ++i) {
		cin >> x >> y;

		int res = valida(x, y);

		/*cout << "turno de ";
		if ( turno % 2 == 0) {
			cout << "player1\n";
		} else cout << "player2\n";
		*/
		if ( res > 0 ) {
			if ( turno % 2 == 0 ) {
				//cout << "anotacion P1 +" << res << " se gana un turno extra\n";
				player1 += res;
				turno-=1;
			} else {
				//cout << "anotacion P2 +" << res << " se gana un turno extra\n";
				player2 += res;
				turno-=1;
			}
		}
		turno++;
	}
	cout << player1 << " " << player2 << '\n';
}