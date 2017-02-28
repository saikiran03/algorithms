[x,y] = meshgrid(-2:.2:2);
g = x .* exp(-x.^2 - y.^2);
surf(x,y,g)
print -deps graph.eps#include <bits/stdc++.h>
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
 
inline int add(int a, int b, int m = inf) {ll v = a+b; return (int)(v%m); }
inline int mul(int a, int b, int m=mod){ return (int)(((ll)a * (ll)b) % m); }
inline int mpow(int b, int e, int m = mod){ int f=1; while(e>0){ if(e&1){ f=mul(f,b); } e=e>>1; b=mul(b,b); } return f; }
template <typename T> void log(T *h, T *t){ while(h!=t) cout << *(h++) << " "; cout << endl; }
 
struct node{
	node* child[26];
	bool isLeaf;
	int chs;
 
	node(){
		isLeaf = false;
		chs = 0;
		rep(i,26)
			child[i] = NULL;
	}
 
	void insert(node* root, string key){
		int index, level, length = key.length();
		node *pCrawl = root;
 
		for(level=0; level<length; level++){
			index = key[level]-'a';
 
			if(!pCrawl->child[index])
				pCrawl->child[index] = new node();
 
			(pCrawl->chs)++;
			pCrawl = pCrawl->child[index];
		}
		pCrawl->isLeaf = true;
	}
 
	int search(node* root, string key){
		int index, level, length = key.length();
		node *pCrawl = root;
 
		for(level=0; level<length; level++){
			index = key[level]-'a';
 
			if(!pCrawl->child[index])
				return 0;
 
			pCrawl = pCrawl->child[index];
		}
		if (pCrawl!=NULL)
			return pCrawl->chs + (pCrawl->isLeaf);
		else
			return 0;
	}
};
 
typedef node trie;

int main() {
	boost;
 	trie t;
}