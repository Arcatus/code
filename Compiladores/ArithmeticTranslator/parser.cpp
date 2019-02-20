#include <cstdlib>
#include <iostream>
#include <cctype>
#include <fstream>

#include "parser.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::to_string;

Parser::Parser()
{
    cin.read(&mLookAhead, 1);
}

Parser::~Parser()
{
}

char Parser::getLookAhead() const
{
    return mLookAhead;
}

void Parser::P()
{
    string snext = "L" + to_string(mLabelCounter);
    mLabelCounter++;

    S(snext);

    // Put label
    mCode << snext << ": ";

    ofstream outputStream("three_address_code.txt");
    outputStream << mCode.str();
    outputStream.close();
}

void Parser::S(const std::string& snext)
{
    if(mLookAhead == 'a' || mLookAhead == 'b' || mLookAhead == 'c')
    {
        char id = mLookAhead;

        match(mLookAhead);
        match('=');

        string eAddress = E();

        match(';');

        mCode << id << "=" << eAddress << endl;
    }
    else if(mLookAhead == 'i')
    {
        match('i');
        match('f');
        match('(');

        // New label
        string btrue = "L" + to_string(mLabelCounter);
        mLabelCounter++;

        B(btrue, snext);

        // Put label
        mCode << btrue << ": ";

        match(')');
        S();
    }
    else
    {
        cout << "Syntax error" << endl;
        exit(1);
    }
}

string Parser::B(const std::string& btrue, const std::string& bfalse)
{
    string e1Address = E();

    while(true)
    {
        if(mLookAhead == '<')
        {
            match('<');

            string e2Address = E();

            mCode << "if " << e1Address << "<" << e2Address << "goto " << btrue << endl <<
                     "goto " << bfalse << endl;
        }
        else
        {
            return e1Address;
        }
    }
}

string Parser::E()
{
    string tAddress = T();

    while(true)
    {
        if(mLookAhead == '+')
        {
            string temp = "t" + to_string(mTempCounter);
            mTempCounter++;

            match('+');

            string t1Address = T();
            mCode << temp << "=" << tAddress << "+" << t1Address << endl;

            tAddress = temp;
        }
        else
        {
            return tAddress;
        }
    }
}

string Parser::T()
{
    string fAddress = F();

    while(true)
    {
        if(mLookAhead == '*')
        {
            string temp = "t" + to_string(mTempCounter);
            mTempCounter++;

            match('*');

            string f1Address = F();
            mCode << temp << "=" << fAddress << "*" << f1Address << endl;

            fAddress = temp;
        }
        else
        {
            return fAddress;
        }
    }
}

string Parser::F()
{
    string fAddress;

    if(mLookAhead == '(')
    {
        match('(');
        fAddress = E();
        match(')');
    }
    else if(isdigit(mLookAhead))
    {
        fAddress = mLookAhead;
        match(mLookAhead);
    }
    else
    {
        cout << "Syntax Error." << endl;
        exit(1);
    }

    return fAddress;
}

void Parser::match(char t)
{
    if(mLookAhead == t)
    {
        cin.read(&mLookAhead, 1);
    }
    else
    {
        cout << "Syntax Error." << endl;
        exit(1);
    }
}
