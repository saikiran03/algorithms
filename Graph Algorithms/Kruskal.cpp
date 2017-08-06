// Kruskal Algorithm Implementation : Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

class UFDS {
public:
    UFDS (int n) {
        len = (++n);
        root = new int[n];
        size = new int[n];

        for (int i = 0; i < n; i++ ) {
            root[i] = i;
            size[i] = 1;
        }
    }

    int Root (int u) {
        while (root[u] != u) {
            root[u] = root[root[u]];
            u = root[u];
        }
        return u;
    }

    bool Find (int u, int v) {
        return (Root(u) == Root(v));
    }

    void Union (int u, int v) {
        int ru = Root(u);
        int rv = Root(v);

        if (size[ru] < size[rv]) {
            root[ru] = root[rv];
            size[rv] += size[ru];
        } else {
            root[rv] = root[ru];
            size[ru] += size[rv];
        }
    }

private:
    int *root, *size, len;

};

const int N = 10005;
pair<long long, pair<int, int> > p[N];

long long kruskal (int V, int E) {
	UFDS ds(V);
	int u, v;
	long long wt, minC=0;

	for (int i = 0; i < E; i++ ) {
		u = p[i].second.first;
		v = p[i].second.second;
		wt = p[i].first;
		if(ds.Root(u) != ds.Root(v)){
			minC += wt;
			ds.Union(u, v);
		}
	}

	return minC;
}

int main() {
	int V, E, u, v, wt;
	cin >> V >> E;

	for (int i = 0; i < E; i++ ) {
		cin >> u >> v >> wt;
		p[i] = {wt, {u, v}};
	}

	sort(p, p+E);
	cout << kruskal(V, E) << endl;
}
