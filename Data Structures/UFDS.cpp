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

int main () {
    UFDS ufds(5);

    ufds.Union(1, 2);
    ufds.Union(1, 3);
    ufds.Union(5, 4);
}
