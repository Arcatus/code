#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
int main (){
	
	char linea[85]; 
	int i;
	scanf("%85[^\n]", linea);
    linea[strlen(linea)] = 0;
	i=0;
    while(!isalpha(linea[i])) {
        i++;
    }
	linea[i]=toupper(linea[i]);
    i++;
	while(linea[i] !='\0') {
        while(linea[i]!='\0' && isspace(linea[i]))i++;
		if(ispunct(linea[i])) {
            while(linea[i]!='\0' && !isalpha(linea[i])) i++;
			linea[i]=toupper(linea[i]); i++;
        } else {
            linea[i]=tolower(linea[i]);
            i++;
        }
	}
	puts(linea); 
	return 0;
}