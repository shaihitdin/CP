#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;
const int N = 10000001;
const long long modulo = (1e9) + 7;
int l_p[N], phi[N];
long long sum[N], pw[N];
int main () {            
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	for (int i = 2; i < N; i += 2)
		l_p[i] = 2;
	for (long long i = 3; i * i < N; i += 2) {
		if (!l_p[i]) {
			for (long long j = i * i; j < N; j += (i << 1) )
				if (!l_p[j])	l_p[j] = i;
			l_p[i] = i;
		}
	}
	for (int i = 0; i < N; ++i)
		if(!l_p[i])	l_p[i] = i;
	phi[1] = 1;
	
	for (int i = 2; i < N; ++i) {
		if (i % (l_p[i] * 1ll * l_p[i]) )
			phi[i] = (l_p[i] - 1) * phi[i / l_p[i]];
		else
			phi[i] = l_p[i] * phi[i / l_p[i]];
	}
	for (int i = 1; i < N; ++i) {
		sum[i] = sum[i - 1] + phi[i];
	}
	for (int i = 1; i <= 10; ++i)
		cerr << l_p[i] << " ";
	cerr << "\n";
	for (int i = 1; i <= 10; ++i)
		cerr << phi[i] << " ";
	/*
	scanf ("%d", &t);
	++t;
	while (--t) {
		long long n, m, l, r;
		scanf ("%I64d%I64d%I64d%I64d", &n, &m, &l, &r);
		long long ans = 0;
		pw[0] = 1;
		for (int i = 1; i < N; ++i)
			pw[i] = (pw[i - 1] * (n - 2)) % modulo;
		for (int i = l; i <= r; ++i) {
			d = i;
			h = m / d;
			ans *= (pw[h]);
		}
	}
	*/
	return 0;
}