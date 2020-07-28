#include<iostream>

int main( ){
    int n;
    std::cin >> n;
    int arr[100000];
    for(int i = 0; i < n; ++ i){
        std::cin >> arr[i];
    }

    int alice[100000];
    int bob[100000];

    int acum = 0;
    for(int i = 0; i < n; ++ i){
        acum += arr[i];
        alice[i] = acum;
    }
    acum = 0;
    for(int i = n - 1; i >= 0; -- i){
        acum += arr[i];
        bob[i] = acum;
    }

    int canta = 0, cantb = 0;
    for(int i = 0; i < n; ++ i){
        if(alice[i] < bob[i] || alice[i] == bob[i]){
            canta += 1;
        }else{
            cantb += 1;
        }
    }
    std::cout << canta << " " << cantb;
}
