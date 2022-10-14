#include <iostream>
#include <vector>

using namespace std;

int contador;
vector<int> grau;
vector<int> compConexa;
int numCompConexas;

void DFSrec (vector<vector<int>> &adj, int vert)
{
    grau[vert] = contador++;
    compConexa[vert] = numCompConexas;
    int numVizinhos = adj[vert].size();

    for (int i = 0; i < numVizinhos; i++)
    {
        int vizinho = adj[vert][i];
        if(grau[vizinho] == -1)
            DFSrec(adj, vizinho);
    }
}

void DFS (vector<vector<int>> &adj)
{
    contador = 0;
    int n = adj.size();

    for (int vert = 0; vert < n; vert++)
    {
        if (grau[vert] == -1)
        {
            DFSrec(adj, vert);
            numCompConexas++;
        }
    }
}

int main()
{
    int numVertices, numArestas;
    numCompConexas = 0;

    cin >> numVertices >> numArestas;
    grau = vector<int>(numVertices, -1);
    compConexa = vector<int>(numVertices, -1);

    vector<vector<int>> listaAdjacencia(numVertices, vector<int>(0));

    int u, v;
    for (int i = 0; i < numArestas; i++)
    {
        cin >> u >> v;
        listaAdjacencia[u].push_back(v);
        listaAdjacencia[v].push_back(u);
    }

    // for (int i = 0; i < numVertices; i++)
    // {
    //     int arestas = listaAdjacencia[i].size();
    //     cout << "Vertice " << i << ": " << arestas << " arestas\n";
    // }

    DFS(listaAdjacencia);

    cout << "Grafo G percorrido, possuindo " << numCompConexas << " componentes conexas, e:\n";
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertice " << i << ". Visita: " << grau[i] << ". Componente conexa: " << compConexa[i] << endl; 
    }

    return 0;
}