#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int mul(int a, int b, int m) { return (int)(((ll)a * (ll)b) % m); }
inline int mpow(int b, int e, int m){
    int f = 1;
    while (e>0) {
        if (e&1)
            f = mul(f, b, m);
        e = e>>1;
        b = mul(b, b, m);
    }
    return f;
}

namespace primality {

    vector<int> primes;

    // Probably will fail for carmicheal numbers.
    bool fermatTest(int n) {
        int k = max(5, rand() % 20); // random k
        for (int i = 0; i < k; i++) {
            int x = max(1, (rand() % n));
            if (mpow(x, n-1, n) != 1) {
                return false;
            }
        }
        return true;
    }

    bool millerRabinUtil(int d, int n) {
        int a = 2 + rand() % (n - 4);
        int x = mpow(a, d, n);

        if (x==1 || x==n-1)
            return true;

        while (d!=n-1) {
            x = (x*x) % n;
            d *= 2;

            if (x==1) return false;
            if (x==n-1) return true;
        }

        return false;
    }

    bool millerRabinTest(int n) {
        if (n <= 1 || n == 4)  return false;
        if (n <= 3) return true;

        int d = n - 1;
        while (d&1==0) { d>>=1; }

        int k = max(5, rand() % 20);
        for (int i = 0; i < k; i++)
                if (millerRabinUtil(d, n) == false)
                    return false;

        return true;
    }

    void primeSieve(int n) {
        bool st[n+1];
        memset(st, true, sizeof(st));
    	st[0] = st[1] = false;

	    for (int i = 4; i <= n; i+=2) // Remove multiples of 2
    		st[i] = false;

    	for (int i = 3; i*i <= n; i+=2) // Remove multiples of primes.
    		for(int j = i*i; st[i] && (j <= n); j+=i)
    			st[j] = false;

	    primes.push_back(2);
    	for (int i = 3; i <= n; i+=2) // Push primes.
    		if (st[i])
    			primes.push_back(i);

    	return;
    }

    void segmentedSieve(int n) {}

};

int main () {
    for (int i = 2; i < 1000; i++) {
        if (primality::fermatTest(i)) {
            cout << i << endl;
        }
    }

	for (int i = 2; i < 1000; i++) {
        if (primality::millerRabinTest(i)) {
            cout << i << endl;
        }
    }

    primality::primeSieve(1000);
    for (int i = 0; i < primality::primes.size(); i++) {
        cout << primality::primes[i] << " ";
    }
    cout << endl;

    return 0;
}
