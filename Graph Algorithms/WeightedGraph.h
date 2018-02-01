#include <bits/stdc++.h>
using namespace std;

// Implement AddEdge method to modify the class of Graph to Directed/Undirected/Unweighted.
class WeightedGraph {
public:
    vector< pair<int, int> > *adjList;
    int nodes;

    WeightedGraph(int n) {
        adjList = new vector< pair<int, int> >[n];
        nodes = n;
    }

    void AddEdge(int u, int v, int w);

    void BFS(int u);
    void DFS(int u);

    vector<int> Dijkstra(int u);
    vector< vector<int> > FloydWarshall();

    vector<int> ArticulationPoints();
    vector< pair<int, int> > Bridges();
    vector<int> TopologicalOrder();
};

void WeightedGraph::BFS(int u) {
    queue<int> q;
    bool vis[nodes] = {false};

    q.push(u);
    vis[u] = true;

    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < adjList[f].size(); i++) {
            int v = adjList[f][i].first; // neighbour of f.
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    return;
}

void WeightedGraph::DFS(int u) {
    stack<int> st;
	bool vis[nodes] = {false};

	st.push(u);
	vis[u] = true;

	while (!st.empty()) {
		int f = st.top();
		st.pop();

		for (int i = 0; i < adjList[f].size(); i++) {
			int v = adjList[f][i].first;
			if (!vis[v]) {
				st.push(v);
				vis[v] = true;
			}
		}
	}

    return;
}

vector<int> WeightedGraph::Dijkstra(int u) {
    vector<int> dist(nodes, 1<<30);
    bool vis[nodes] = {false};
    multiset< pair<int, int> > ms;

    dist[u] = 0;
    ms.insert({0, u});

    while (!ms.empty()) {
        pair<int, int> p = *ms.begin();
        ms.erase(ms.begin());

        int x = p.second, w = p.first;
        if (vis[x])
            continue;

        vis[x] = true;
        for (int i = 0; i < adjList[x].size(); i++) {
            int e = adjList[x][i].first, we = adjList[x][i].second;
            if (dist[x] + we < dist[e]) {
                dist[e] = dist[x] + we;
                ms.insert({dist[e], e});
            }
        }
    }

    return dist;
}

vector<vector<int>> WeightedGraph::FloydWarshall() {
    vector<vector<int>> dist(nodes, vector<int>(nodes, 1<<29));
    for (int u = 0; u < nodes; u++) {
        for (int e = 0; e < adjList[u].size(); e++) {
            dist[u][adjList[u][e].first] = adjList[u][e].second;
        }
        dist[u][u] = 0;
    }

    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

vector<int> WeightedGraph::TopologicalOrder() {
    vector<int> Inorder(nodes, 0);
    for (int u = 0; u < nodes; u++) {
        for (int i = 0; i < adjList[u].size(); i++) {
            Inorder[adjList[u][i].first]++;
        }
    }

    vector<int> TO;
    queue<int> q; // Modify this to min-heap to get lexicographically lowest ordering.

    for (int u = 0; u < nodes; u++) {
        if (Inorder[u]==0) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int f = q.front(); q.pop();
        TO.push_back(f);

        for (int i = 0; i < adjList[f].size(); i++) {
            int v = adjList[f][i].first;
            Inorder[v]--;
            if (Inorder[v]==0) {
                q.push(v);
            }
        }
    }

    if (TO.size() < nodes) {
        cout << "Graph is not DAG." << endl;
    }
    return TO;
}
