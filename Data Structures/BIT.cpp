#include <bits/stdc++.h>
using namespace std;
 
class BIT {
public:
	int *base;
 
	BIT (int n) {
		len = n + 5;
		tree = new int[len];
		base = new int[len];
	}
 
	void update (int k, int f) {
		while (f < len) {
			tree[f] += k;
			f += (f & (-f));
		}
	}
 
	void build () {
		for (int i = 1; i <= len-5; i++ ) {
			update(base[i], i);
		}
	}
 
	int read (int f) {
		int ans = 0;
		while (f > 0) {
			ans += tree[f];
			f -= (f & (-f));
		}
		return ans;
	}
 
private:
	int *tree, len;
};
 
int main () {
	BIT fenwick(10000000);
}

//          1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
// f	    1	0	2	1	1	3	0	4	2	5	2	2	3	1	0	2
// c	    1	1	3	4	5	8	8	12	14	19	21	23	26	27	27	29
// tree	    1	1	2	4	1	4	0	12	2	7	2	11	3	4	0	29