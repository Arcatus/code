#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <vector>
#include <locale>

std::string temporaly, symbTrans;
unsigned int n_linea = 1; 
bool new_line = true, special_case2 = true,
                      special_case3 = false;

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

bool dfaStart(DFA* dfa, std::istream& inputStream, int currentAutomata)
{
    unsigned int currentState = dfa->startingState;

    temporaly = "";

    while(inputStream.good())
    {
        char symbol = inputStream.get();

        switch(currentAutomata){
            case 1: {
                if ( isalpha(symbol) > 0 ){
                    symbTrans = "letra"; temporaly+=symbol;
                } else if ( isdigit(symbol) > 0 ){
                    symbTrans = "digit"; temporaly+=symbol;
                } else if ( symbol == '_') {
                    symbTrans = "guion"; temporaly+=symbol;
                } else {
                    symbTrans = symbol;
                } 
                break;
            }

            case 2: {
                if ( isdigit(symbol) > 0 ){
                    symbTrans = "digit"; 
                } else if ( symbol == '-') {
                    symbTrans = "signo";
                    symbol = inputStream.get();
                    if( ! ( isdigit(symbol) > 0 ) ){
                        inputStream.putback(symbol);
                        inputStream.putback('-');
                        if(currentState==2 || currentState==4) return true;
                        return false;
                    }else inputStream.putback(symbol);
                } else if ( symbol == '.'){
                    symbTrans = "punto"; 
                } else if ( symbol == 'e'){
                    symbTrans = "e";
                } else {
                    symbTrans = symbol;
                }
                break;
            }
            case 3: {

                if (symbol=='=' && special_case2 && currentState == 0 ){
                    special_case2 = false;
                    symbTrans = symbol;
                    symbol = inputStream.get();
                    if(symbol != '=' ){
                        inputStream.putback(symbol);
                        temporaly = "=";
                        special_case2 = true;
                        return true;
                    } else {
                        inputStream.putback(symbol);
                        symbol = '=';
                    }
                } else {
                    symbTrans = symbol;
                    special_case2 = true;
                } 
                break;
            }
            case 7: {
                if (symbol=='(' || symbol==')' || symbol=='{' || symbol=='}' ||
                    symbol=='[' || symbol==']'){
                    temporaly = symbol;
                    return true;
                }else {
                    symbTrans = symbol;
                }
                break;
            }
            default: symbTrans = symbol; break;
        }

        std::pair<unsigned int, std::string> transition = { currentState, symbTrans };

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

        currentState = dfa->transitionTable[transition];
    }

    if(dfa->finalStates.count(currentState) > 0)
    {
        return true;
    }
    return false;
}

