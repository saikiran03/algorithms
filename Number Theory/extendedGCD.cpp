#include <bits/stdc++.h>
using namespace std;

// ax + by = gcd(a, b)
int extendedGCD(int a, int b, int *x, int *y) {
    if (a==0) {
        *x = 0; *y = 1;
        return b;
    }

    int x1, y1;
    int g = extendedGCD(b%a, a, &x1, &y1);

    *x = y1 - (b/a)*x1;
    *y = x1;
    return g;
}

int main () {
    int a, b, x, y;
    scanf("%d %d", &a, &b);
    int g = extendedGCD(a, b, &x, &y);
    printf("%d(%d) + %d(%d) = %d\n", a, x, b, y, g);
    return 0;
}
