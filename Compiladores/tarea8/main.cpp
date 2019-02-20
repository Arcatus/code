/*Compiladores 18-O tarea 8
    Ramirez Martinez Carlos Alberto*/

#include <map>
#include <string>
#include "parser.h"
#include "lexer.h"

int main()
{
    Lexer lexer;
    
    typeTable tabla_simbolos;

    lexer.init(tabla_simbolos);

    Parser parser(lexer.getTokens());

    parser.semanticEnable = false;

    parser.connect(tabla_simbolos);

    parser.P();

    if(parser.getToken().compare("$")==0)
    {
        printf("Success\n");
    }
    else
    {
        printf("Error\n");
    }
    return 0;
}