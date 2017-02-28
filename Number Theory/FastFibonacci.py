from math import sqrt

N = 1000005
PHI = 1.61803398875
SQRT5 = sqrt(5)
MOD = 1000000007

fib = [-1] * N
fib[1] = fib[2] = 1

def FF(n):
	if(n==0):
		return 0

	if n<N and fib[n]!=-1:
		return fib[n]

	m = n/2
	if n&1:
		fib[n*(n<N)] = (pow(FF(m+1), 2, MOD) + pow(FF(m), 2, MOD)) % MOD
	else:
		fib[n*(n<N)] = (FF(m) * (FF(m) + 2*FF(m-1))) % MOD

	return fib[n*(n<N)]

# Approximate Value
def phiF(n):
	num = pow(PHI, n, MOD) - pow(-PHI, -n, MOD)
	return int(num/SQRT5)

print FF(10000000000)
