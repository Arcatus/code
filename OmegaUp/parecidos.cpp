#include <cstdio>

char cambios[1000001];

int main()
{
	int n, i;
	scanf("%d",&n);
	char s[9];
	
	if (n==1) {
		scanf("%s",s);
		printf("%s\n",s);
		return 0;
	}

	char j;
	char t[9];

	scanf("%s",s);
	
	for (i=0;i<n;++i) {
		scanf("%s",t);
		for (j=0;j<8;++j) {
			if ( s[j] != t[j]) {
				cambios[i] = s[j] + 10*j;
				s[j] = t[j];
				break;
			}
		}
	}	
	int pos;
	printf("%s\n",s);
	for (i=n-2;i>=0;i--)
	{
		pos = (cambios[i]-'0') / 10;
		cambios[i] = (cambios[i]-'0') % 10;
		s[pos] = cambios[i] + '0';
		printf("%s\n",s);
	}
	return 0;
}