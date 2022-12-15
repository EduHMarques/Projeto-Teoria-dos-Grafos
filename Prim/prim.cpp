#include <iostream>
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

void prim(int fonte, GRAFO g)
{
    priority_queue<pesoVertice, vector<pesoVertice>, greater<pesoVertice> > filaPrioridade;

    int V = g.V;

    vector<bool> pertenceArvore(V, false);
    vector<int> verticePai(V, -1);
    vector<int> vetorPeso(V, oo);

    vetorPeso[fonte] = 0;
    filaPrioridade.push(make_pair(0, fonte));

    while (!filaPrioridade.empty())
    {
        int u = filaPrioridade.top().second;
        filaPrioridade.pop();

        if(pertenceArvore[u] == true)
            continue;

        pertenceArvore[u] = true;

        vector<pair<int, int>>::iterator i;
        for (i = g.adj[u].begin(); i != g.adj[u].end(); i++)
        {
            int v = (*i).first;
            int peso = (*i).second;
 
            if (pertenceArvore[v] == false)
            {
                if (vetorPeso[v] > peso)
                {
                    vetorPeso[v] = peso;
                    verticePai[v] = u;
                    filaPrioridade.push(make_pair(vetorPeso[v], v));
                }
            }
        }
    }

    cout << "Arvore: ";
    for (int i = 1; i < V; i++) {
        printf("(%d,%d) ", verticePai[i], i);
    }

    int custo = 0;
    for (auto& n : vetorPeso)
        custo += n;
    cout << "\nCusto da AGM: " << custo << endl;
}

int main()
{
    int V, E;

    cin >> V;
    cin >> E;

    GRAFO g;
  	g.V = V;
  	g.adj = new vector<pesoVertice>[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.adj[u].push_back(make_pair(v, w));
        g.adj[v].push_back(make_pair(u, w));
    }

    prim(0, g);     // Fonte, grafo

    return 0;
}