#ifndef PARSER_H
#define PARSER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include "lexer.h"

#define debug(X) std::cout<<"DEBUG: "<<X<<'\n';

int tokens_procesados = 0;

void match(std::string& l1, std::string l2);

void             P(std::string& token_val); //ok
void        Bloque(std::string& token_val);	
void Declaraciones(std::string& token_val);	
void             D(std::string& token_val);	
void          Tipo(std::string& token_val); //ok
void    Sentencias(std::string& token_val); //ok
void             S(std::string& token_val);	
void             L(std::string& token_val);	
void             B(std::string& token_val);	
void             R(std::string& token_val);	
void             E(std::string& token_val);	//ok
void             T(std::string& token_val);	//ok
void             F(std::string& token_val);	//ok

void P(std::string& l)
{
    if(l.compare("LCURLY") == 0)
    {
        Bloque(l);
    }
    else if (l.compare("$") == 0 )
    {
        return;
    }
    else
    {
        printf("ERROR P\n");
        exit(1);
    }
}

void Bloque(std::string& l)
{
	if(l.compare("LCURLY") == 0 )
	{	
		match(l,"LCURLY");
		Declaraciones(l);
		Sentencias(l);
		match(l,"RCURLY");
	}
	else if (l.compare("WHILE")==0 ||  l.compare("ELSE")==0 || l.compare("DO")==0 ||
             l.compare("BREAK")==0 ||  l.compare("IF")==0   || l.compare("ID")==0 || 
             l.compare("BOOL")==0  ||  l.compare("NUM")==0  || l.compare("$")==0 || 
             l.compare("RCURLY")==0 )
	{
		return;
	}
	else
	{
		printf("ERROR Bloque\n");
		exit(1);
	}
}

void Declaraciones(std::string& l)
{
	while(1)
	{
		if (l.compare("NUM")==0 || l.compare("BOOL")==0)
		{
			D(l);
		} 
		else if(l.compare("WHILE")==0 || l.compare("RCURLY")==0  || l.compare("DO")==0 ||
             	l.compare("BREAK")==0 || l.compare("IF")==0 || l.compare("ID")==0 )
		{
			return;
		}	
		else
		{
			//debug(l);
			printf("ERROR Declaraciones\n");
			exit(1);
		}
	}
}

void D(std::string& l)
{

	Tipo(l);
	if(l.compare("ID")==0)
	{
		match(l,"ID");
		match(l,"SEMICOLON");
	}
	else if (l.compare("LBRACKET")==0)
	{
		match(l,"LBRACKET");
		match(l,"LNUM");
		match(l,"RBRACKET");
		match(l,"ID");
		match(l,"SEMICOLON");
	}
	else if(l.compare("WHILE")==0 || l.compare("LCURLY")==0    || l.compare("DO")==0 ||
            l.compare("BREAK")==0 || l.compare("IF")==0   || l.compare("ID")==0 ||
			l.compare("NUM")==0   || l.compare("BOOL")==0 )
	{
		return;
	}
	else
	{
		printf("ERROR D\n");
		exit(1);
	}
}

void Tipo(std::string& l)
{
	if(l.compare("NUM")==0 || l.compare("BOOL")==0)
	{
		match(l,l);
	}
	else if(l.compare("ID")==0 || l.compare("LBRACKET")==0)
	{
		return;
	}
	else
	{
		printf("ERROR Tipo\n");
		exit(1);
	}
}

void Sentencias(std::string& l)
{
	while(1)
	{
		if (l.compare("BREAK")==0 || l.compare("DO")==0 || l.compare("WHILE")==0 || 
			l.compare("IF")==0	  || l.compare("ID")==0 || l.compare("LCURLY")==0)
		{
			S(l);
		}
		else if (l.compare("RCURLY")==0)
		{
			return;
		}
		else
		{
			printf("ERROR Sentencias\n");
			exit(1);
		}
	}
}

