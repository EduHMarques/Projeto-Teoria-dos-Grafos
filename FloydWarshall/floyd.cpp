#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matriz;
typedef vector<int> Lista;

#define oo 999 // representa infinito

void Solucao(Matriz matriz, Matriz resultado, int V)
{
    cout << "\nMatriz de adjacencia inicial:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz solucao:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }
}

void Floyd(int V, Matriz matriz)
{
    Matriz resultado(V, Lista(V));

    // Copia e cola a matriz na matriz de resultado para comparar no final.
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++)
            resultado[i][j] = matriz[i][j];

    // Algoritmo.
    for (int k = 0; k < V; k++) 
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (resultado[i][j] > resultado[i][k] + resultado[k][j])
                    resultado[i][j] = resultado[i][k] + resultado[k][j];
    
    // Custo O(n^3)
    Solucao(matriz, resultado, V);
}

int main()
{
    int V, E;
    
    cin >> V;
    cin >> E;

    Matriz adj;

    // Preenche inicialmente a matriz
    for (int i = 0; i < V; ++i) 
    {
        Lista lista(V);

        for (int j = 0; j < V; ++j)
        {
            if (i == j) // Diagonal principal nula
                lista[j] = 0;
            else // Infinito nas arestas não definidas
                lista[j] = oo;
        }
        adj.push_back(lista); // Insere a lista na posição i
    }

    // Input de arestas
    for (int i = 0; i < E; i++) 
    {
        int u, v, e;
        
        cin >> u >> v >> e;
        
        adj[u][v] = e;
    }

    Floyd(V, adj);

    return 0;
}