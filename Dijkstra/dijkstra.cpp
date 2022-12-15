#include <bits/stdc++.h>
#include <queue>
#include<vector>
using namespace std;
#define oo 999

typedef pair<int, int> pesoVertice;           // Par que armazena peso e vértice

typedef struct Grafo
{
    int V;
    vector<pair<int, int> >* adj;
} GRAFO;

void dijkstra(int fonte, GRAFO g)
{
    priority_queue<pesoVertice, vector<pesoVertice>, greater<pesoVertice> > filaPrioridade;

    int V = g.V;
 
    vector<int> distancias(V, oo);
 
    auto par = make_pair(0, fonte);
    filaPrioridade.push(par);

    distancias[fonte] = 0;
 
    while (!filaPrioridade.empty()) 
    {
        int u = filaPrioridade.top().second;
        filaPrioridade.pop();
 
        vector<pair<int, int>>::iterator i;
        for (i = g.adj[u].begin(); i != g.adj[u].end(); ++i) 
        {
            int v = (*i).first;
            int peso = (*i).second;
 
            if (distancias[v] > distancias[u] + peso) 
            {
                distancias[v] = distancias[u] + peso;
                par = make_pair(distancias[v], v);
                filaPrioridade.push(par);
            }
        }
    }

    // Mudar o print
    cout << "Distancias da fonte (" << fonte << ") ao vertice: \n";
    for (int i = 0; i < V; ++i) {
        cout << fonte << " -> " << i << ": " << distancias[i] << endl;
    }
}
 
int main()
{
    int V;
    int E;

    cin >> V >> E;

    GRAFO g;
  	g.V = V;
  	g.adj = new vector<pesoVertice>[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.adj[u].push_back(make_pair(v, w));
    }

    dijkstra(0, g);     // Fonte, grafo
 
    return 0;
}