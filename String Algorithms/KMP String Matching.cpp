#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define boost ios_base::sync_with_stdio(false); cin.tie(0);
#define tcase int _tc; cin >> _tc; while(_tc--)
#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define tr(it,x) for(auto it=x.begin(); it!=x.end(); it++)
#define mems(c,x) memset(c, x, sizeof c)
#define all(x) x.begin(), x.end()
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
const double pi = acos(-1.0);
const double EPS = 1e-9;
const int max_n = 100010;
string T,P;
int b[max_n], n, m;

void kmpPreprocess(){
    int i=0, j=-1; b[0] = -1;
    while(i < m){
        while(j>=0 && P[i]!=P[j]) j = b[j];
        i++; j++;
        b[i] = j;
        cout << b[i] << " ";
    }
    cout << endl;
    return;
}

void kmpSearch(){
    int i=0, j=0;
    while(i<n){
        while(j>=0 && T[i]!=P[j]) j = b[j];
        i++; j++;
        if(j==m){
            cout << "P is found at index " << i-j << " in T" << endl;
        }
    }
    return;
}

int main() {
    boost;
    cin >> P >> T;
    m = P.length(); n = T.length();
    kmpPreprocess();
    kmpSearch();
}