#include <bits/stdc++.h>
using namespace std;

const int M = 10000005;
int spf[M];

void factorSieve() {
    spf[1] = 1;
    for (int i = 2; i < M; i++)
        spf[i] = i;

    for (int i = 4; i < M; i+=2)
        spf[i] = 2;

    for (int i = 3; i*i < M; i+=2)
        for (int j = i*i; (j < M) && (spf[i]==i); j+=i)
            if (spf[j] == j)
                spf[j] = i;

    return;
}

map<int, int> getFactorisation(int x) {
    map<int, int> factors;
    while (x>1) {
        factors[spf[x]]++;
        x /= spf[x];
    }
    return factors;
}

int main() {
    factorSieve();
    map<int, int> factors = getFactorisation(1440);
    return 0;
}
