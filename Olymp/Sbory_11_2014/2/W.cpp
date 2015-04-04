#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 20001;
long long t[11][N], k;
const long long mod = 1000000000;
long long sum(int r, int pos) {
	long long ans = 0;
	for (int i = r; i >= 1; i = (i & (i+1)) - 1) {
		ans = (ans + t[pos][i]) % mod;
	}
	return ans;
}
void upd(int r, long long inc, int pos) {
	for (int i = r; i < N; i = i | (i+1)) {
		t[pos][i] = (t[pos][i] + inc) % mod;
	}
	return;
}
#ifdef _WIN32
	#define ll "%I64d"
#else
	#define ll "%lld"
#endif
int main() {
	freopen ("kinverse.in", "r", stdin);
	freopen ("kinverse.out", "w", stdout);
		long long n;
		scanf(ll ll, &n, &k);
		--k;
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			long long x;
			scanf(ll, &x);
			ans = (ans + (sum (N-1, k) - sum (x, k) ) + mod) % mod;
			upd (x, 1, 1);
			for (int j = 2; j <= k; ++j)
				upd (x, sum (N - 1, j - 1) - sum (x, j - 1), j);
		}
		printf(ll, ans);
	return 0;
}