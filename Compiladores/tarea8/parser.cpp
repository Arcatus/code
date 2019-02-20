#include <string>
#include <utility>
#include <cstdio>
#include <cstdlib>

#include "parser.h"

using std::pair;
using std::string;
using std::make_pair;
using std::ofstream;
using std::to_string;

Parser::Parser(){}
Parser::~Parser(){}

void Parser::connect(typeTable& ts)
{
	tabla_simbolos = ts;
}

void Parser::avanzarEntrada()
{
	token = bolsa_token.front();
    bolsa_token.pop();
}

string Parser::getToken() const
{
	return token.first;
}

void Parser::P()
{
    if(token.first.compare("LCURLY") == 0)
    {
        Bloque();
    }
    else if (token.first.compare("$") == 0 )
    {

        return;
    }
    else
    {
        printf("Syntax error P\n");
        exit(1);
    }
}

void Parser::Bloque()
{
	if(token.first.compare("LCURLY") == 0 )
	{	
		match("LCURLY");
		
		Declaraciones();
		Sentencias();

		ofstream outputStream("three_address_code.txt");
		outputStream << mCode.str();
		outputStream.close();
		match("RCURLY");
	}
	else
	{
		printf("Syntax error Bloque\n");
		exit(1);
	}
}

void Parser::Declaraciones()
{
	while(1)
	{
		if (token.first.compare("NUM")==0 || token.first.compare("BOOL")==0)
		{
			D();
		} 
		else if( 	token.first.compare("IF")==0     || 
					token.first.compare("RCURLY")==0 || 
			 	 	token.first.compare("DO")==0     || 
			 	 	token.first.compare("LCURLY")==0 || 
             	 	token.first.compare("BREAK")==0  ||	
             	 	token.first.compare("WHILE")==0  || 
             	 	token.first.compare("ID")==0      )
		{
			return;
		}	
		else
		{
			printf("Syntax error Declaraciones\n");
			exit(1);
		}
	}
}

void Parser::D()
{

	pss retTipo = Tipo();

	if(token.first.compare("ID")==0)
	{
		tabla_simbolos[token.second].first = retTipo.first;
		match("ID");
		match("SEMICOLON");
	}
	else if (token.first.compare("LBRACKET")==0)
	{
		match("LBRACKET");
		match("LNUM");
		match("RBRACKET");
		tabla_simbolos[token.second].first = retTipo.first;
		match("ID");
		match("SEMICOLON");
	}
	else if(	token.first.compare("WHILE")==0  || 
				token.first.compare("LCURLY")==0 || 
				token.first.compare("DO")==0     ||
				token.first.compare("BREAK")==0  || 
				token.first.compare("IF")==0     || 
				token.first.compare("ID")==0     ||
				token.first.compare("NUM")==0    || 
				token.first.compare("BOOL")==0    )
	{
		return;
	}
	else
	{
		printf("Syntax error D\n");
		exit(1);
	}
}

pss Parser::Tipo()
{
	pss retTipo;

	if(token.first.compare("NUM")==0 || token.first.compare("BOOL")==0)
	{
		retTipo.first = token.first;
		match(token.first);
	}
	else
	{
		printf("Syntax error Tipo\n");
		exit(1);
	}
	return retTipo;
}

void Parser::Sentencias()
{
	while(1)
	{
		if (	token.first.compare("BREAK")==0 || 
				token.first.compare("DO")==0    || 
				token.first.compare("WHILE")==0 || 
				token.first.compare("IF")==0	|| 
				token.first.compare("ID")==0    || 
				token.first.compare("LCURLY")==0 )
		{
			string snext = "L" + to_string(mLabelCounter);
    		mLabelCounter++;

			S(snext);

			//mCode << snext +": "; se omite

		}
		else if (token.first.compare("RCURLY")==0)
		{
			return;
		}
		else
		{
			printf("Syntax error Sentencias\n");
			exit(1);
		}
	}
}

