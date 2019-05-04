#include <iostream> 
#include <vector>
#include <list>

using namespace std; 
  
class Graph 
{ 
    int V;
    vector<int> *adj;
    
    vector<int> alcanzable;

    void alltopologicalSortUtil(vector<int>& res, bool visited[]);
  
public: 
    Graph(int V);
    void addEdge(int v, int w); 
    void alltopologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V;
    adj = new vector<int>[V]; 
  
    for (int i = 0; i < V; i++) 
        alcanzable.push_back(0); 
} 

void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);    
    alcanzable[w]++;
} 
  
void Graph::alltopologicalSortUtil(vector<int>& res, bool visited[]) 
{    
    for (int i = 0; i < V; i++) 
    {
        if (alcanzable[i] == 0 && !visited[i])
        { 
            vector<int>::iterator j;
            for (j = adj[i].begin(); j != adj[i].end(); j++) 
                alcanzable[*j]--;

            res.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(res, visited);
        }
    }
    
    if (res.size()==0) {
        cout << "-1" << '\n';
    }
    else {
        for (int i = 0; i < res.size(); i++) 
            cout << res[i] << " ";
        cout<<'\n';
    }
    exit(0);
} 

void Graph::alltopologicalSort() 
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) visited[i] = false;
    vector<int> res;
    alltopologicalSortUtil(res, visited); 
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int vertices, arcos;

    cin >> vertices >> arcos;

    Graph g(vertices);

    int x, y;
    for (int i=0;i<arcos;++i)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }
  
    g.alltopologicalSort(); 
  
    return 0; 
} 