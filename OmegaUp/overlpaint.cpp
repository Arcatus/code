
#include<bits/stdc++.h>  
using namespace std;  

struct Interval  
{  
    int s, e;  
};  

bool mycomp(Interval a, Interval b)  
{ 
    return a.s < b.s; 
}  
  
void mergeIntervals(Interval arr[], int n)
{  
    sort(arr, arr+n, mycomp);  
  
    int index = 0;
    for (int i=1; i<n; i++) {
        if (arr[index].e >=  arr[i].s) {  
            arr[index].e = max(arr[index].e, arr[i].e);  
        }  
        else { 
            arr[++index] = arr[i];  
        }     
    }

    cout << "\n The Merged Intervals are: ";  
    for (int i = 0; i <= index; i++)  
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";  
    cout << '\n';
}

int main()  
{  
    Interval arr[] = { {1,100}, {110,120}, {100,110}, {10,17} };
    int n = sizeof(arr)/sizeof(arr[0]);  
    mergeIntervals(arr, n);  
    return 0;  
} 