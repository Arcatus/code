#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n, leave, it;
	cin >> n;

	string events;

	cin >> events;

	vector<bool> rooms;

	for (int i=0; i<10; ++i) {
		rooms.push_back(false);
	}

	for (int i=0; i < events.size(); ++i) {
		if ( events[i] == 'L' ) {
			it = 0;
			while ( rooms[it] != false ) {
				it++;
			}
			rooms[it] = true;
		} else if ( events[i] == 'R' ) {
			it = 9;
			while ( rooms[it] != false ) {
				it--;
			}
			rooms[it] = true;
		} else {
			rooms[ events[i] - '0' ] = false;
		}
	}
	for (bool i: rooms) {
		cout << i;
	}
}