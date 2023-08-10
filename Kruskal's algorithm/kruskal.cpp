#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> e1, vector<int> e2)
{
    return e1[2] <= e2[2];
}
int main()
{
    int n;
    int e;
    vector<vector<int>> graph;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the edges between vertices in the form (a b wt)\n";
    vector<int> visited(n, 0);
    vector<pair<int, int>> mst[n];
    for (int i = 0; i < e; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        vector<int> temp = {a, b, wt};
        graph.push_back(temp);
    }
    sort(graph.begin(), graph.end(), cmp);
    for (int i = 0; i < e; i++)
    {
        // start constructing the tree using
        // the nodes connected to edges with least weight
        // mark the nodes visited
        // only use the unvisited nodes

        int a = graph[i][0];
        int b = graph[i][1];
        int wt = graph[i][2];
        if (!visited[a] || !visited[b])
        {
            mst[a].push_back({b, wt});
            mst[b].push_back({a, wt});
            visited[a] = visited[b] = 1;
        }
    }
    cout << "----------------------------------------\n";
    cout << "Minimum spanning tree:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; i++)
    {        
        for (int j = 0; j < mst[i].size(); j++)
            cout << i << "-" << mst[i][j].first << " " << mst[i][j].second << endl;        
    }
    return 0;
}