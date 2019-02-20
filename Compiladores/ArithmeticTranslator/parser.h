#ifndef PARSER_H
#define PARSER_H

#include <sstream>

class Parser
{
public:
    Parser();
    ~Parser();

    char getLookAhead() const;
    void P();

private:
    void S(const std::string& snext = std::string{""});
    std::string B(const std::string& btrue = std::string{""}, const std::string& bfalse=std::string{""});
    std::string E();
    std::string T();
    std::string F();
    void match(char lookahead);

    char mLookAhead;
    std::stringstream mCode;
    unsigned int mTempCounter  = {0};
    unsigned int mLabelCounter = {0};
};

#endif // PARSER_H
