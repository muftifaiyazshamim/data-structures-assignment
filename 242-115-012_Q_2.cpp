#include <iostream>
using namespace std;

int main()
{
    int V, E; // number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // --- Adjacency Matrix ---
    int matrix[50][50] = {0}; // matrix initialized to 0
    // --- Adjacency List ---
    int adjList[50][50];      // each row represents a vertex, columns store neighbours
    int listSize[50] = {0};   // keeps track of number of neighbours for each vertex

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // Fill adjacency matrix
        matrix[u][v] = 1;
        matrix[v][u] = 1; // assuming undirected graph

        // Fill adjacency list
        adjList[u][listSize[u]++] = v; // store v in u's list
        adjList[v][listSize[v]++] = u; // store u in v's list
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Display adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < listSize[i]; j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
