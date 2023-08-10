#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the edges in the form (src dest wt)" << endl;
    vector<pair<int, int>> graph[n];
    map<int, int> costMap;
    vector<int> visited(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> costQueue;

    for (int i = 0; i < e; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        graph[src].push_back({wt, dest});
        graph[dest].push_back({wt, src});
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j].second << ":" << graph[i][j].first << " ";
        cout << endl;
    }

    // initial config
    costQueue.push({0, 0});

    //--------DIJIKSTRA ALGO--------------------------
    while (!costQueue.empty())
    {
        // continue doing bfs on unvisited nodes
        pair<int, int> curr = costQueue.top();
        int currNode = curr.second;
        int currWt = curr.first;
        costQueue.pop();
        if (!visited[currNode])
        {
            visited[currNode] = 1;
            for (int i = 0; i < graph[currNode].size(); i++)
            {
                costQueue.push({graph[currNode][i].first + currWt, graph[currNode][i].second});
            }
            costMap[currNode] = currWt;
        }
    }
    cout << "---------------------------------------" << endl;
    cout << "Forwarding table" << endl;
    cout << "---------------------------------------" << endl;
    cout << "node\tcost" << endl;
    for (auto it : costMap)
    {
        cout << it.first << "\t" << it.second << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << "Graph" << endl;
    cout << "---------------------------------------" << endl;
    //------------------------------------------------
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j].second << ":" << graph[i][j].first << " ";
        cout << endl;
    }
    return 0;
}