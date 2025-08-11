#include <iostream>
using namespace std;

// BFS function using array-based queue
void BFS(int start, int adjList[50][50], int listSize[50], int V)
{
    bool visited[50] = {false}; // track visited vertices
    int queue[50];              // array to act as queue
    int front = 0, rear = 0;    // queue pointers

    visited[start] = true;      // mark start vertex as visited
    queue[rear++] = start;      // enqueue start vertex

    cout << "BFS order: ";
    while (front < rear)        // while queue is not empty
    {
        int node = queue[front++]; // dequeue
        cout << node << " ";

        // Explore all neighbours
        for (int i = 0; i < listSize[node]; i++)
        {
            int neighbour = adjList[node][i];
            if (!visited[neighbour])   // if neighbour not visited
            {
                visited[neighbour] = true;
                queue[rear++] = neighbour; // enqueue neighbour
            }
        }
    }
    cout << endl;
}

int main()
{
    int V, E; // vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    int adjList[50][50];  // adjacency list array
    int listSize[50] = {0}; // size of each list

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u][listSize[u]++] = v;
        adjList[v][listSize[v]++] = u; // undirected
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    BFS(start, adjList, listSize, V);

    return 0;
}

