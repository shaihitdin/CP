#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N = 2000001, sz = 4000037;
const long long inf = 1e18;
long long n, a[2001], ans;
int cnt[N];
pair <long long, int> cnt1[sz];

void add (long long num) {
    if (num < 0) {
    	num = -num;
    	num |= (1LL << 55);
    }
	int i = num % sz;
	for (; cnt1[i].F != -inf && cnt1[i].F != num;) {
		if (++i == sz)
			i = 0;
	}
	cnt1[i].F = num;
	++cnt1[i].S;
}

int find_it (long long num) {
    if (num < 0) {
    	num = -num;
    	num |= (1LL << 55);
    }
	int i = num % sz;
	for (; cnt1[i].F != -inf && cnt1[i].F != num;) {
		if (++i == sz)
			i = 0;
	}
	return cnt1[i].S;
}

int main () {
	freopen ("F.in", "r", stdin);
	freopen ("F.out", "w", stdout);
	scanf ("%I64d", &n);
	for (int i = 0; i < sz; ++i)
		cnt1[i].F = -inf;
	for (int i = 1; i <= n; ++i)
		scanf ("%I64d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j)
			ans += (cnt[(N >> 1) - (a[i] + a[j])] - find_it (-( (a[i] + a[j]) << 22) + a[i]) - find_it (-( (a[i] + a[j]) << 22) + a[j]) );
		for (int j = i + 1; j <= n; ++j) {
			++cnt[(N >> 1) + a[i] + a[j]];		
			add( ( (a[i] + a[j]) << 22) + a[i]);
			add( ( (a[i] + a[j]) << 22) + a[j]);
		}
	}
	printf ("%I64d", ans / 3);
	return 0;
}