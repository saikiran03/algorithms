#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false); cin.tie(0);
#define tcase int _tc; cin >> _tc; while(_tc--)
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
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
const int N = 100005;

int A[N], BIT[N]; // Both are 1 based index arrays.

void updateBIT(int k, int f, int n){
    while(f<n){
        BIT[f] += k;
        f += (f & (-f));
    }
    return;
}

int fetchBIT(int f, int n){
    int ans = 0; // Sum from index 1 to f.
    while(f>0){
        ans += BIT[f];
        f -= (f & (-f));
    }
    return ans;
}

void buildBIT(int n){
    FOR(i,1,n)
        updateBIT(A[i], i, n);
    return;
}

int main(){
    
}


//          1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
// f	    1	0	2	1	1	3	0	4	2	5	2	2	3	1	0	2
// c	    1	1	3	4	5	8	8	12	14	19	21	23	26	27	27	29
// tree	    1	1	2	4	1	4	0	12	2	7	2	11	3	4	0	29