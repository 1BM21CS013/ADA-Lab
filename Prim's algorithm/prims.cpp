#include <bits/stdc++.h>
#include <vector>

using namespace std;

int findminKey(int v, vector<int> &key, vector<bool> &vis)
{
    int min = INT_MAX, minIndex;

    for (int i = 0; i < v; i++)
    {
        if (key[i] < min && !vis[i])
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph)
{
    cout << "edge \t weight" << endl;

    for (int i = 1; i < graph.size(); i++)
    {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}
void primsMST(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);

    vector<bool> vis(n, false);

    key[0] = 0;

    for (int i = 1; i < n; i++)
    {

        int curr = findminKey(n, key, vis);

        vis[curr] = true;

        for (int j = 0; j < n; j++)
        {

            if (graph[curr][j] && vis[j] == false && graph[curr][j] < key[j])
            {
                parent[j] = curr;
                key[j] = graph[curr][j];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{

    int n = 5;

    cout << "enter no of vertices: " << endl;
    // cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    graph = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};

    primsMST(graph);

    return 0;
}