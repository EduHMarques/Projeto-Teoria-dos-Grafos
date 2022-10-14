#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numVertices, numArestas;

    cin >> numVertices >> numArestas;

    vector<vector<int>> listaAdjacencia(numVertices, vector<int>(0));

    int u, v;
    for(int i = 0; i < numArestas; i++)
    {
        cin >> u >> v;
        listaAdjacencia[u].push_back(v);
        listaAdjacencia[v].push_back(u);
    }

    cout << "Hello World!" << endl; 

    return 0;
}