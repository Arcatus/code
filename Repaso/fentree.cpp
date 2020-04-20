#include <bits/stdc++.h> 
using namespace std;

int getSum(int BITree[], int index) 
{ 
    int sum = 0;
    index = index + 1;
    while (index>0) { 
        sum += BITree[index];
        index -= index & (-index); 
    } 
    return sum; 
}
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    while (index <= n) {                                         
        BITree[index] += val; 
        index += index & (-index); 
    } 
} 

int sum(int x, int BITTree1[], int BITTree2[]) 
{ 
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x); 
} 
  
  
void updateRange(int BITTree1[], int BITTree2[], int n, int val, int l, int r) 
{ 
    updateBIT(BITTree1,n,l,val); 
    updateBIT(BITTree1,n,r+1,-val); 
  
    updateBIT(BITTree2,n,l,val*(l-1)); 
    updateBIT(BITTree2,n,r+1,-val*r); 
} 
  
int rangeSum(int l, int r, int BITTree1[], int BITTree2[]) 
{ 
    return sum(r, BITTree1, BITTree2) - sum(l-1, BITTree1, BITTree2); 
} 
  
  
int *constructBITree(int n) 
{ 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    return BITree; 
} 

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> t;
    int n, c;
    while(t--) {
        cin >> n >> c;
        int *BITTree1, *BITTree2; 
        BITTree1 = constructBITree(n);
        BITTree2 = constructBITree(n);
        for(int i=0; i<c; ++i) {
            cin >> opc;
            if ( opc ) {
                cin >> p >> q;
                cout << rangeSum(p,q,BITTree1,BITTree2) << "\n";
            } else {
                cin >> p >> q >> v;
                updateRange(BITTree1,BITTree2,n,v,p,q);
            }
        }
        free(BITTree1);
        free(BITTree2);
    }
    return 0; 
}