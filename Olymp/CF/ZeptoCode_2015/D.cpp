#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, bpr = 1e9 + 7, pr = 31;

int n, k;

string s;
int p_pow[N], ok[N];
int h[N];


inline int to_pow (const int &hash, const int &position) {
	return (hash * 1ll * p_pow[N - 1 - position]) % bpr;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	
	cin >> n >> k;

	cin >> s;

	s = '#' + s;
	p_pow[0] = 1;
	
	for (int i = 1; i < N; ++i)
		p_pow[i] = (p_pow[i - 1] * 1ll * pr) % bpr;

	for (int i = 1; i <= n; ++i)
		h[i] = (h[i - 1] + (s[i] - 'a' + 1) * 1ll * p_pow[i]) % bpr;

	for (int i = 1; i <= n; ++i) {
		int now = i + i, cnt = 2;
		for (; now <= n && cnt <= k; now += i, ++cnt) {
			int h1 = (h[now] - h[now - i] + bpr) % bpr;
			if (to_pow (h1, now - i + 1) != to_pow (h[i], 1))
				break;
		}
		
		if (cnt == k + 1) {
			int l = now - i, r = now + 1;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				int h1 = (h[mid] - h[now - i] + bpr) % bpr;
				h1 = to_pow (h1, now - i + 1);
				int h2 = to_pow (h[mid - (now - i)], 1);
				if (h1 == h2)
					l = mid;
				else
					r = mid;
			}
			ok[now - i] += 1;
			ok[r] -= 1;
		}
	}
	
	int balance = 0;

	for (int i = 1; i <= n; ++i) {
		balance += ok[i];
		if (balance)
			putchar ('1');
		else
			putchar ('0');
	}

	return 0;
}