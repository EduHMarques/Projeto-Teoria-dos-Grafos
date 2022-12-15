#include <iostream>
#include <vector>

using namespace std;

#define oo 999

typedef struct Aresta
{
    int origem, destino, peso;
} ARESTA;

typedef struct Grafo
{
    int V;
    vector<ARESTA> lista_adj;
} GRAFO;

// Printar a solução
void Solucao(vector<int> distancias, int V, int fonte)
{
    cout << "\nDistancias da fonte (" << fonte << ") ao vertice: \n";
    for (int i = 0; i < V; ++i)
        cout << fonte << " -> " << i << ": " << distancias[i] << endl;
}

// Algoritmo de Bellman-Ford
void BellmanFord(GRAFO grafo, int fonte)
{
    int V = grafo.V;
    int E = grafo.lista_adj.size();

    vector<int> distancias(V);

    // Inicializa a distância do vértice fonte para todos os outros (com 0 arestas).
    for (int i = 0; i < V; i++)
        distancias[i] = oo;
    
    distancias[fonte] = 0;

    for (int i = 1; i <= V - 1; i++)
        for (int k = 0; k < E; k++)
        {
            int u = grafo.lista_adj[k].origem;
            int v = grafo.lista_adj[k].destino;
            
            int peso = grafo.lista_adj[k].peso;

            if (distancias[u] != oo && distancias[u] + peso < distancias[v])
                distancias[v] = distancias[u] + peso;
        }

    Solucao(distancias, V, fonte);
}

int main()
{
    int V;
    int E;

    cin >> V >> E;

    GRAFO g;
    g.V = V;

    for (int i = 0; i < E; i++)
    {
        int origem, destino, peso;
        
        cin >> origem;
        cin >> destino;
        
        cin >> peso;

        ARESTA a;
        
        a.origem = origem;
        a.destino = destino;
        
        a.peso = peso;
        
        g.lista_adj.push_back(a);
    }

    BellmanFord(g, 0);

    return 0;
}