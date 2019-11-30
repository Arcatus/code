//#include <iostream>
#include <cstdio>
#include <cstring>
//#include <bitset>
#include <vector>

using namespace std;

int main()
{
	int v, n;

	scanf("%d %d",&v,&n);

	vector< pair<char,int> > guardar[n];

	char opc[3];
	bool used[25+1] = { };

	for (int i=0; i<n; ++i) {
		for (int k=0;k<3;++k) {
			scanf("%s",opc);
			used[opc[1]-'a'] = true;
			guardar[i].push_back({opc[0],opc[1]-'a'});
		}
	}

	int assigned[26];	

	int offset = 0;
	for (int i=0; i<=25; ++i) {
		if ( used[i] ) {
			assigned[i] = offset++;
		}
	}	

	int bitmask[n][3] = { };

	for (int i=0; i<n; ++i) {
		for (int j=0; j<3; ++j) {
			if ( guardar[i][j].first == '!' ) {
				bitmask[i][j] = 1<<assigned[ guardar[i][j].second];
			}
		}
	}
	
	for (int k=0; k < ( 1<<v ); ++k) {
		bool ans=true, tmp;
		for (int i=0; i<n; ++i) {
			tmp =	(k&(1<<assigned[ guardar[i][0].second ])^bitmask[i][0]) ||
					(k&(1<<assigned[ guardar[i][1].second ])^bitmask[i][1]) ||
					(k&(1<<assigned[ guardar[i][2].second ])^bitmask[i][2]);
			ans = ans && tmp;
			if ( !ans ) break;
		}
		if ( ans ) {
			printf("1\n");
			return 0;
		}
	}
	printf("0\n");
}