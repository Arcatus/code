#include <iostream>

using namespace std; 

int a(int n);
int b(int n);
  
int a(int n) 
{ 
    if (n == 0) {
        return 1;
    } else if (n == 1){
        return 0;
    } else 
    {
        return a(n-2) + 2*b(n-1);
    }
} 

int b(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1){
        return 1;
    } else 
    {
        return a(n-1) + b(n-2);
    }
}
  
int main() 
{ 
    int n;
    cin >> n;
    cout << a(n) << '\n'; 
    return 0; 
}