#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500

int existe(char str[], int i)
{ 
	for (int j = i-1; j >= 0; j--)
	if (str[i] == str[j]) return 1;
	return 0;
} 
void contar_letras(char str[]) 
{ 
	for (int i = 0; str[i] != '\n'; i++) 
	if (!existe(str, i)) {
		int cont = 1; 
		for (int j = i+1; str[j] != '\n'; j++) 
		if (str[i] == str[j]) cont++; 
		printf("%c = %d\n", str[i], cont); 
	} 
} 
char p[4];

int main() 
{ 
	char str[MAX_SIZE]; 
	printf("\tIngrese su palabra o frase: \n\n\t");
	fgets(str, MAX_SIZE, stdin);
	
	for (int i=0; i<=4; i++) {
		scanf("%c",&p[i]);
	}
	if (p[1]==p[4]&&p[2]==p[3]) {
		printf("\tEs un palindromo\n");
	} else {
		printf("\tNo es un palindrono\n");
	}
	printf("\tConteo de cuantas ocurrencias de cada letra contiene una palabra\n");
	contar_letras(str); 
	getchar(); 
	return 0; 
}