void S(std::string& l)
{
	//S->L=B;
	if(l.compare("ID")==0)
	{
		L(l);
		match(l,"ASSIGN");
		B(l);		
		match(l,"SEMICOLON");
	}
	//S->if(B)SS'
	else if(l.compare("IF")==0)
	{
		match(l,"IF");
		match(l,"LPAR");
		B(l);
		match(l,"RPAR");
		S(l);
		while(1)
		{
			if(l.compare("ELSE")==0)
			{
				match(l,"ELSE");
				S(l);
			} 
			else if(l.compare("WHILE")==0 || l.compare("LCURLY")==0 || l.compare("DO")==0 ||
		            l.compare("BREAK")==0 || l.compare("IF")==0     || l.compare("ID")==0 || 
		            l.compare("RCURLY")==0 )
			{
				return;
			}
			else
			{
				//debug(l);
				printf("ERROR SS'\n");
				exit(1);
			}
		}
	}
	//S->while(B)S
	else if (l.compare("WHILE")==0)
	{
		match(l,"WHILE");
		match(l,"LPAR");
		B(l);
		match(l,"RPAR");
		S(l);
	}
	//S->doSwhile(B);
	else if( l.compare("DO")==0)
	{
		match(l,"DO");
		S(l);
		match(l,"WHILE");
		match(l,"LPAR");
		B(l);
		match(l,"RPAR");
		match(l,"SEMICOLON");
	}
	//S->BREAK;
	else if(l.compare("BREAK")==0)
	{
		match(l,"BREAK");
		match(l,"SEMICOLON");
	}
	//S->Bloque
	else if(l.compare("LCURLY")==0)
	{
		Bloque(l);
	} 
	else if (l.compare("RCURLY")==0 || l.compare("ELSE")==0 )
	{
		return;
	}
	else
	{
		//debug(l);
		printf("ERROR S\n");
		exit(1);
	}
}

void L(std::string& l)
{
	match(l,"ID");

	while(1)
	{
		if (l.compare("LBRACKET")==0)
		{
			match(l,"LBRACKET");
			B(l);
			match(l,"RBRACKET");
		} 
		else if(l.compare("ASSIGN")==0)
		{
			return;
		}
		else 
		{
			//debug(l);
			printf("ERROR L\n");
			exit(1);
		}
	}
}

void B(std::string& l)
{
	R(l);
	while(1)
	{
		if (l.compare("RELOP")==0)
		{
			match(l,"RELOP");
			R(l);
		} 
		else if(l.compare("RPAR")==0 || l.compare("RBRACKET")==0 || l.compare("SEMICOLON")==0 ||
				l.compare("LPAR")==0 || l.compare("LNUM")==0 || l.compare("TRUE")==0 ||
				l.compare("FALSE")==0|| l.compare("ID")==0)
		{
			return;
		}
		else
		{
			printf("ERROR B\n");
			exit(1);
		}
	}
}

void R(std::string& l)
{
	E(l);
	while(1)
	{
		if(l.compare("LOGOP")==0)
		{
			match(l,"LOGOP");
			E(l);
		} 
		else if(l.compare("RPAR")==0 || l.compare("RBRACKET")==0 || l.compare("SEMICOLON")==0 ||
				l.compare("LPAR")==0 || l.compare("LNUM")==0 || l.compare("TRUE")==0 ||
				l.compare("FALSE")==0|| l.compare("ID")==0 || l.compare("RELOP")==0 )
		{
			return;
		}
		else 
		{
			//debug(l);
			printf("ERROR R\n");
			exit(1);
		}
	}
}

void E(std::string& l)
{
	T(l);
	while(1)
	{
		if(l.compare("ARITHOP")==0)
		{
			match(l,"ARITHOP");
			T(l);
		} 
		else if (l.compare("LOGOP")==0 || l.compare("RELOP")==0 || l.compare("RPAR")==0 || 
				 l.compare("SEMICOLON")==0 || l.compare("RBRACKET")==0 )
		{	
			return;
		}
		else
		{
			//debug(l);
			printf("ERROR E\n");
			exit(1);
		}
	}
}

void T(std::string& l)
{
	F(l);
	while(1)
	{
		if(l.compare("ARITHOP")==0)
		{
			match(l,"ARITHOP");
			F(l);
		} 
		else if(l.compare("RELOP")==0 || l.compare("RPAR")==0 ||
				l.compare("RBRACKET")==0 || l.compare("SEMICOLON")==0 ||
				l.compare("LOGOP")==0 )
		{
			return;
		}
		else 
		{
			debug(l);
			std::cout << tokens_procesados;
			printf("ERROR T\n");
			exit(1);
		}
	}
}

void F(std::string& l)
{
	if (l.compare("LPAR")==0)
	{
		match(l,"LPAR");
		B(l);
		match(l,"RPAR");
	} 
	else if (l.compare("ID")==0)
	{
		L(l);
	}
	else if (l.compare("LNUM")==0 || l.compare("TRUE")==0 || l.compare("FALSE")==0)
	{
		match(l,l);
	}
	else if (l.compare("ARITHOP	")==0 || l.compare("RELOP")==0 || l.compare("LOGOP")==0 ||
			 l.compare("RPAR")==0 || l.compare("RBRACKET")==0 || l.compare("SEMICOLON")==0)
	{
		return;
	}
	else
	{
		printf("ERROR F\n");
		exit(1);
	}
}

void match(std::string& l, std::string l2)
{
	if(l.compare(l2)==0)
	{
		tokens_procesados++;
		l = getToken();
	}
	else
	{
		//debug(l);
		printf("ERROR match\n");
		exit(1);
	}
}

#endif // PARSER_H