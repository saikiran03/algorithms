#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false); cin.tie(0);
#define tcase int _tc; cin >> _tc; while(_tc--)
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n) for(int i=n; i>0; i--)
#define For(i,a,b,inc) for(int i=a; i<=b; i+=inc)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define Rfor(i,a,b,inc) for(int i=a; i>=b; i-=inc)
#define RFOR(i,a,b) for(int i=a; i>=a; i--)
#define mems(a, b) memset(a, (b), sizeof(a))
#define all(x) x.begin(), x.end()
#define rall(x) x.end(), x.begin()
#define tr(it, x) for(auto it=x.begin(); it!=x.end(); it++)
#define rtr(it, x) for(auto it=x.end(); it!=x.begin(); it--)
#define present(x, c) (c.find(x) != c.end())
#define cpresent(x, c) (find(all(c), x) != c.end())
#define rf freopen("inp.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);
#define mp make_pair
#define pb push_back
#define fs first
#define se second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef map<int,int> mpii;
typedef set<int> seti;

const int inf = INT_MAX;
const int mod = 1000000007;
const double pi = acos(-1.0);
const double EPS = 1e-9;
const int MAX_SIZE = 325000005;

bool st[MAX_SIZE];
vi primes;

void sieve(int n){
	mems(st, true);
	st[0] = st[1] = false;

	for(int i=4; i<=n; i+=2) // Remove multiples of 2
		st[i] = false;

	for(int i=3; i*i<=n; i+=2) // Remove multiples of primes.
		for(int j=i*i; st[i] && j<=n; j+=i)
			st[j] = false;

	primes.pb(2);
	for(int i=3; i<=n; i+=2) // Push primes.
		if(st[i])
			primes.pb(i);

	return;
}

int main(){
	sieve(MAX_SIZE-1);
}
