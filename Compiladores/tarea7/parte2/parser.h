#ifndef PARSER_H
#define PARSER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include "lexer.h"

using std::pair;
using std::string;
using std::cout;

void match(pair<string, string>& l, string l2);

void             P(pair<string, string>&); 
void        Bloque(pair<string, string>&);	
void Declaraciones(pair<string, string>&);	
void             D(pair<string, string>&);	
string        Tipo(pair<string, string>&); 
void    Sentencias(pair<string, string>&); 
void             S(pair<string, string>&);	
string           L(pair<string, string>&);	
string           B(pair<string, string>&);	
string           R(pair<string, string>&);	
string           E(pair<string, string>&);	
string           T(pair<string, string>&);	
string           F(pair<string, string>&);	

void P(pair<string, string>& l)
{
    if(l.first.compare("LCURLY") == 0)
    {
        Bloque(l);
    }
    else if (l.first.compare("$") == 0 )
    {
        return;
    }
    else
    {
        printf("Error P\n");
        exit(1);
    }
}

void Bloque(pair<string, string>& l)
{
	if(l.first.compare("LCURLY") == 0 )
	{	
		match(l,"LCURLY");
		Declaraciones(l);
		Sentencias(l);
		match(l,"RCURLY");
	}
	else
	{
		printf("Error Bloque\n");
		exit(1);
	}
}

void Declaraciones(pair<string, string>& l)
{
	while(1)
	{
		if (l.first.compare("NUM")==0 || l.first.compare("BOOL")==0)
		{
			D(l);
		} 
		else if( l.first.compare("IF")==0    || l.first.compare("RCURLY")==0 || 
			 	 	l.first.compare("DO")==0    || l.first.compare("LCURLY")==0 || 
             	 		l.first.compare("BREAK")==0 ||	l.first.compare("WHILE")==0  || 
             	 			l.first.compare("ID")==0 )
		{
			return;
		}	
		else
		{
			printf("Error Declaraciones\n");
			exit(1);
		}
	}
}

void D(pair<string, string>& l)
{

	string d_tipo = Tipo(l);

	if(l.first.compare("ID")==0)
	{
		string id_addr = l.second;
		match(l,"ID");
		tabla_simbolos.emplace(id_addr,d_tipo);
		match(l,"SEMICOLON");
	}
	else if (l.first.compare("LBRACKET")==0)
	{
		match(l,"LBRACKET");
		match(l,"LNUM");
		match(l,"RBRACKET");
		string id_addr = l.second;
		match(l,"ID");
		tabla_simbolos.emplace(id_addr,d_tipo);
		match(l,"SEMICOLON");
	}
	else if(l.first.compare("WHILE")==0 || l.first.compare("LCURLY")==0 || 
				l.first.compare("DO")==0    ||l.first.compare("BREAK")==0   || 
					l.first.compare("IF")==0    || l.first.compare("ID")==0     ||
						l.first.compare("NUM")==0   || l.first.compare("BOOL")==0 )
	{
		return;
	}
	else
	{
		printf("Error D\n");
		exit(1);
	}
}

string Tipo(pair<string, string>& l)
{
	string tipo_Tipo;

	if(l.first.compare("NUM")==0 || l.first.compare("BOOL")==0)
	{
		tipo_Tipo = l.first;
		match(l,l.first);
	}
	else
	{
		printf("Error Tipo\n");
		exit(1);
	}
	return tipo_Tipo;
}

void Sentencias(pair<string, string>& l)
{
	while(1)
	{
		if (l.first.compare("BREAK")==0 || l.first.compare("DO")==0 || 
				l.first.compare("WHILE")==0 || l.first.compare("IF")==0	|| 
					l.first.compare("ID")==0 || l.first.compare("LCURLY")==0 )
		{
			S(l);
		}
		else if (l.first.compare("RCURLY")==0)
		{
			return;
		}
		else
		{
			printf("Error Sentencias\n");
			exit(1);
		}
	}
}

