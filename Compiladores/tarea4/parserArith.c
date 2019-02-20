#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void E(char* l);
void T(char* l);
void F(char* l);
void match(char* l, char c);

int main()
{
    char l = getchar();
    E(&l);

    if(l == '\n')
    {
        printf("Success\n");
    }
    else
    {
        printf("Error\n");
    }
    return 0;
}

void E(char* l)
{
    T(l);

    while(1)
    {
        if(*l == '+')
        {
            match(l, '+');
            T(l);
        } else if (*l == '-') {
            match(l, '-');
            T(l);
        }
        else if ( *l == ')' || *l == '\n'  )
        {
            return;
        } else {
            printf("Error\n");
            exit(1);
        }
    }
}

void T(char* l)
{
    F(l);

    while(1)
    {
        if(*l == '*')
        {
            match(l, '*');
            F(l);
        }
        else if (*l=='/')
        {
            match(l, '/');
            F(l);
        } 
        else if (*l=='+' || *l=='-' || *l=='\n' || *l==')')
        {
            return;
        }
        else
        {
            printf("Error\n");
            exit(1);
        }
    }
}

void F(char* l)
{
    if(*l == '(')
    {
        match(l, '(');
        E(l);
        match(l, ')');
    }
    else if(isdigit(*l))
    {
        match(l, *l);
    }
    else
    {
        printf("Error\n");
        exit(1);
    }
}

void match(char* l, char c)
{
    if(*l == c)
    {
        *l = getchar();
    }
    else
    {
        printf("Error\n");
        exit(1);
    }
}
