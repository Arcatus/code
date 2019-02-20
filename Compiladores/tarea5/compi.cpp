#include "parser.h"
#include "lexer.h"

int main()
{
	DFA dfa_id, dfa_blanks, dfa_num, dfa_opr, dfa_opa, dfa_log, dfa_agr, dfa_scl;

    tabla_simbolos.emplace("if"); 
    tabla_simbolos.emplace("else");
    tabla_simbolos.emplace("do");
    tabla_simbolos.emplace("while");
    tabla_simbolos.emplace("break");
    tabla_simbolos.emplace("num");
    tabla_simbolos.emplace("bool");
    tabla_simbolos.emplace("true");
    tabla_simbolos.emplace("false");

    agrupadores.emplace("{","LCURLY");
    agrupadores.emplace("}","RCURLY");
    agrupadores.emplace("(","LPAR");
    agrupadores.emplace(")","RPAR");
    agrupadores.emplace("[","LBRACKET");
    agrupadores.emplace("]","RBRACKET");

    dfaAddTransition(&dfa_blanks, 0, "\t", 1);
    dfaAddTransition(&dfa_blanks, 0, " " , 1);
    dfaAddTransition(&dfa_blanks, 1, "\t", 1);
    dfaAddTransition(&dfa_blanks, 1, " " , 1);

    dfaAddFinalState(&dfa_blanks, 1);

	dfaAddTransition(&dfa_id,0,"letra",1);
	dfaAddTransition(&dfa_id,0,  "_"  ,1);
	dfaAddTransition(&dfa_id,1,  "_"  ,1);
	dfaAddTransition(&dfa_id,1,"letra",1);
	dfaAddTransition(&dfa_id,1,"digit",1);

    dfaAddFinalState(&dfa_id, 1);

    dfaAddTransition(&dfa_num,0,  "-"  ,1);
    dfaAddTransition(&dfa_num,0,  "+"  ,1);
    dfaAddTransition(&dfa_num,0,"digit",2);
    dfaAddTransition(&dfa_num,1,"digit",2);
    dfaAddTransition(&dfa_num,2,"digit",2);
    dfaAddTransition(&dfa_num,2,  "."  ,3);
    dfaAddTransition(&dfa_num,2,  "e"  ,5);
    dfaAddTransition(&dfa_num,3,"digit",4);
    dfaAddTransition(&dfa_num,4,"digit",4);
    dfaAddTransition(&dfa_num,4,  "e"  ,5);
    dfaAddTransition(&dfa_num,5,  "-"  ,6);
    dfaAddTransition(&dfa_num,5,  "+"  ,6);
    dfaAddTransition(&dfa_num,5,"digit",7);
    dfaAddTransition(&dfa_num,6,"digit",7);
    dfaAddTransition(&dfa_num,7,"digit",7);

    dfaAddFinalState(&dfa_num, 1);
    dfaAddFinalState(&dfa_num, 2);
    dfaAddFinalState(&dfa_num, 4);
    dfaAddFinalState(&dfa_num, 7);

    dfaAddTransition(&dfa_opr,0, "<", 1);
    dfaAddTransition(&dfa_opr,0, ">", 4);
    dfaAddTransition(&dfa_opr,0, "=", 7);
    dfaAddTransition(&dfa_opr,0, "!",10);
    dfaAddTransition(&dfa_opr,1, "=", 2);
    dfaAddTransition(&dfa_opr,4, "=", 5);
    dfaAddTransition(&dfa_opr,7, "=", 8);
    dfaAddTransition(&dfa_opr,10,"=",11);

    dfaAddFinalState(&dfa_opr, 1);
    dfaAddFinalState(&dfa_opr, 2);
    dfaAddFinalState(&dfa_opr, 4);
    dfaAddFinalState(&dfa_opr, 5);
    dfaAddFinalState(&dfa_opr, 7);
    dfaAddFinalState(&dfa_opr, 8);
    dfaAddFinalState(&dfa_opr,11);

    //dfaAddTransition(&dfa_opa,0, "+", 1);
    //dfaAddTransition(&dfa_opa,0, "-", 1);
    dfaAddTransition(&dfa_opa,0, "*", 1);
    dfaAddTransition(&dfa_opa,0, "%", 1);
    dfaAddTransition(&dfa_opa,0, "/", 1);

    dfaAddFinalState(&dfa_opa, 1);

    dfaAddTransition(&dfa_log,0, "&", 1);
    dfaAddTransition(&dfa_log,1, "&", 2);
    dfaAddTransition(&dfa_log,0, "|", 3);
    dfaAddTransition(&dfa_log,3, "|", 4);

    dfaAddFinalState(&dfa_log, 2);
    dfaAddFinalState(&dfa_log, 4);

    dfaAddTransition(&dfa_agr,0, "(", 1);
    dfaAddTransition(&dfa_agr,0, ")", 1);
    dfaAddTransition(&dfa_agr,0, "[", 1);
    dfaAddTransition(&dfa_agr,0, "]", 1);
    dfaAddTransition(&dfa_agr,0, "{", 1);
    dfaAddTransition(&dfa_agr,0, "}", 1);

    dfaAddFinalState(&dfa_agr, 1);

    dfaAddTransition(&dfa_scl,0, ";", 1);

    dfaAddFinalState(&dfa_scl, 1);

    auto toUpper = []( std::string str ){
    	std::string ret = "";
        std::locale loc;
        for (std::string::size_type i = 0; i < str.length(); ++i)
        {
         	ret += std::toupper(str[i],loc);
        }
    	return ret;
    };

    while(inputStream.good())
    {
        if(new_line)
        {
            new_line = false;
            dfaStart(&dfa_blanks,inputStream, 0);
            symbol = inputStream.get();
            if (symbol == '\n')
            {
                n_linea++;
                new_line = true;
                continue;
            } 
            else 
            {
                inputStream.putback(symbol);
            }
        }
        dfaStart(&dfa_blanks,inputStream, 0);
    
        if ( dfaStart(&dfa_id, inputStream) )
        {
            if(tabla_simbolos.count(index_sintax) > 0)
            {
                bolsa_token.emplace(toUpper(index_sintax));
            } 
            else
            {
                bolsa_token.emplace("ID");
            } 
        } 
        else if ( dfaStart(&dfa_num, inputStream,false) )
        {
            if(SGN_ANT.compare("-")==0 || SGN_ANT.compare("+")==0)
            {
                bolsa_token.emplace("ARITHOP");
            }
            else 
            {
            	bolsa_token.emplace("LNUM");
            }
        } 
        else if ( dfaStart(&dfa_opr, inputStream) )
        {
            if (SGN_ANT.compare("=") == 0 && state_save == 0)
            {
                bolsa_token.emplace("ASSIGN");
            } 
            else
            {
                bolsa_token.emplace("RELOP");
            } 
        } 
        else if ( dfaStart(&dfa_opa, inputStream) )
        {
            bolsa_token.emplace("ARITHOP");
        } 
        else if ( dfaStart(&dfa_log, inputStream) )
        {
            bolsa_token.emplace("LOGOP");
        } 
        else if ( dfaStart(&dfa_agr , inputStream) )
        {        
            bolsa_token.emplace(agrupadores[SGN_ANT]);
        } 
        else if ( dfaStart(&dfa_scl, inputStream) )
        {
            bolsa_token.emplace("SEMICOLON");
        } 
        else if ( inputStream.get() == '\n' )
        {
            n_linea++;
            new_line = true;
        } 
        else if ( inputStream.get() != -1 )
        {
            std::cout << "Error sintactico linea: " << n_linea << std::endl;
            exit(1);
        }
    }

    bolsa_token.emplace("$");

	std::string l = getToken();

    P(l);

    if(l.compare("$")==0)
    {
        printf("Success\n");
    }
    else
    {
    	//debug(l);
        printf("Error main\n");
    }
    return 0;
}
