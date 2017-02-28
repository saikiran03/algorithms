// Kruskal Algorithm Implementation : Minimum Spanning Tree

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
const int N = 10005;

int id[N];
pair<ll, ii> p[N];

void init(){
	rep(i,N)
		id[i] = i;
	return;
}

int root(int x){
	while(id[x] != x){
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void Union(int u, int v){
	int p = root(u);
	int q = root(v);
	id[p] = id[q];
	return;
}


ll kruskal(int V, int E){
	int u, v;
	ll cost, minC=0;

	rep(i,E){
		u = p[i].se.fs;
		v = p[i].se.se;
		cost = p[i].fs;
		if(root(u) != root(v)){
			minC += cost;
			Union(u, v);
		}
	}

	return minC;
}

int main() {
	boost;
	int V, E, u, v, wt;
	cin >> V >> E;
	rep(i,E){
		cin >> u >> v >> wt;
		p[i] = mp(wt, mp(u,v));
	}
	
	init();
	sort(p, p+E);
	cout << kruskal(V, E) << endl;
}