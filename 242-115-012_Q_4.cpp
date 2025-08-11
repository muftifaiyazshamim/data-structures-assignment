#include <iostream>
using namespace std;

// Recursive DFS function
void DFS(int node, int adjList[50][50], int listSize[50], bool visited[50])
{
    visited[node] = true;    // mark current node as visited
    cout << node << " ";     // process current node

    // visit all neighbours
    for (int i = 0; i < listSize[node]; i++)
    {
        int neighbour = adjList[node][i];
        if (!visited[neighbour])
        {
            DFS(neighbour, adjList, listSize, visited);
        }
    }
}

int main()
{
    int V, E; // vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    int adjList[50][50];   // adjacency list using arrays
    int listSize[50] = {0}; // keeps size of each list

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u][listSize[u]++] = v;
        adjList[v][listSize[v]++] = u; // undirected
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    bool visited[50] = {false}; // visited tracking array
    cout << "DFS order: ";
    DFS(start, adjList, listSize, visited);
    cout << endl;

    return 0;
}

