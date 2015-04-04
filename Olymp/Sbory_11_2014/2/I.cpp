#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
const long long inf = 10000000000000000;
const int N = 200001;
map <int, int> mp;
long long t[N * 8];
long long d[N], a[N], minus_sum, l, diff, ans = -inf;
inline long long get(int v, int Tl, int Tr, int l, int r) {
	if (Tl > r || Tr < l) {
		return -inf;
	}
	if (Tl >= l && Tr <= r) {
		return t[v];
	}
	long long res = -inf;
	int mid = (Tl+Tr) >> 1;
	res = max (res, get((v << 1), Tl, mid, l, r));
	res = max (res, get((v << 1) + 1, mid + 1, Tr, l, r));
	return res;
}
int n,k,sz,pos;
int main () {
	freopen ("threemax.in", "r", stdin);
	freopen ("threemax.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	cin >> n >> k;
	sz = 1;
	while (sz <= n)
		sz <<= 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i] = a[i] + d[i - 1];
	}
	for (int i = 1; i <= n; ++i)
		t[i + sz] = d[i];
	for (int i = sz - 1; i > 0; --i)
		t[i] = max (t[i << 1], t[(i << 1) + 1]);
	
	for (int i = 1; i <= n; ++i) {
		while (l <= n && diff != k) {
			++l;
			if (l > n)
				break; 
			if (mp[a[l]] == 0)
				++diff;
			++mp[a[l]];
		}
		if (diff != k)
			break;
		if (l > n) {
			break;
		} 
		long long x = get (1, 0, sz - 1, l, n) - minus_sum;
		if (ans < x) {
			ans = x;
			pos = i;
		}
		minus_sum += a[i];
		--mp[a[i]];
		if (mp[a[i]] == 0)
			--diff;
	}
	if (ans == -inf) {
		printf ("IMPOSSIBLE");
	}
	else {
		cout << ans;
		for (int i = pos; i <= n; ++i) {
			if (d[i] - d[pos - 1] == ans) {
				cout << "\n" << pos << " " << i;
				return 0;
			}
		}
	}
	return  0;
}