#include <bits/stdc++.h>
#include "WeightedGraph.h"
using namespace std;

// Weighted Undirected Graph
void WeightedGraph::AddEdge(int u, int v, int w = 1) {
    adjList[u].push_back({v, w});
    // adjList[v].push_back({u, w});
}

int main() {
    int V, E, u, v, w;
    cin >> V >> E;
    WeightedGraph wdg(V);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        wdg.AddEdge(u-1, v-1, w);
    }

    // vector<int> shortestPaths(wdg.Dijkstra(0));
    // for (int i = 1; i < V; i++) {
    //     cout << shortestPaths[i] << " ";
    // }
    // cout << endl;
    //
    // vector< vector<int> > shortestPathsG(wdg.FloydWarshall());
    // for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++) {
    //         cout << shortestPathsG[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> TopOrder(wdg.TopologicalOrder());
    for (int i = 0; i < TopOrder.size(); i++) {
        cout << TopOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
