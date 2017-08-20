#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int *A;

    SegmentTree (int n) {
        len = (n+5);
        tree = new int[4*len];
        A = new int[len];
    }

    void build (int s, int e, int n) {
        if (s == e) {
            tree[n] = A[s]; // assign leaf value.
            return;
        }

        int m = (s+e)/2;
        build (s, m, 2*n); // build left sub-tree
        build (m+1, e, 2*n+1); // build right sub-tree

        tree[n] = merge(tree[2*n], tree[2*n+1]); // merge sub-tree at current node.
        return;
    }

    // query (0, n-1, f, l, 1) returns sum for range [f,l];
    int query (int s, int e, int f, int l, int n) {
    	if (l<s || f>e) // (f, l) is completely outside (s, e)
    		return 0;

    	if (s<=f && l<=e) // (f, l) is completely inside (s, e)
    		return tree[n];

    	// (f, l) is partially inside (s, e).
    	int m = (s+e)/2;
    	int p = query(s, m, f, l, 2*n);
    	int q = query(m+1, e, f, l, 2*n+1);

    	return merge(p, q);
    }

    // update (0, n-1, l, r, 1, v) updates range (l, r).
    void update(int s, int e, int l, int r, int n, int v){
    	if (s>e || s>r || e<l) // (f,l) out of current range.
    		return;

    	if (s==e) {
    		tree[n] += v;
    		return;
    	}

    	int m = (s+e)/2;
    	update(s, m, l, r, 2*n, v); // update left subtree
    	update(m+1, e, l, r, 2*n+1, v); // update right subtree.

    	tree[n] = merge(tree[2*n], tree[2*n+1]);
    	return;
    }

private:
    int *tree, len;

    int merge (int a, int b) {
        return a + b;
    }
};

int main () {

    int n;
    cin >> n;

    SegmentTree st(n);
    for (int i = 0; i < n; i++ ) {
        cin >> st.A[i];
    }

    st.build(0, n-1, 1);
    cout << st.query(0, n-1, 1, 4, 1) << endl;

    st.update(0, n-1, 1, 4, 1, 2);
	cout << st.query(0, n-1, 1, 4, 1) << endl;

    return 0;
}
