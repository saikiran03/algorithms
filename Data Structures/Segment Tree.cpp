#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef map<int,int> mpii;
typedef set<int> seti;

#define boost ios_base::sync_with_stdio(false); cin.tie(0);
#define tcase int _tc; cin >> _tc; FOR(_TC,1,_tc)
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define RFOR(i,a,b) for(int i=a; i>=b; i--)
#define tr(it,x) for(auto it=x.begin(); it!=x.end(); it++)
#define rtr(it, x) for(auto it=x.end(); it!=x.begin(); it--)
#define mems(c,x) memset(c, x, sizeof c)
#define all(x) x.begin(), x.end()
#define rall(x) x.end(), x.begin()
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
const ll inf2 = 1e18;
const double pi = acos(-1.0);
const double EPS = 1e-9;
const int N = 10005;

inline int add(int a, int b, int m = inf) {ll v = a+b; return (int)(v%m); }
inline int mul(int a, int b, int m=mod){ return (int)(((ll)a * (ll)b) % m); }
inline int mpow(int b, int e, int m = mod){ int f=1; while(e>0){ if(e&1){ f=mul(f,b); } e=e>>1; b=mul(b,b); } return f; }

int A[N]; // Array
int tree[4*N]; // Segment Tree for array A.

int merge(int a, int b){
	// merge 2 nodes.
	return a + b;
}

void build(int s, int e, int n){
	if(s==e){
		tree[n] = A[s]; // assign values to leaves.
		return;
	}

	int m = (s+e)/2;
	build(s, m, 2*n); // build left subtree.
	build(m+1, e, 2*n+1); // build right subtree.

	tree[n] = merge(tree[2*n], tree[2*n+1]); // merge subtrees into current node.
	return;
}

// query (0, n-1, f, l, 1) returns sum for range [f,l];
int query(int s, int e, int f, int l, int n){
	if(l<s || f>e) // (f, l) is completely outside (s, e)
		return 0;

	if(l==s && f==e) // (f, l) is completely inside (s, e)
		return tree[n];

	// (f, l) is partially inside (s, e).
	int m = (s+e)/2;
	int p = query(s, m, l, r, 2*n);
	int q = query(m+1, e, l, r, 2*n+1);

	return merge(p, q);
}

// update (0, n-1, l, r, 1, v) updates range (l, r).
void update(int s, int e, int l, int r, int n, int v){
	if(s>e || s>r || e<l) // (f,l) out of current range.
		return;

	if(s==e){
		tree[n] += v;
		return;
	}

	int m = (s+e)/2;
	update(s, m, l, r, 2*n, v); // update left subtree
	update(m+1, e, l, r, 2*n+1, v); // update right subtree.

	tree[n] = merge(tree[2*n], tree[2*n+1]);
	return;
}

int main() {
	boost;
	
	// Input for Array A.
	int n;
	cin >> n;
	rep(i,n) cin >> A[i];

	build(0,n-1,1);
	cout << query(0,n-1,1,4,1) << endl;
	update(0,n-1,1,4,1,2);
	cout << query(0,n-1,1,4,1) << endl;

	return 0;
}