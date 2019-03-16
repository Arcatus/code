#include <cstdio>
#include <cstdlib>
#include <iostream>

void P();
void T();

void match(char c);

std::string s;

int ptr = 0;

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
    {
        ptr = 0;

        std::cin >> s;

        s+="$";
        
        P();

        if( s.compare("Error") == 0)
        {
            printf("NO\n");
        } 
        else if ( s[ptr] == '$' )
        {
            printf("SI\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}

void P()
{
    T();

    while(1)
    {
        if(s[ptr]=='(' || s[ptr]=='[' || s[ptr] == '{')
        {
            T();
        }
        else if ( s[ptr] == '$' || s[ptr] == '}' ||  s[ptr] == ')' || s[ptr] == ']')
        {
            return;
        }
        else
        {
            s = "Error";
            return;
        }
    }
}

void T()
{
    if(s[ptr] =='(')
    {
        match('(');
        P();
        match(')');
    }
    else if(s[ptr]=='[')
    {
        match('[');
        P();
        match(']');
    }
    else if(s[ptr]=='{')
    {
        match('{');
        P();
        match('}');
    }
    else if(s[ptr] == '$' || s[ptr] == ')' || s[ptr] == '}' || s[ptr] == ']')
    {
        return;
    }
    else 
    {
        s = "Error";
        return;
    }
}

void match(char c)
{
    if ( s[ptr] == c )
    {
        ptr++;
    } 
    else 
    {
        s = "Error";
        return;
    }
}