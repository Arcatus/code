#include<iostream>
 
int main( ){
    int n;
    std::cin >> n;
 
    int m, temp;
    for(int i = 0; i < n; ++ i){
        int arr[2000], par = 0, impar = 0, op;
 
        std::cin >> m;
        for(int j = 0; j < m; ++ j){
            std::cin >> arr[j];
            if(arr[j] % 2 == 0){
                par += 1;
            }else{
                impar += 1;
            }
        }
        if(impar == 0){
            op = 0;
        }else if(par == 0){
            if(impar % 2 == 0){
                op = 0;
            }else{
                op = 1;
            }
        }else{
            if(impar % 2 != 0){
                op = 1;
            }
        }
 
        if(op == 1) {
            std::cout << "YES" << "\n";
        }else{
            std::cout << "NO" << "\n";
        }
    }
}
