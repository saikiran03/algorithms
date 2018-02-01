#include <bits/stdc++.h>
using namespace std;

#define inf (int)1e9
#define mod (int)1e9 + 7
inline int add (int a, int b) { return ((a%mod) + (b%mod)) % mod; }

const int N = 105;
int adjMat[N][N], dist[N][N];

void floydWarshall (int n) {
	
	for (int k = 1; k <= n; k++ ) 
		for (int i = 1; i <= n; i++ ) 
			for (int j = 1; j <= n; j++ ) 
				dist[i][j] = min( dist[i][j], add(dist[i][k], dist[k][j]) );

	return;
}

int main() {
	// your code goes here

	int v, e, t, h, w;
	cin >> v >> e;

	for (int i = 1; i <= v; i++ ) 
		for (int j = 1; j <= v; j++ ) 
			dist[i][j] = inf;
	
	for (int i = 0; i < e; i++ ) {
		cin >> h >> t >> w;
		dist[h][t] = w;
		dist[t][h] = w;
	}

	floydWarshall(v);

	for (int i = 1; i <= v; i++ ) {
		for (int j = 1; j <= v; j++ ) 
			cout << dist[i][j] << " ";
		cout << endl;
	}
	return 0;
}