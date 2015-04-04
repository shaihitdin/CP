#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 100001;
long long t1[N], t2[N];
long long sum1(int r) {
	long long ans = 0;
	for(int i = r; i >= 1; i = (i & (i+1)) - 1) {
		ans += t1[i];
	}
	return ans;
}
void upd1(int r, long long inc) {
	for(int i = r; i < N; i = i | (i+1)) {
		t1[i] += inc;
	}
	return;
}
long long sum2(int r) {
	long long ans = 0;
	for(int i = r; i >= 1; i = (i & (i+1)) - 1) {
		ans += t2[i];
	}
	return ans;
}
void upd2(int r, int inc) {
	for(int i = r; i < N; i = i | (i+1)) {
		t2[i] += inc;
	}
	return;
}
int main() {
	freopen("mega.in", "r", stdin);
	freopen("mega.out", "w", stdout);
		long long n;
		scanf("%lld", &n);
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			long long x;
			scanf("%lld", &x);
			ans += (sum2(N-1)-sum2(x));
			upd1(x, 1);
			upd2(x, sum1(N-1)-sum1(x));
		}
		printf("%lld", ans);
	return 0;
}