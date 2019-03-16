#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>

using std::queue;
using std::string;

void S(std::string& l);
void P(std::string& l);
void match(std::string& l,std::string l2);

queue<string> token;

/*
    S -> P S 
    P -> ↑ S ↓
*/

int main()
{
    string token;
    std::cin >> token;

    S(token);

    if(token.compare("$") == 0)
    {
        printf("Success\n");
    }
    else
    {
        printf("Error\n");
    }
    return 0;
}

void S(std::string& token)
{
    if (token.compare("↑") == 0)
    {
        P(token);
        S(token);
    } 
    else if ( token.compare("$") == 0 || token.compare("↓") == 0 )
    {
        return;
    }
    else
    {
        std::cout << token;
        printf("Error\n");
        exit(1);
    }
}

void P(std::string& token)
{
    if (token.compare("↑") == 0)
    {
        match(token,"↑");
        S(token);
        match(token,"↓");
    }
    else
    {
        printf("Error\n");
        exit(1);
    }
}

void match(std::string& token,std::string token2)
{
    if( token.compare(token2) == 0)
    {
        std::cin >> token;
    }
    else
    {
        printf("Error\n");
        exit(1);
    }
}
