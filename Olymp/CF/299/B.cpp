#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, bpr = 1e9 + 7, p1 = 31, p2 = 37;

int h[N], h1[N], p_pow1[N], p_pow2[N];

int n, m;

string s;

bool can[N];

int st[N];

inline int to_pow1 (const int &hash, const int &ppow) {
	return (hash * 1ll * p_pow1[N - 1 - ppow]) % bpr;
}

inline int to_pow2 (const int &hash, const int &ppow) {
	return (hash * 1ll * p_pow2[N - 1 - ppow]) % bpr;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	p_pow1[0] = p_pow2[0] = 1;
	
	for (int i = 1; i < N; ++i)
		p_pow1[i] = (p_pow1[i - 1] * 1ll * p1) % bpr, p_pow2[i] = (p_pow2[i - 1] * 1ll * p2) % bpr;

	cin >> n >> m;

	cin >> s;

	for (int i = 0; i < s.size (); ++i) {
		h[i] = ((s[i] - 'a' + 1) * 1ll * p_pow1[i]) % bpr;
		h1[i] = ((s[i] - 'a' + 1) * 1ll * p_pow2[i]) % bpr;
		if (i > 0)
			h[i] = (h[i] + h[i - 1]) % bpr, h1[i] = (h1[i] + h1[i - 1]) % bpr;
	}

	for (int i = 0; i < s.size (); ++i) {
		int hp = h[i], hs;
		int hp1 = h1[i], hs1;
		if (i + 1 == s.size ()) {
			hs = h[i];
			hs1 = h1[i];
		} else {
			hs = (h[s.size () - 1] - h[s.size () - 1 - (i + 1)] + bpr) % bpr;
			hs1 = (h1[s.size () - 1] - h1[s.size () - 1 - (i + 1)] + bpr) % bpr;
		}
		
		hp = to_pow1 (hp, 0);
		hs = to_pow1 (hs, s.size () - 1 - i);

		hp1 = to_pow2 (hp1, 0);
		hs1 = to_pow2 (hs1, s.size () - 1 - i);
		
		if (hp == hs && hp1 == hs1)
			can[i] = 1;
	}
	
	int len = s.size ();

	for (int i = 1, last, now; i <= m; ++i, last = now) {
		cin >> now;
		++st[now];
		if (i == 1)
			continue;
		if (last + len - 1 >= now && !can[last + len - 1 - now]) {
			cout << 0;
			return 0;
		}
	}

	int now = 0, need = 0;
	
	for (int i = 1; i <= n; ++i) {
		now += st[i];
		if (!now)
			++need;
		if (i >= len)
			now -= st[i - len + 1];
	}

	int ans = 1;
	
	for (; need; --need)
		ans = (ans * 1ll * 26) % bpr;
	
	cout << ans;

	return 0;
}