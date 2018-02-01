#include <bits/stdc++.h>
using namespace std;

const int inf = 2000000000;
const int N = 10005;
vector< pair<int,int> > adjList[N];
int dist[N];
bool visited[N];

inline void pd (int n) { for (int i = 1; i <= n; i++ ) cout << dist[i] << " "; cout << endl; }

void dijkstra (int u, int V) {
	memset(visited, false, sizeof visited);
	for (int i = 1; i <= V; i++ )
		dist[i] = inf;
		
	multiset< pair<int, int> > s;
	dist[u] = 0;

	s.insert({0, u});
	while (!s.empty()) {
		pair<int, int> p = *s.begin();
		s.erase(s.begin());

		int v = p.second, w = p.first;
		if (visited[v])
			continue;
		
		visited[v] = true;
		for (int i = 0; i < adjList[v].size(); i++ ) {
			int e = adjList[v][i].second, f = adjList[v][i].first;
			
			if (dist[v] + f < dist[e]) {
				dist[e] = dist[v] + f;
				s.insert({dist[e], e});
			}
		}
	}

	return;
}

int main(){
	int V, E, u, v, w;
	cin >> V >> E;

	for (int i = 0; i < E; i++ ) {
		cin >> u >> v >> w;
		adjList[u].push_back({w, v});
		adjList[v].push_back({w, u});
	}

	dijkstra(1, V);
	pd(V);
}