void S(pair<string, string>& l)
{
	//S->L=B;
	if(l.first.compare("ID")==0)
	{
		string id_addr = L(l);
		string id_tipo = tabla_simbolos[id_addr]; // es num o bool

		match(l,"ASSIGN");
		
		string b_tipo = B(l); // es int, float o bool

		if ( tabla_asign_valida.count(make_pair(id_tipo,b_tipo)) == 0 )
		{
			if (id_tipo.compare("")==0)
			{
				printf("Variable no declarada\n");
			}
			//debug_semantic(id_tipo,b_tipo);
			printf("Error semantico S\n");
			exit(1);
		}
		else
		{
			tabla_simbolos[id_addr] = b_tipo;
		}
		match(l,"SEMICOLON");
	}
	//S->if(B)SS'
	else if(l.first.compare("IF")==0)
	{
		match(l,"IF");
		match(l,"LPAR");
		B(l);
		match(l,"RPAR");
		S(l);
		while(1)
		{
			if(l.first.compare("ELSE")==0)
			{
				match(l,"ELSE");
				S(l);
			} 
			else if( l.first.compare("ID")==0    || l.first.compare("LCURLY")==0 ||
					 	l.first.compare("DO")==0 	 || l.first.compare("BREAK")==0  || 
					 		l.first.compare("IF")==0    || l.first.compare("WHILE")==0  || 
		             			l.first.compare("RCURLY")==0  )
			{
				return;
			}
			else
			{
				printf("Error SS'\n");
				exit(1);
			}
		}
	}
	//S->while(B)S
	else if (l.first.compare("WHILE")==0)
	{
		match(l,"WHILE");
		match(l,"LPAR");
		B(l);
		match(l,"RPAR");
		S(l);
	}
	//S->do S while(B);
	else if( l.first.compare("DO")==0)
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
	else if(l.first.compare("BREAK")==0)
	{
		match(l,"BREAK");
		match(l,"SEMICOLON");
	}
	//S->Bloque
	else if(l.first.compare("LCURLY")==0)
	{
		Bloque(l);
	} 
	else if (l.first.compare("RCURLY")==0)
	{
		return;
	}
	else
	{
		printf("Error S\n");
		exit(1);
	}
}

string L(pair<string, string>& l)
{
	string l_tipo = l.second;

	match(l,"ID");

	while(1)
	{
		if (l.first.compare("LBRACKET")==0)
		{
			match(l,"LBRACKET");
			B(l);
			match(l,"RBRACKET");
		} 
		else if( l.first.compare("OP_MUL")==0    || l.first.compare("OP_DIV")==0   || 
				 	l.first.compare("LOGOP")==0     || l.first.compare("ASSIGN")==0   || 
				 		l.first.compare("RBRACKET")==0  || l.first.compare("RELOP")==0    || 
				 			l.first.compare("SEMICOLON")==0 || l.first.compare("RPAR")==0     || 
				 				l.first.compare("OP_SUM")==0    || l.first.compare("OP_RES")==0 )
		{
			return l_tipo;
		}
		else 
		{
			printf("Error L\n");
			exit(1);
		}
	}
}

string B(pair<string, string>& l)
{
	string r_val = R(l);

	string bp_tipo = r_val;

	while(1)
	{
		if (l.first.compare("RELOP")==0)
		{
			match(l,"RELOP");
			string b1_val = R(l);
			if ( tabla_inferenciaC.count(make_pair(bp_tipo,b1_val)) == 0 )
			{
				//debug_semantic(bp_tipo, b1_val);
				if ( bp_tipo.compare("NUM")==0 || b1_val.compare("NUM")==0 )
				{
					printf("Variable no inicializada\n");
				}
				printf("Error semantico B\n");
				exit(1);
			}
			bp_tipo = tabla_inferenciaC[make_pair(bp_tipo,b1_val)];
		} 
		else if( l.first.compare("RPAR")==0 || 
				 	l.first.compare("RBRACKET")==0 || 
				 		l.first.compare("SEMICOLON")==0 )
		{
			return bp_tipo;
		}
		else
		{
			printf("Error B\n");
			exit(1);
		}
	}
}

