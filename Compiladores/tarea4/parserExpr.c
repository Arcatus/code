#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void S(char* l);
void T(char* l);
void F(char* l);
void G(char* l);

void match(char* l, char c);

int main()
{
    char l = getchar();
    S(&l);

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

void S(char* l)
{
    T(l);

    while(1)
    {
        if(*l == '|')
        {
            match(l, '|');
            T(l);
        } 
        else if ( *l == '\n' || *l == ')'  )
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
        if ( *l=='(' || *l=='a' || *l=='b' )
        {   
            F(l);
        } else if( *l == '|' || *l == '\n' || *l==')' ) {
            return;
        } else {
            printf("Error\n");
            exit(1);   
        }
    }
}

void F(char* l)
{
    G(l);

    while(1)
    {
        if(*l == '*')
        {
            match(l, '*');
        } 
        else if ( *l=='(' || *l=='a' || *l=='b' || *l=='|' ||*l=='\n' ||*l==')' )
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

void G(char* l)
{
    if(*l == '(')
    {
        match(l, '(');
        S(l);
        match(l, ')');
    }
    else if(*l=='a' || *l=='b')
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
