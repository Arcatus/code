#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std; 

vector<int> adj[100001];
vector<int> alcanzable;
vector<bool> visited;
vector<int> res;

int vertices, arcos;

void topoLex() 
{    
    for (int i = 0; i < vertices; i++) {
        if (alcanzable[i] == 0 && !visited[i])
        {
            vector<int>::iterator j;
            for (j = adj[i].begin(); j != adj[i].end(); j++) 
                alcanzable[*j]--;
            res.push_back(i);
            visited[i] = true;
            topoLex();
        }
    }
}

int main() 
{
    scanf("%d",&vertices);
    scanf("%d",&arcos);

    int x, y;
    for (int i=0;i<arcos;++i)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        alcanzable[y]++;
    }
    topoLex();

    return 0; 
}