string R(pair<string, string>& l)
{
	string e_val = E(l);

	string rp_tipo = e_val;

	while(1)
	{
		if(l.first.compare("LOGOP")==0)
		{
			match(l,"LOGOP");
			string e1_val = E(l);
			if ( tabla_inferenciaL.count(make_pair(rp_tipo,e1_val)) == 0 )
			{
				//debug_semantic(rp_tipo, e1_val);
				printf("Error semantico R\n");
				exit(1);
			}
			rp_tipo = tabla_inferenciaL[make_pair(rp_tipo,e1_val)];
		} 
		else if( l.first.compare("RELOP")==0	||	l.first.compare("RPAR")==0 	|| 
				 	l.first.compare("RBRACKET")==0	||	l.first.compare("SEMICOLON")==0	)
		{
			return rp_tipo;
		}
		else 
		{
			printf("Error R\n");
			exit(1);
		}
	}
}

string E(pair<string, string>& l)
{
	string t_val = T(l);

	string ep_tipo = t_val;

	while(1)
	{
		if(l.first.compare("OP_SUM")==0 || l.first.compare("OP_RES")==0 )
		{
			match(l,l.first);
			string t1_val = T(l);
			if ( tabla_inferenciaSRD.count(make_pair(ep_tipo,t1_val)) == 0 )
			{
				//debug_semantic(ep_tipo, t1_val);
				printf("Error semantico E\n");
				exit(1);
			}
			ep_tipo = tabla_inferenciaSRD[make_pair(ep_tipo,t1_val)];
		}
		else if ( l.first.compare("LOGOP")==0 || l.first.compare("RELOP")==0	|| 
				  	l.first.compare("RPAR")==0  || l.first.compare("SEMICOLON")==0	|| 
				  		l.first.compare("RBRACKET")==0	)
		{
			return ep_tipo;
		}
		else
		{
			printf("Error E\n");
			//printf("Error\n");
			exit(1);
		}
	}
}

string T(pair<string, string>& l)
{
	string f_val = F(l);

	string tp_tipo = f_val;

	while(1)
	{
		if(l.first.compare("OP_MUL")==0)
		{
			match(l,l.first);
			string f1_val = F(l);
			if ( tabla_inferenciaM.count(std::make_pair(tp_tipo,f1_val)) == 0 )
			{
				//debug_semantic(tp_tipo,f1_val);
				if (tp_tipo.compare("FLOAT")==0 && f1_val.compare("FLOAT")==0)
				{
					printf("Operacion no permitida\n");
				}
				printf("Error semantico T1\n");
				exit(1);
			}
			tp_tipo = tabla_inferenciaM[std::make_pair(tp_tipo,f1_val)];
		} 
		else if(l.first.compare("OP_DIV")==0 )
		{
			match(l,l.first);
			string f1_val = F(l);
			if ( tabla_inferenciaSRD.count(std::make_pair(tp_tipo,f1_val)) == 0 )
			{
				//debug_semantic(tp_tipo,f1_val);
				printf("Error semantico T2\n");
				exit(1);
			}
			tp_tipo = tabla_inferenciaSRD[std::make_pair(tp_tipo,f1_val)];
		}
		else if(l.first.compare("OP_SUM")==0   || l.first.compare("OP_RES")==0     || 
					l.first.compare("LOGOP")==0    || l.first.compare("RELOP")==0      || 
						l.first.compare("RPAR")==0     || l.first.compare("SEMICOLON")==0  ||  
							l.first.compare("RBRACKET")==0 )
		{
			return tp_tipo;
		}
		else 
		{
			printf("Error T\n");
			exit(1);
		}


	}
}

string F(pair<string, string>& l)
{
	string lexval;

	if (l.first.compare("LPAR") == 0)
	{
		match(l,"LPAR");
		lexval = B(l);
		match(l,"RPAR");
	} 
	else if (l.first.compare("ID")==0)
	{
		lexval = tabla_simbolos[L(l)];
	}
	else if (l.first.compare("LNUM")==0  || 
			 	l.first.compare("TRUE")==0  || 
			 		l.first.compare("FALSE")==0 ) 
	{
		lexval = l.second;
		match(l,l.first);
	}
	else
	{
		printf("Error F\n");
		exit(1);
	}
	return lexval;
}

void match(pair<string, string>& l, string l2)
{
	if(l.first.compare(l2)==0)
	{
		l = getToken();
	}
	else
	{
		printf("Error match\n");
		exit(1);
	}
}

#endif // PARSER_H
