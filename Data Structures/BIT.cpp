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