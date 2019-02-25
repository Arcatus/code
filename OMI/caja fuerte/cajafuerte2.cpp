#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
char ma[23002][3002];
char me[3002][3002];
vector<char> z[2002];
vector<char> zz[2002];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int mod=1997;
int p=29;


int pw(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a%mod;
    int temp=pw(a,b/2)%mod;
    if(b%2)
        return ((temp*temp)%mod*a)%mod;
    return (temp*temp)%mod;
}

int hash(vector<char>&s)
{
    int cont=0;
    for(int i=0;i<s.size();i++)
    {
        cont=(cont+(s[i]-'a')*pw(p,s.size()-1-i))%mod;
    }
    return cont%mod;
}

bool comp(int id,int pos)
{
    bool ok=true;
    for(int i=0;i<z[id].size();i++)
    {
        if(z[id][(pos+i)%z[id].size()]!=zz[id][i])
        {
            ok=false;
            break;
        }
    }
    return ok;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",ma[i]);
    }
    int x,y;
    for(int i=0;i<n/2;i++)
    {
        x=y=i;
        for(int j=0;j<4;j++)
            for(int k=0;k<n-(2*i)-1;k++)
            {
                z[i].push_back(ma[y][x]);
                y+=dy[j];
                x+=dx[j];
            }
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",me[i]);
    }
    for(int i=0;i<n/2;i++)
    {
        x=y=i;
        for(int j=0;j<4;j++)
            for(int k=0;k<n-(2*i)-1;k++)
            {
                zz[i].push_back(me[y][x]);
                y+=dy[j];
                x+=dx[j];
            }
    }
    
    int cont=0;
    for(int i=0;i<n/2;i++)
    {
        for(int k=0;k<=z[i].size()/2;k++)
        {
            if(comp(i,k) || comp(i,z[i].size()-k))
            {
                //printf("%d %d\n",k,z[i].size()-k);
                cont+=k;
                break;
            }
        }
    }
    
    printf("%d",cont);
    
}
