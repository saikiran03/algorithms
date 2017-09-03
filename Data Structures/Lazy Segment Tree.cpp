#include <bits/stdc++.h>
using namespace std;


class LazySegmentTree {
public:
    int *A;

    LazySegmentTree (int n) {
        len = n+5;
        A = new int[len];
        lazy = new int[4*len];
        tree = new int[4*len];
        Reset();
    }

    void Reset () {
        for (int i = 0; i < len; i++ ) {
            A[i] = 0;
            for (int j = 0; j < 4; j++ ) {
                tree[4*i + j] = 0;
                lazy[4*i + j] = 0;
            }
        }
    }

    void build (int s, int e, int n) {
        if (s==e) {
            tree[n] = A[s]; // assign values to leaves.
            return;
        }

        int m = (s+e)/2;
        build (s, m, 2*n); // build left subtree.
        build (m+1, e, 2*n+1); // build right subtree.

        tree[n] = merge(tree[2*n], tree[2*n+1]); // merge subtrees into current node.
        return;
    }

    // query (0, n-1, l, r, 1) returns sum for range [f,l];
    int query (int s, int e, int l, int r, int n) {
    	if (r<s || l>e) { // (s, e) is completely outside (l, r)
            return 0;
        }

        if (lazy[n]!=0) {
            tree[n] += (e-s+1) * lazy[n];
            if (s!=e) {
                lazy[2*n] += lazy[n];
                lazy[2*n+1] += lazy[n];
            }
            lazy[n] = 0;
        }

        if (l<=s && r>=e) { // (s, e) is completely inside (l, r)
            return tree[n];
        }

        // (s, e) is partially inside (l, r).
        int m = (s+e)/2;
        int p = query(s, m, l, r, 2*n);
        int q = query(m+1, e, l, r, 2*n+1);

        return merge(p, q);
    }

    // update (0, n-1, l, r, 1, v) updates range (l, r).
    void update (int s, int e, int l, int r, int n, int v) {

        if (lazy[n] != 0) {
            tree[n] += (e-s+1) * lazy[n];
            if (s!=e) {
                lazy[2*n] += lazy[n];
                lazy[2*n+1] += lazy[n];
            }
            lazy[n] = 0;
        }

        if (s>r || e<l) { // (s,e) out of current range.
            return;
        }

        if (s>=l && e<=r) {
			tree[n] += (e-s+1) * v;
			if (s!=e) {
				lazy[2*n] += v;
				lazy[2*n+1] += v;
			} else {
				A[s] = tree[n];
			}
            return;
        }

        int m = (s+e)/2;
        update(s, m, l, r, 2*n, v);  // update left subtree
        update(m+1, e, l, r, 2*n+1, v);  // update right subtree.

        tree[n] = merge(tree[2*n], tree[2*n+1]);
        return;
	}

	void completeLazy (int s, int e, int n) {
		if (lazy[n]!=0) {
			tree[n] += (e-s+1) * lazy[n];
			if (s!=e) {
				lazy[2*n] += lazy[n];
				lazy[2*n+1] += lazy[n];
			}
			lazy[n] = 0;
		}

		if (s!=e) {
			int m = (s+e)/2;
			completeLazy(s, m, 2*n);
			completeLazy(m+1, e, 2*n+1);
		} else {
            A[s] = tree[n];
        }
		return;
	}

private:
    int *lazy, *tree, len;

    int merge (int a, int b) {
        return a + b;
    }
};

int main() {
	LazySegmentTree lst(10);
    for (int i = 0; i < 10; i++ ) {
        cin >> lst.A[i];
    }

    lst.build(0, 9, 1);
    cout << lst.query(0, 9, 1, 5, 1) << endl;
    lst.update(0, 9, 1, 4, 1, 2) << endl;
    cout << lst.query(0, 9, 1, 5, 1) << endl;

    return 0;
}
