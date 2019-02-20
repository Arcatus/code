
#include "lexer.h"

Lexer::Lexer(){}
Lexer::~Lexer(){}

qpss& Lexer::getTokens()
{
    return bolsa_token;
}

void Lexer::init(typeTable& tabla_simbolos)
{
    n_linea = 1;

    new_line = true;    

    DFA dfa_id;
    DFA dfa_blanks;
    DFA dfa_num;
    DFA dfa_opr;
    DFA dfa_opa;
    DFA dfa_log;
    DFA dfa_agr;
    DFA dfa_scl;

    unsigned int posicion_tabla = 3;

    std::map<std::string, std::string> agrupadores;

    std::set<string> reservadas;

    tabla_simbolos.emplace(0,make_pair("NTyp","NaN"));
    tabla_simbolos.emplace(1,make_pair("BOOL","true"));
    tabla_simbolos.emplace(2,make_pair("BOOL","false"));

    reservadas.emplace("if"); 
    reservadas.emplace("else");
    reservadas.emplace("do");
    reservadas.emplace("while");
    reservadas.emplace("break");
    reservadas.emplace("num");
    reservadas.emplace("bool");
    reservadas.emplace("true");
    reservadas.emplace("false");

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

    std::istream& inputStream(std::cin);

    std::map<std::string,unsigned int> tab_norep;
    while(inputStream.good())
    {
        if(new_line)
        {
            new_line = false;
            dfaStart(&dfa_blanks,inputStream);
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
        dfaStart(&dfa_blanks,inputStream);
    
        if ( dfaStart(&dfa_id, inputStream) )
        {
            if(reservadas.count(Address) > 0)
            {
                if( Address.compare("true")==0 )
                {
                    bolsa_token.emplace(toUpper(Address),1);
                }
                else if ( Address.compare("false")==0 )
                {
                    bolsa_token.emplace(toUpper(Address),2);
                }
                else
                {
                    bolsa_token.emplace(toUpper(Address),0);
                }
            } 
            else
            {
                if ( tab_norep.count(Address) > 0)
                {
                    bolsa_token.emplace("ID",tab_norep[Address]);
                } 
                else 
                {
                    tab_norep.emplace(Address,posicion_tabla);
                    tabla_simbolos.emplace(posicion_tabla,make_pair("",Address));
                    bolsa_token.emplace("ID",posicion_tabla++);
                }
            }
        } 
        else if ( dfaStart(&dfa_num, inputStream,false) )
        {
            if(SGN_ANT.compare("-")==0)
            {
                bolsa_token.emplace("OP_RES",0);
            }
            else if(SGN_ANT.compare("+")==0)
            {
                bolsa_token.emplace("OP_SUM",0);
            }
            else 
            {
                if (state_save > 2)
                {
                    tabla_simbolos.emplace(posicion_tabla,make_pair("FLOAT",Address));
                    bolsa_token.emplace("LNUM",posicion_tabla++);
                }
                else 
                {
                    tabla_simbolos.emplace(posicion_tabla,make_pair("INT",Address));
                    bolsa_token.emplace("LNUM",posicion_tabla++);   
                }
            }
        } 
        else if ( dfaStart(&dfa_opr, inputStream) )
        {
            if (SGN_ANT.compare("=") == 0 && state_save == 0)
            {
                bolsa_token.emplace("ASSIGN",0);
            } 
            else
            {
                tabla_simbolos.emplace(
                    posicion_tabla,make_pair("RELOP",relopAddress));
                bolsa_token.emplace("RELOP",posicion_tabla++);
            } 
        } 
        else if ( dfaStart(&dfa_opa, inputStream) )
        {
            if (SGN_ANT.compare("*")==0)
            {
                bolsa_token.emplace("OP_MUL",0);
            }
            else if (SGN_ANT.compare("/")==0)
            {
                bolsa_token.emplace("OP_DIV",0);
            }
        } 
        else if ( dfaStart(&dfa_log, inputStream) )
        {
            tabla_simbolos.emplace(
                posicion_tabla,make_pair("LOGOP",relopAddress));
            bolsa_token.emplace("LOGOP",posicion_tabla++);
        } 
        else if ( dfaStart(&dfa_agr , inputStream) )
        {        
            bolsa_token.emplace(agrupadores[SGN_ANT],0);
        } 
        else if ( dfaStart(&dfa_scl, inputStream) )
        {
            bolsa_token.emplace("SEMICOLON",0);
        } 
        else if ( inputStream.get() == '\n' )
        {
            n_linea++;
            new_line = true;
        } 
        else if ( inputStream.get() != -1 )
        {
            std::cout << "Error lexico en linea: " << n_linea << std::endl;
            exit(1);
        }
    }

    bolsa_token.emplace("$",0);
}

void Lexer::printTokens()
{
    while(!bolsa_token.empty())
    {
        std::cout << bolsa_token.front().first << '\n';

        bolsa_token.pop();
    }
}

void Lexer::printTablaSimbolos()
{
    for(auto i : tabla_simbolos)
    {
        std::cout << i.first << " Type: " << i.second.first 
                    << " Address: " << i.second.second << '\n';
    }
}

void Lexer::dfaAddTransition(DFA* dfa, unsigned int state, std::string symbol,
                      unsigned int newState)
{
    dfa->transitionTable.emplace(std::make_pair(
        std::pair<unsigned int, std::string >(state, symbol), newState));
}

void Lexer::dfaAddFinalState(DFA* dfa, unsigned int state)
{
    dfa->finalStates.emplace(state);
}

bool Lexer::dfaStart(DFA* dfa, std::istream& inputStream, bool no_alpha)
{
    unsigned int currentState = dfa->startingState;

    Address = "";
    relopAddress = "";
    state_save = 0;

    while(inputStream.good())
    {
        symbol = inputStream.get();

        if ( isalpha(symbol) > 0 && no_alpha)
        {
            symbol_in = "letra"; Address+=symbol;
        } 
        else if ( isdigit(symbol) > 0 )
        {
            symbol_in = "digit"; Address+=symbol;
        } 
        else if ( symbol == '.' )
        {
            symbol_in = symbol; Address+=symbol;
        }
        else 
        {
            if (symbol!=' ') relopAddress+=symbol;
            symbol_in = symbol; 
        } 

        std::pair<unsigned int, std::string> transition = {currentState, symbol_in};

        if(dfa->transitionTable.count(transition) == 0 )
        {
            inputStream.putback(symbol);

            if(dfa->finalStates.count(currentState) > 0 )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        state_save = currentState;
        SGN_ANT = symbol;

        currentState = dfa->transitionTable[transition];
    }

    if(dfa->finalStates.count(currentState) > 0)
    {
        return true;
    }
    return false;
}

