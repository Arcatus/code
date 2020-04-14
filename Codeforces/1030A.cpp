#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int t;
	while(n > 0) {
		n--;
		cin >> t;
		if (t == 1) {
			printf("HARD\n");
			return 0;
		}
	}
	printf("EASY\n");
}