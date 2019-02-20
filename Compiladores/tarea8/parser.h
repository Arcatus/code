#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <utility>
#include <queue>
#include <cctype>
#include <map>
#include <set>

using std::string;
using std::pair;
using std::queue;

typedef std::map< unsigned int , std::pair<string,string> > typeTable;
typedef std::pair<std::string,std::string> pss;
typedef std::set<std::pair<std::string,std::string>> spss;
typedef std::queue< std::pair<std::string,unsigned int>> qpss;
typedef std::map<std::pair<std::string,std::string>,std::string> mapss;
typedef std::map<std::string,std::string> mss;

#define debug_semantic(X,Y) std::cout<<"Type(1): "<<X<<" Type(2): "<<Y<<'\n'

class Parser
{
public:
	Parser();
	Parser(qpss& t);
	~Parser();

	string getToken() const;
	void P();
	void connect(typeTable& ts);
	void printTablaSimbolos();

	bool semanticEnable;
	
private:
	void        Bloque();	
	void Declaraciones();	
	void             D();	
	pss           Tipo(); 
	void    Sentencias(); 
	void             S(const string& snext = std::string{""});	
	void            Sp(const string& snext = std::string{""},const string& bfalse = std::string{""});	
	pss           	 L();	
	pss           	 B(const std::string& btrue = std::string{""}, const std::string& bfalse=std::string{""});	
	pss           	 R(const std::string& btrue = std::string{""}, const std::string& bfalse=std::string{""});	
	pss           	 E();	
	pss           	 T();	
	pss           	 F();

	unsigned int mTempCounter  = {0};
    unsigned int mLabelCounter = {0};

	void match(string cmp);
	void avanzarEntrada();

	qpss bolsa_token;
	pair<string,unsigned int> token;

	std::stringstream mCode;

	mapss tabla_inferencia_Mult;
	mapss tabla_inferencia_Arith;
	mapss tabla_inferencia_Relop;
    mapss tabla_inferencia_Logop;
    bool lvalue;

    typeTable tabla_simbolos;

    spss tabla_asign_valida;
};

#endif // PARSER_H