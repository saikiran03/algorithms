// Dijkstra's Algorithm

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define boost ios_base::sync_with_stdio(false); cin.tie(0);
#define tcase int _tc; cin >> _tc; while(_tc--)
#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define tr(it,x) for(auto it=x.begin(); it!=x.end(); it++)
#define mems(c,x) memset(c, x, sizeof c)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define present(x,c) (c.find(x) != c.end())
#define cpresent(x,c) (find(all(c), x) != c.end())
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);
#define mp make_pair
#define pb push_back
#define fs first
#define se second

const int mod = 1000000007;
const int inf = INT_MAX;
const double pi = acos(-1.0);
const double EPS = 1e-9;
const int N = 1005;

vii adj[N];
int dist[N];
int visited[N];

void Dijkstra(int V, int u){
	mems(dist, inf);
	mems(visited, false); 
	dist[u] = 0;

	class prioritize{ 
		public:
			bool operator ()(ii &p1, ii &p2){
				return p1.se > p2.se;
			}
	};

	priority_queue<ii, vii, prioritize> pq;
	pq.push(mp(u, dist[u]=0));

	while(!pq.empty()){
		ii v = pq.top();
		pq.pop();

		int cv = v.fs, cw = v.se;
		if(visited[cv])
			continue;
		
		visited[cv] = true;
		tr(it, adj[cv]){
			if((!visited[it->fs]) && ((ll)it->se + cw < dist[it->fs]))
				pq.push(mp(it->fs, dist[it->fs] = it->se + cw));
		}
	}

	return;
}

int main() {
	boost;
	int V, E, u, v, w;
	cin >> V >> E;
	rep(i,E){
		cin >> u >> v >> w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	Dijkstra(V, 1);
	FOR(i,1,V)
		cout << dist[i] << " ";
	cout << endl;
}