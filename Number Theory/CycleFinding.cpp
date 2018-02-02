#include <bits/stdc++.h>
using namespace std;

int f(int x) {return (7*x+5)%12;}

pair<int, int> floydCycleFinding(int x) {
    int t = f(x), h = f(f(x));
    while (t!=h) {t = f(t); h = f(f(h));}

    int mu = 0; h = x;
    while (t!=h) {t = f(t); h = f(h); mu++;}

    int lmb = 1; h = f(t);
    while (t!=h) {h = f(h); lmb++;}

    return {mu, lmb};
}

pair<int, int> brentCycleFinding(int x) {
    int t = x, h = f(x), l = 1, p = 1, mu = 0;
    while (t!=h) {
        if (l==p) {
            p = p<<1;
            l = 0;
            t = h;
        }
        h = f(h);
        l++;
    }

    t = h = x;
    for (int i = 0; i < l; i++) {
        h = f(h);
    }

    // find start of cycle
    while (t!=h) {
        t = f(t);
        h = f(h);
        mu++;
    }
    return {mu, l};
}

int main() {
    pair<int, int> f, b;
    f = floydCycleFinding(10);
    b = brentCycleFinding(10);
    cout << f.first << " " << f.second << endl;
    cout << b.first << " " << b.second << endl;
    return 0;
}