void Parser::S(const string& snext)
{
	//S->L=B;
	if(token.first.compare("ID")==0)
	{

		unsigned int id_addr = token.second;

		lvalue = true;
		pss retL = L();

		match("ASSIGN");
		lvalue = false;
		pss retB = B(); 

		mCode  << retL.second << "=" << retB.second << '\n';

		if ( tabla_asign_valida.count(make_pair(retL.first,retB.first)) == 0 
				&& semanticEnable)
		{
			if (retL.first.compare("")==0)
			{
				printf("Variable no declarada\n");
			}			
			printf("Syntax error semantico S\n");
			exit(1);
		}
		else
		{
			tabla_simbolos[id_addr].first = retB.first;
		}
		match("SEMICOLON");
	}
	//S->if(B)SS'
	else if(token.first.compare("IF")==0)
	{
		string bfalse = "L" + to_string(mLabelCounter);
		mLabelCounter++;

		string btrue = "L" + to_string(mLabelCounter);
		mLabelCounter++;

		match("IF");
		match("LPAR");
		B(btrue,bfalse);
		match("RPAR");
		mCode << btrue << ": ";
		S(snext);
		Sp(snext,bfalse);

	}
	//S->while(B)S
	else if (token.first.compare("WHILE")==0)
	{
		string begin = "L" + to_string(mLabelCounter);
        mLabelCounter++;
        string btrue = "L" + to_string(mLabelCounter);
        mLabelCounter++;
        
		match("WHILE");
		match("LPAR");

		mCode << begin << ": ";
		B(btrue,snext);
		match("RPAR");
		mCode << btrue << ": ";
		S(begin);
		mCode << "goto " + begin << '\n';
		mCode << snext << ": ";
	}
	//S->do S while(B);
	else if( token.first.compare("DO")==0)
	{
		match("DO");
		S();
		match("WHILE");
		match("LPAR");
		B();
		match("RPAR");
		match("SEMICOLON");
	}
	//S->BREAK;
	else if(token.first.compare("BREAK")==0)
	{
		match("BREAK");
		match("SEMICOLON");
	}
	//S->Bloque
	else if(token.first.compare("LCURLY")==0)
	{
		Bloque();
	} 
	else if (token.first.compare("RCURLY")==0)
	{
		return;
	}
	else
	{
		printf("Syntax error S\n");
		exit(1);
	}
}

void Parser::Sp(const string& snext,const string& bfalse)
{
	if(token.first.compare("ELSE")==0)
	{
		mCode << "goto "+snext << ": \n";
		mCode << bfalse << ": ";
		match("ELSE");
		S(snext);
		mCode << snext << ": ";
	}
	else if(	token.first.compare("ID")==0     ||
				token.first.compare("LCURLY")==0 ||
			 	token.first.compare("DO")==0 	 || 
			 	token.first.compare("BREAK")==0  || 
			 	token.first.compare("IF")==0     || 
			 	token.first.compare("WHILE")==0  || 
	            token.first.compare("RCURLY")==0  )
	{
		mCode << bfalse << ": ";
		return;
	}
	else
	{
		printf("Syntax error Sp\n");
		exit(1);
	}
}

pss Parser::L()
{
	pss retL = tabla_simbolos[token.second];

	match("ID");

	string lbase = retL.second;
	string ltype = "Type("+lbase+")";

	string tmp{""};

	string tmpRet{""};

	bool uno = true;
	unsigned int contLevel = 0;
	while(1)
	{
		if (token.first.compare("LBRACKET")==0)
		{
			contLevel++;
			tmp = "t" + to_string(mTempCounter);
        	mTempCounter++;
			match("LBRACKET");
			pss retB = B();
			match("RBRACKET");

			mCode << tmp << "=" << "w("+ltype+")*"+retB.second+"\n";
			if (uno){tmpRet += tmp;uno=false;}
			else tmpRet+="+"+tmp;
			retL.second=tmpRet;
		} 
		else if( token.first.compare("OP_MUL")==0    || token.first.compare("OP_DIV")==0   || 
				 token.first.compare("LOGOP")==0     || token.first.compare("ASSIGN")==0   || 
				 token.first.compare("RBRACKET")==0  || token.first.compare("RELOP")==0    || 
				 token.first.compare("SEMICOLON")==0 || token.first.compare("OP_RES")==0   ||
				 token.first.compare("OP_SUM")==0    || token.first.compare("RPAR")==0 		)
		{
			if ( contLevel > 1)
			{
				string tmp1 = "t" + to_string(mTempCounter);
        		mTempCounter++;
				if (lvalue)
				{
					mCode << tmp1 << "=" << retL.second <<'\n';
					retL.second = lbase+"["+tmp1+"]";
				}
				else 
				{
					string tmp2 = "t" + to_string(mTempCounter);
        			mTempCounter++;
        			mCode << tmp1 << "=" << retL.second<<'\n';
	        		mCode << tmp2 << "=" << lbase+"["+tmp1+"]" <<'\n';
	        		retL.second = tmp2;
				}
			} 
			else if( contLevel == 1)
			{
				retL.second = lbase+"["+tmp+"]";
			}
			return retL;
		}
		else 
		{
			printf("Syntax error L\n");
			exit(1);
		}
	}
}

