#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> adj[], int *visited, int vertex, vector<int> &topo, int *path)
{
    if(path[vertex])
        return false;
    if(visited[vertex])
        return true;
    visited[vertex] = 1;
    path[vertex] = 1;
    cout << vertex << " ";
    int numOfNeighbors = adj[vertex].size();
    for (int i = 0; i < numOfNeighbors; i++)
        if (!visited[adj[vertex][i]])
            dfs(adj, visited, adj[vertex][i], topo, path);
    path[vertex] = 0;
    topo.push_back(vertex);
    return true;
}

int main()
{
    int n, e, a, b;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<int> adj[n];
    vector<int> topo;
    int visited[n] = {0};
    int path[n] = {0};
    cout << "Enter the edges between nodes in the form of (a b) which means an edge between a and b\n";
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        while (a >= n || b >= n)
        {
            cout << "vertices can only be in the range: 0-" << n - 1 << endl;
            cin >> a >> b;
        }
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        int size = adj[i].size();
        cout << "Node " << i << ": ";
        for (int j = 0; j < size; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    dfs(adj, visited, 0, topo, path);
    cout << "\n";
    int size = topo.size();
    for (int i = size - 1; i >= 0; i--)
        cout << topo[i] << " ";

    return 0;
}