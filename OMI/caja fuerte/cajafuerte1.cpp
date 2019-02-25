#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define mod 1997
char ini[3001][3001];
char fin[3001][3001];
int ar1[15000],ar2[15000],pot[15000];
int h,o,n,POT=29;

 int genera(int pos)
  {
    int key=0;
    for(int r=0;r<o;r++)
      key=(key+(ar2[(pos+r)%o]*pot[o-1-r])%mod)%mod;         
    return key;
  }
 int genera2(int pos)
  {
    int key=0;
    for(int r=0;r<h;r++)
      key=(key+(ar1[(pos+r)%o]*pot[o-1-r])%mod)%mod;         
    return key;
  }  
 bool igual(int pos)
 {
    for(int r=0;r<h;r++)     
    if( ar1[r]!=ar2[(pos+r)%h] )
     return false;
   return true;
 }

int compara()
{
    int res=100000;
  int key=genera(0),key2=genera2(0);
  //printf("%d %d\n",key,key2);
   if( key==key2 )
       if(igual(0))             
        res=0;
   if(res)
  for(int r=1;r<o;r++)
   {
      key=(key-(ar2[(r+o-1)%o]*pot[o-1])%mod+mod)%mod;    
      key=(key*POT)%mod;       
      key=(key+ar2[ (r+o-1)%o ])%mod;     
     if( key==key2)
       if(igual(r))             
        res=min(r,h-r);
       // printf("%d %d\n",key,key2);
   }
  return res;
}
int main()
{
  //  freopen("Caso0.ent","r",stdin);
  //  freopen("ouput.txt","w",stdout);
    scanf("%d",&n);
    for(int r=0;r<n;r++)
     scanf("%s",ini[r]);
    for(int r=0;r<n;r++)
     scanf("%s",fin[r]);     
    int temp=1;
    for(int r=0;r<n*4;r++)     
    {
       pot[r]=temp;
       temp=(temp*POT)%mod;        
    }
     int res=0;
   for(int j=0;j<n/2;j++)
    {
       h=o=0;
      for(int r=0;r<n-j*2-1;r++)                 
       ar1[h++]=ini[j][j+r]-'a';
      for(int r=0;r<n-j*2-1;r++)                 
       ar1[h++]=ini[j+r][n-1-j]-'a';
      for(int r=0;r<n-j*2-1;r++)                 
       ar1[h++]=ini[n-j-1][n-j-1-r]-'a';
      for(int r=0;r<n-j*2-1;r++)                 
       ar1[h++]=ini[n-j-1-r][j]-'a';
       
      for(int r=0;r<n-j*2-1;r++)                 
       ar2[o++]=fin[j][j+r]-'a';
      for(int r=0;r<n-j*2-1;r++)                 
       ar2[o++]=fin[j+r][n-1-j]-'a';
      for(int r=0;r<n-j*2-1;r++)                 
       ar2[o++]=fin[n-j-1][n-j-1-r]-'a';
      for(int r=0;r<n-j*2-1;r++)                 
       ar2[o++]=fin[n-j-1-r][j]-'a';      
      res+= compara();
    }
    printf("%d",res);
}