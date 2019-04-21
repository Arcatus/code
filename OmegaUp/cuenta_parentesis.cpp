#include <cstdio>

using namespace std;

void P();
void T();

char a;

int longitud, cuenta_cadenas;
int max_longitud=0;

void match(char c);

int main() 
{

    while (scanf("%c",&a)==1)
    {
        longitud=0;
        P();
        if( longitud > max_longitud ) {
            max_longitud = longitud;
            cuenta_cadenas = 1;
        }
        else if ( longitud == max_longitud )
        {
            cuenta_cadenas++;
        }
    }

    if (  )
    {
        printf("0 1\n");
    }   
    else
    {
        printf("%d %d\n",max_longitud, cuenta_cadenas);
    }    
    
    return 0;
}

void P()
{
    T();

    while(1)
    {
        if(a=='(') {
            T();
        }
        else if ( a == ')' || a == '\n') {
            return;
        }
        else
        {
            return;
        }
    }
}

void T()
{
    if(a =='(') {
        match('(');
        P();
        match(')');
    }
    else if(a == ')' || a == '\n') {
        return;
    }
    else 
    {
        return;
    }
}

void match(char c)
{
    if ( a == c )
    {
        if ( scanf("%c",&a) != 1);
        {
            a = '\n';
        }
        longitud++;
    } 
    else 
    {
        longitud = 0;
        return;
    }
}