pss Parser::B(const std::string& btrue, const std::string& bfalse)
{
	pss retR = R(btrue,bfalse);

	while(1)
	{
		if(token.first.compare("LOGOP")==0)
		{
			string AddressRelop = tabla_simbolos[token.second].second;

			match("LOGOP");

			pss retR1 = R(btrue,bfalse);

			mCode << "if " << retR.second << AddressRelop 
			<< retR1.second << " goto " + btrue << "\ngoto " + bfalse <<'\n';

			if ( tabla_inferencia_Logop.count(make_pair(retR.first,retR1.first))==0 
					&& semanticEnable )
			{
				printf("Error semantico B\n");
				exit(1);
			}
			retR.first = tabla_inferencia_Logop[make_pair(retR.first,retR1.first)];
		} 
		else if( 	token.first.compare("RPAR")==0 		|| 
				 	token.first.compare("RBRACKET")==0	||	
				 	token.first.compare("SEMICOLON")==0	 )
		{
			return retR;
		}
		else 
		{
			printf("Syntax error B\n");
			exit(1);
		}
	}
}

pss Parser::R(const std::string& btrue, const std::string& bfalse)
{
	pss retE = E();

	while(1)
	{
		if (token.first.compare("RELOP")==0 )
		{
			string AddressRelop = tabla_simbolos[token.second].second;

			match("RELOP");

			pss retE1 = E();

			mCode << "if " << retE.second << AddressRelop 
			<< retE1.second << " goto " + btrue << "\ngoto " + bfalse <<'\n';

			if ( tabla_inferencia_Relop.count(make_pair(retE.first,retE1.first)) == 0 
					&& semanticEnable )
			{
				if ( retE.first.compare("NUM")==0 || retE1.first.compare("NUM")==0 )
				{
					printf("Variable no inicializada\n");
				}
				printf("Syntax error semantico R\n");
				exit(1);
			}        
			retE.first = tabla_inferencia_Relop[make_pair(retE.first,retE1.first)];
		} 
		else if( token.first.compare("RPAR")==0 	 ||
				 token.first.compare("LOGOP")==0 	 ||
				 token.first.compare("RBRACKET")==0  || 
				 token.first.compare("SEMICOLON")==0 )
		{
			return retE;
		}
		else
		{
			printf("Syntax error R\n");
			exit(1);
		}
	}
}

pss Parser::E()
{
	char signo;
	pss retT = T();

	while(1)
	{
		if(token.first.compare("OP_SUM")==0 || token.first.compare("OP_RES")==0 )
		{
			string temp = "t" + to_string(mTempCounter);
            mTempCounter++;
            
            signo = (token.first.compare("OP_SUM")==0)?'+':'-';
			match(token.first);

			pss retT1 = T();

			mCode << temp << "=" << retT.second << signo << retT1.second << '\n';

            retT.second = temp;

			if ( tabla_inferencia_Arith.count(make_pair(retT.first,retT1.first)) == 0 
					&& semanticEnable )
			{
				printf("Error semantico E\n");
				exit(1);
			}
			retT.first = tabla_inferencia_Arith[make_pair(retT.first,retT1.first)];
		}
		else if ( 	token.first.compare("LOGOP")==0 	|| 
					token.first.compare("RELOP")==0		|| 
				  	token.first.compare("RPAR")==0  	|| 
				  	token.first.compare("SEMICOLON")==0	|| 
				  	token.first.compare("RBRACKET")==0	 )
		{
			return retT;
		}
		else
		{
			printf("Syntax error E\n");
			exit(1);
		}
	}
}