int main(void)
{

	DFA dfa_id_reserved, dfa_blanks, dfa_num, 
                    dfa_opr, dfa_opa, dfa_log, dfa_asg, dfa_agr, dfa_scl;

    std::istream& inputStream(std::cin);

    std::set<std::string> tabla_sintactica;
    std::map<std::string, std::string> agrupadores;
/*
    std::vector<std::string> reservedWords = 
                {"ELSE","else","IF","if","DO","do","WHILE","while","BREAK","break",
                 "NUM","num","BOOL","bool","TRUE","true","FALSE","false"};
*/
    std::vector<std::string> reservedWords = 
                {"else","if","do","while","break","num","bool","true","false"};

    agrupadores.emplace("{","LCURLY");
    agrupadores.emplace("}","RCURLY");
    agrupadores.emplace("(","LPAR");
    agrupadores.emplace(")","RPAR");
    agrupadores.emplace("[","LBRACKET");
    agrupadores.emplace("]","RBRACKET");

    tabla_sintactica.insert( reservedWords.begin(), reservedWords.end() );

    dfaAddTransition(&dfa_blanks, 0, "\t", 1);
    dfaAddTransition(&dfa_blanks, 0, " " , 1);
    dfaAddTransition(&dfa_blanks, 1, "\t", 1);
    dfaAddTransition(&dfa_blanks, 1, " " , 1);

    dfaAddFinalState(&dfa_blanks, 1);

	dfaAddTransition(&dfa_id_reserved,0,"letra",1);
	dfaAddTransition(&dfa_id_reserved,0,"guion",1);
	dfaAddTransition(&dfa_id_reserved,1,"guion",1);
	dfaAddTransition(&dfa_id_reserved,1,"letra",1);
	dfaAddTransition(&dfa_id_reserved,1,"digit",1);

    dfaAddFinalState(&dfa_id_reserved, 1);

    dfaAddTransition(&dfa_num,0,"signo",1);
    dfaAddTransition(&dfa_num,0,"digit",2);
    dfaAddTransition(&dfa_num,1,"digit",2);
    dfaAddTransition(&dfa_num,2,"digit",2);
    dfaAddTransition(&dfa_num,2,"punto",3);
    dfaAddTransition(&dfa_num,2,  "e"  ,0);
    dfaAddTransition(&dfa_num,3,"digit",4);
    dfaAddTransition(&dfa_num,4,"digit",4);
    dfaAddTransition(&dfa_num,4,  "e"  ,0);

    dfaAddFinalState(&dfa_num, 2);
    dfaAddFinalState(&dfa_num, 4);

    dfaAddTransition(&dfa_opr,0, "<", 1);
    dfaAddTransition(&dfa_opr,0, ">", 4);
    dfaAddTransition(&dfa_opr,0, "=", 7);
    //dfaAddTransition(&dfa_opr,0, "!",10);
    dfaAddTransition(&dfa_opr,1, "=", 2);
    dfaAddTransition(&dfa_opr,4, "=", 5);
    dfaAddTransition(&dfa_opr,7, "=", 8);
    //dfaAddTransition(&dfa_opr,10,"=",11);

    dfaAddFinalState(&dfa_opr, 1);
    dfaAddFinalState(&dfa_opr, 2);
    dfaAddFinalState(&dfa_opr, 4);
    dfaAddFinalState(&dfa_opr, 5);
    dfaAddFinalState(&dfa_opr, 7);
    dfaAddFinalState(&dfa_opr, 8);
    //dfaAddFinalState(&dfa_num,11);

    dfaAddTransition(&dfa_opa,0, "+", 1);
    dfaAddTransition(&dfa_opa,0, "-", 1);
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

    dfaAddTransition(&dfa_agr,0, "agrup", 1);
    dfaAddTransition(&dfa_agr,1, "agrup", 1);

    dfaAddFinalState(&dfa_agr, 1);

    dfaAddTransition(&dfa_scl,0, ";", 1);

    dfaAddFinalState(&dfa_scl, 1);

    auto toUpper = []( std::string str ){
        std::locale loc;
        for (std::string::size_type i = 0; i < str.length(); ++i)
        std::cout << std::toupper(str[i],loc);
        std::cout << ' ';
    };

    char symbol;

    while(inputStream.good())
    {
        if(new_line){
            new_line = false;
            dfaStart(&dfa_blanks,inputStream, 0);
            symbol = inputStream.get();
            if (symbol=='\n'){
                n_linea++;
                new_line = true;
                continue;
            } else {
                std::cout<<n_linea << ' ';
                inputStream.putback(symbol);
            }
        }
        
        dfaStart(&dfa_blanks,inputStream, 0);
    
        if ( dfaStart(&dfa_id_reserved, inputStream, 1 ) ){
            if(tabla_sintactica.count(temporaly) > 0) toUpper(temporaly);
            else std::cout << "ID ";
        } else if ( dfaStart(&dfa_num, inputStream, 2) ){
            std::cout << "LNUM ";
        } else if ( dfaStart(&dfa_opr, inputStream, 3) ){
            if (temporaly.compare("=")==0){
                std::cout << "ASSIGN ";
            } else std::cout << "RELOP ";
        } else if ( dfaStart(&dfa_opa, inputStream, 4) ){
            std::cout << "ARITHOP ";
        } else if ( dfaStart(&dfa_log, inputStream, 5) ){
            std::cout << "LOGOP ";
        } else if ( dfaStart(&dfa_agr , inputStream, 7) ){
            std::cout << agrupadores[temporaly] << ' ';
        } else if ( dfaStart(&dfa_scl, inputStream, 6) ){
            std::cout << "SEMICOLON ";
        } else if ( inputStream.get() == '\n' ){
            n_linea++;
            new_line = true; 
            std::cout << '\n';

        } else if ( inputStream.get() != -1 ){
            std::cout << "\nERROR LINE " << n_linea << std::endl;
            return 0;
        }
    }
	return 0;
}