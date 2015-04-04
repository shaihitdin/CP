/*
ID: shaihit1
PROG: sprime
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e9;
int a, b;
int powers[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
const int N = 3e6;
vector <int> primes, answers;

inline bool check_prime (const int && x) {
	if (x == 1 || x == 0)
		return 0;
	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i)
		if (!(x % primes[i]))
			return 0;
	return 1;
}

int st[N], stq, enq, n;

int main() {
	
	freopen ("sprime.in", "r", stdin);
	freopen ("sprime.out", "w", stdout);
	
	for (int i = 2; i * i <= MAXN; ++i) {
		bool flag = 0;
		for (int j = 2; j * j <= i; ++j)
			if (!(i % j))
				flag = 1;
		if (!flag)
			primes.push_back (i);
	}
	
	scanf ("%d", &n);
	
	st[enq++] = 0;
	while (stq < enq) {
		int v = st[stq++];
		if (v / powers[n - 1]) {
			answers.push_back (v);
			continue;
		}
		for (int i = 0; i <= 9; ++i)
			if (check_prime (v * 10 + i))
				st[enq++] = v * 10 + i;
	}

	for (int to : answers)
		printf ("%d\n", to);
	return 0;
}
