#include <iostream>
#include "parser.h"

using std::cout;
using std::endl;

int main(int argc, char const* argv[])
{
    Parser parser;
    parser.P();

    if(parser.getLookAhead() != '\n')
    {
        cout << "Parsing failure :(" << endl;
    }
    else
    {
        cout << "Parsing succesfull :)" << endl;
    }

    return 0;
}
