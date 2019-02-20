#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include <vector>
#include <locale>
#include <sstream> 
#include <utility>
#include <iostream>

bool new_line = true;

unsigned int n_linea = 1, costo = 0;

int state_save; char symbol;

std::string index_sintax, symbol_in, SGN_ANT, tokenizer;

std::queue<std::string> bolsa_token;

std::set<std::string> tabla_simbolos;
std::map<std::string, std::string> agrupadores;
std::map< std::pair<std::string, std::string>, std::string> tabla_parseo;

struct DFA
{
    unsigned int startingState = { 0 };
    std::set<unsigned int> finalStates;
    std::map<std::pair<unsigned int, std::string>, unsigned int> transitionTable;
};

void dfaAddTransition(DFA* dfa, unsigned int state, std::string symbol,
                      unsigned int newState)
{
    dfa->transitionTable.emplace(std::make_pair(
        std::pair<unsigned int, std::string >(state, symbol), newState));
}

void dfaAddFinalState(DFA* dfa, unsigned int state)
{
    dfa->finalStates.emplace(state);
}

bool dfaStart(DFA* dfa, std::istream& inputStream, bool no_alpha = true)
{
    unsigned int currentState = dfa->startingState;

    index_sintax = "";
    state_save = 0;

    while(inputStream.good())
    {
        symbol = inputStream.get();

        if ( isalpha(symbol) > 0 && no_alpha)
        {
            symbol_in = "letra"; index_sintax+=symbol;
        } 
        else if ( isdigit(symbol) > 0 )
        {
            symbol_in = "digit"; index_sintax+=symbol;
        } 
        else 
        {
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


int main()
{
    std::istream& inputStream(std::cin);

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
            if(SGN_ANT.compare("-")==0)
            {
                bolsa_token.emplace("OP_RES");
            }
            else if(SGN_ANT.compare("+")==0)
            {
                bolsa_token.emplace("OP_SUM");
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
            if (SGN_ANT.compare("*")==0)
            {
                bolsa_token.emplace("OP_MUL");
            }
            else if (SGN_ANT.compare("/")==0)
            {
                bolsa_token.emplace("OP_DIV");
            }
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

    auto insertaTP = [](std::string a, std::string b, std::string c)
    {
        tabla_parseo.emplace(std::make_pair(a,b),c);
    };

    //PRIM F INVERTIDO 
    insertaTP("F","LPAR", "RPAR B LPAR");
    insertaTP("F","LNUM", "LNUM");
    insertaTP("F","TRUE", "TRUE");
    insertaTP("F","FALSE","FALSE");
    insertaTP("F","ID",   "6 L");
 
    //PRIM T INVERTIDO
    insertaTP("T","LPAR", "Tp F");
    insertaTP("T","LNUM", "Tp F");
    insertaTP("T","FALSE","Tp F");
    insertaTP("T","TRUE", "Tp F");
    insertaTP("T","ID",   "Tp F");

    //PRIM Tp INVERTIDO
    insertaTP("Tp","OP_MUL","4 Tp F OP_MUL");
    insertaTP("Tp","OP_DIV","5 Tp F OP_DIV");
    //SIG Tp 
    insertaTP("Tp","OP_SUM",   "ε"); 
    insertaTP("Tp","OP_RES",   "ε"); 
    insertaTP("Tp","LOGOP",    "ε");
    insertaTP("Tp","RELOP",    "ε");
    insertaTP("Tp","RPAR",     "ε");
    insertaTP("Tp","SEMICOLON","ε");
    insertaTP("Tp","RBRACKET", "ε");    


    //PRIM E INVERTIDO
    insertaTP("E","LPAR", "Ep T");
    insertaTP("E","LNUM", "Ep T");
    insertaTP("E","FALSE","Ep T");
    insertaTP("E","TRUE", "Ep T");
    insertaTP("E","ID",   "Ep T");

    //PRIM Ep INVERTIDO
    insertaTP("Ep","OP_SUM","2 Ep T OP_SUM");
    insertaTP("Ep","OP_RES","3 Ep T OP_RES"); 
    //SIG Ep
    insertaTP("Ep","LOGOP",    "ε");
    insertaTP("Ep","RELOP",    "ε");
    insertaTP("Ep","RPAR",     "ε");
    insertaTP("Ep","RBRACKET", "ε");
    insertaTP("Ep","SEMICOLON","ε");

    //PRIM R INVERTIDO
    insertaTP("R","LNUM", "Rp E");
    insertaTP("R","LPAR", "Rp E");
    insertaTP("R","FALSE","Rp E");
    insertaTP("R","TRUE", "Rp E");
    insertaTP("R","ID",   "Rp E"); 
    
    //PRIM Rp INVERTIDO
    insertaTP("Rp","LOGOP", "E LOGOP");
    //SIG Rp
    insertaTP("Rp","RELOP",    "ε");
    insertaTP("Rp","RPAR",     "ε");
    insertaTP("Rp","RBRACKET", "ε");
    insertaTP("Rp","SEMICOLON","ε");

    //PRIM B INVERTIDO
    insertaTP("B","LPAR", "Bp R");
    insertaTP("B","LNUM", "Bp R");
    insertaTP("B","FALSE","Bp R");
    insertaTP("B","TRUE", "Bp R");
    insertaTP("B","ID",   "Bp R");

    //PRIM Bp INVERTIDO
    insertaTP("Bp","RELOP", "Bp R RELOP");
    //SIG Bp 
    insertaTP("Bp","RPAR",     "ε");
    insertaTP("Bp","RBRACKET", "ε");
    insertaTP("Bp","SEMICOLON","ε");

    //PRIM L INVERTIDO
    insertaTP("L","ID", "Lp ID");

    //PRIM Lp INVERTIDO
    insertaTP("Lp","LBRACKET", "Lp RBRACKET B LBRACKET");
    //SIG Lp
    insertaTP("Lp","OP_MUL",   "ε");
    insertaTP("Lp","OP_SUM",   "ε");
    insertaTP("Lp","OP_RES",   "ε");
    insertaTP("Lp","OP_DIV",   "ε");
    insertaTP("Lp","LOGOP",    "ε");
    insertaTP("Lp","ASSIGN",   "ε");
    insertaTP("Lp","RBRACKET", "ε");
    insertaTP("Lp","RELOP",    "ε");
    insertaTP("Lp","SEMICOLON","ε");
    insertaTP("Lp","RPAR",     "ε");

    //PRIM S INVERTIDO
    insertaTP("S","WHILE", "S RPAR B LPAR WHILE");
    insertaTP("S","BREAK", "SEMICOLON BREAK");
    insertaTP("S","DO",    "SEMICOLON RPAR B LPAR WHILE S DO");
    /* semantic */ 
    insertaTP("S","ID",    "1 SEMICOLON B ASSIGN L");

    insertaTP("S","IF",    "Sp S RPAR B LPAR IF");
    insertaTP("S","LCURLY","BLOQUE");

    //PRIM Sp INVERTIDO
    insertaTP("Sp","ELSE", "S ELSE");
    //SIG Sp
    insertaTP("Sp","WHILE", "ε");
    insertaTP("Sp","BREAK", "ε");
    insertaTP("Sp","DO",    "ε");
    insertaTP("Sp","IF",    "ε");
    insertaTP("Sp","ID",    "ε");
    insertaTP("Sp","LCURLY","ε");
    insertaTP("Sp","RCURLY","ε");

    //PRIM Sentencias
    insertaTP("Sentencias","ID",    "Sentenciasp");
    insertaTP("Sentencias","BREAK", "Sentenciasp");
    insertaTP("Sentencias","DO",    "Sentenciasp");
    insertaTP("Sentencias","WHILE", "Sentenciasp");
    insertaTP("Sentencias","IF",    "Sentenciasp");
    insertaTP("Sentencias","LCURLY","Sentenciasp");
    //SIG Sentencias
    insertaTP("Sentencias","RCURLY", "ε");

    //PRIM Sentenciasp INVERTIDO
    insertaTP("Sentenciasp","ID",    "Sentenciasp S");
    insertaTP("Sentenciasp","BREAK", "Sentenciasp S");
    insertaTP("Sentenciasp","DO",    "Sentenciasp S");
    insertaTP("Sentenciasp","WHILE", "Sentenciasp S");
    insertaTP("Sentenciasp","IF",    "Sentenciasp S");
    insertaTP("Sentenciasp","LCURLY","Sentenciasp S");
    //SIG Sentenciasp
    insertaTP("Sentenciasp","RCURLY", "ε");

    //PRIM Tipo
    insertaTP("Tipo","NUM", "NUM");
    insertaTP("Tipo","BOOL","BOOL");

    //PRIM D INVERTIDO
    insertaTP("D","NUM", "Dp Tipo");
    insertaTP("D","BOOL","Dp Tipo");

    //PRIM Dp INVERTIDO
    insertaTP("Dp","ID",      "SEMICOLON ID");
    insertaTP("Dp","LBRACKET","SEMICOLON ID RBRACKET LNUM LBRACKET");

    //PRIM Declaraciones INVERTIDO    
    insertaTP("Declaraciones","NUM", "Declaracionesp");
    insertaTP("Declaraciones","BOOL","Declaracionesp");
    //SIG Declaraciones
    insertaTP("Declaraciones","WHILE", "ε");
    insertaTP("Declaraciones","RCURLY","ε");
    insertaTP("Declaraciones","LCURLY","ε");
    insertaTP("Declaraciones","DO",    "ε");
    insertaTP("Declaraciones","BREAK", "ε");
    insertaTP("Declaraciones","IF",    "ε");
    insertaTP("Declaraciones","ID",    "ε");

    //PRIM Declaracionesp INVERTIDO
    insertaTP("Declaracionesp","NUM", "Declaracionesp D");
    insertaTP("Declaracionesp","BOOL","Declaracionesp D");
    //SIG Declaracionesp
    insertaTP("Declaracionesp","WHILE", "ε");
    insertaTP("Declaracionesp","RCURLY","ε");
    insertaTP("Declaracionesp","LCURLY","ε");
    insertaTP("Declaracionesp","DO",    "ε");
    insertaTP("Declaracionesp","BREAK", "ε");
    insertaTP("Declaracionesp","IF",    "ε");
    insertaTP("Declaracionesp","ID",    "ε");

    //PRIM BLOQUE INVERTIDO
    insertaTP("BLOQUE","LCURLY","RCURLY Sentencias Declaraciones LCURLY");

    //PRIM P
    insertaTP("P","LCURLY","BLOQUE");

    std::stack<std::string> pila;

    pila.push("$");

    pila.push("P");

    int token_contador = 0;

    std::string current = pila.top();

    while( !(current.compare("$") == 0 ) )
    { 
        std::string token = bolsa_token.front();

        auto it = tabla_parseo.find(make_pair(current,token));

        if ( current.compare(token) == 0 )
        {
            bolsa_token.pop();
            pila.pop();
        } 
        else if ( it->second.compare("ε") == 0)
        {
            pila.pop();
        }
        else if ( current.compare("1")==0 || current.compare("2")==0 || current.compare("3")==0 ||
                  current.compare("4")==0 || current.compare("5")==0 || current.compare("6")==0 )
        {
            if (current.compare("1")==0) costo+=10;
            else if (current.compare("2")==0) costo+=5;
            else if (current.compare("3")==0) costo+=10;
            else if (current.compare("4")==0) costo+=25;
            else if (current.compare("5")==0) costo+=50;
            else if (current.compare("6")==0) costo+=15;

            pila.pop();
        }
        else if ( it != tabla_parseo.end() )
        {
            std::stringstream ss( it->second );

            pila.pop();

            while(getline(ss, tokenizer,' ')) 
            { 
                pila.push(tokenizer);
            }
        }
        else
        {
            std::cout << current << '\n';
            std::cout << token << '\n';
            printf("ERROR\n");
            exit(1);
        }
        current = pila.top();
    }

    if ( current.compare(bolsa_token.front()) == 0 )
    {
        //printf("Success\n");
        printf("%d\n",costo);
    }
    else 
    {
        printf("ERROR\n");
        exit(1);
    }

    return 0;
}