pss Parser::T()
{
	pss retF = F();

	while(1)
	{
		if(token.first.compare("OP_MUL")==0)
		{
			string temp = "t" + to_string(mTempCounter);
            mTempCounter++;

			match(token.first);

			pss retF1 = F();

			mCode << temp << "=" << retF.second << "*" << retF1.second << '\n';

            retF.second = temp;

			if (tabla_inferencia_Mult.count(std::make_pair(retF.first,retF1.first))==0 
					&& semanticEnable)
			{
				if (retF.first.compare("FLOAT")==0 && retF1.first.compare("FLOAT")==0)
				{
					printf("Operacion no permitida\n");
				}
				printf("Error semantico T1\n");
				exit(1);
			}
			retF.first = tabla_inferencia_Mult[std::make_pair(retF.first,retF1.first)];
		} 
		else if(token.first.compare("OP_DIV")==0 )
		{
			string temp = "t" + to_string(mTempCounter);
            mTempCounter++;

			match(token.first);

			pss retF1 = F();

			mCode << temp << "=" << retF.second << "/" << retF1.second << '\n';

            retF.second = temp;

			if ( tabla_inferencia_Arith.count(std::make_pair(retF.first,retF1.first)) == 0 
					&& semanticEnable)
			{
				printf("Error semantico T2\n");
				exit(1);
			}
			retF.first = tabla_inferencia_Arith[std::make_pair(retF.first,retF1.first)];
		}
		else if(
					token.first.compare("SEMICOLON")==0  ||
					token.first.compare("RBRACKET")==0   || 
					token.first.compare("OP_SUM")==0   	 || 
					token.first.compare("OP_RES")==0     || 
					token.first.compare("LOGOP")==0      || 
					token.first.compare("RELOP")==0      || 
					token.first.compare("RPAR")==0       )
		{

			return retF;
		}
		else 
		{
			printf("Syntax error T\n");
			exit(1);
		}
	}
}

pss Parser::F()
{
	pss retF; 

	if (token.first.compare("LPAR") == 0)
	{
		match("LPAR");
		retF = B();
		match("RPAR");
	} 
	else if (token.first.compare("ID")==0)
	{
		retF = L();
	}
	else if (token.first.compare("LNUM")==0  || 
			 token.first.compare("TRUE")==0  || 
			 token.first.compare("FALSE")==0  ) 
	{
		retF = tabla_simbolos[token.second];
		match(token.first);
	}
	else
	{
		printf("Syntax error F\n");
		exit(1);
	}
	return retF;
}
Parser::Parser(qpss& t)
{
	bolsa_token = t;
	token = bolsa_token.front();
    bolsa_token.pop();

    tabla_inferencia_Arith.emplace(
    	make_pair("INT","INT"),"INT");

    tabla_inferencia_Arith.emplace(
    	make_pair("INT","FLOAT"),"FLOAT");

    tabla_inferencia_Arith.emplace(
    	make_pair("FLOAT","INT"),"FLOAT");

    tabla_inferencia_Arith.emplace(
    	make_pair("FLOAT","FLOAT"),"FLOAT");

    tabla_inferencia_Mult.emplace(
    	make_pair("INT","INT"),"INT");

    tabla_inferencia_Mult.emplace(
    	make_pair("INT","FLOAT"),"FLOAT");

    tabla_inferencia_Mult.emplace(
    	make_pair("FLOAT","INT"),"FLOAT");

    tabla_inferencia_Logop.emplace(
    	make_pair("BOOL","BOOL"),"BOOL");

    tabla_inferencia_Relop.emplace(
    	make_pair("INT","INT"),"BOOL");

    tabla_inferencia_Relop.emplace(
    	make_pair("FLOAT","FLOAT"),"BOOL");

    tabla_inferencia_Relop.emplace(
    	make_pair("INT","FLOAT"),"BOOL");

    tabla_inferencia_Relop.emplace(
    	make_pair("FLOAT","INT"),"BOOL");

    tabla_asign_valida.emplace(
    	make_pair("INT","INT"));

    tabla_asign_valida.emplace(
    	make_pair("FLOAT","FLOAT"));

    tabla_asign_valida.emplace(
    	make_pair("INT","FLOAT"));

    tabla_asign_valida.emplace(
    	make_pair("FLOAT","INT"));

    tabla_asign_valida.emplace(
    	make_pair("NUM","INT"));

    tabla_asign_valida.emplace(
    	make_pair("NUM","FLOAT"));

    tabla_asign_valida.emplace(
    	make_pair("BOOL","BOOL"));
}

void Parser::match(string cmp)
{
	if(token.first.compare(cmp)==0)
	{
		avanzarEntrada();
	}
	else
	{
		printf("Error match\n");
		exit(1);
	}
}

void Parser::printTablaSimbolos()
{
    for(auto i : tabla_simbolos)
    {
        std::cout << i.first << " Type:" << i.second.first 
                  << "\t| Address: " << i.second.second << '\n';
    }
}