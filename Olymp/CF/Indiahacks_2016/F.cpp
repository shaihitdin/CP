#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define prev notprev

const int N = 5e5 + 100, sz = (1 << 20), oo = 1e9;

int prev[N];
int cnt[N], p[N], pn[N], c[N], cn[N];
string s;
int t[sz + sz + 100];
int bracketb[N];
int n, lcp[N];

inline int num (char x) {
	return x == ')';
}

vector <int> g[N + N];

inline void upd (int x, int delta) {
	t[x += sz] = delta;
	while (x >>= 1)
		t[x] = min (t[x + x], t[x + x + 1]);
}

inline int get (int l, int r) {
	int res = oo;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = min (res, t[l++]);
		if (!(r & 1))
			res = min (res, t[r--]);
		if (l > r)
			break;
	}
	return res;
}

inline int calc (int l, int r) {
	if (r < l)
		return 0;
	int x = (l == 0) ? N : bracketb[l - 1];
	int l_bin = l - 1, r_bin = r + 1;
	while (r_bin - l_bin > 1) {
		int mid = (r_bin + l_bin) >> 1;
		if (get (l, mid) >= x)
			l_bin = mid;
		else
			r_bin = mid;
	}
	return upper_bound (g[x].begin (), g[x].end (), l_bin) - lower_bound (g[x].begin (), g[x].end (), l - 1) - 1;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	cin >> s;

	s += '#';
	++n;
/*
	for (int i = 0; i < n; ++i)
		cerr << s[i] << " ";
	cerr << "\n";
*/		
	for (int i = 0; i < n - 1; ++i)
		++cnt[(c[i] = num (s[i]) + 1) + 1];
	cnt[0] = 1;
	cnt[1] += cnt[0];
	cnt[2] += cnt[1];
	cnt[3] += cnt[2];
	p[0] = n - 1;
	c[n - 1] = 0;
	for (int i = 0; i < n - 1; ++i)
		p[cnt[num (s[i]) + 1]++] = i;
	
	for (int pw = 0; (1 << pw) <= n; ++pw) {
		memset (cnt, 0, sizeof (cnt));
		memset (cn, 0, sizeof (cn));
		memset (pn, 0, sizeof (pn));
		for (int i = 0; i < n; ++i)
			++cnt[c[i] + 1];
		for (int i = 1; i < n; ++i)
			cnt[i] += cnt[i - 1];
		/*
		for (int i = 0; i < n; ++i) {
			cerr << p[i] << " ";
		}
		cerr << "\n";
		*/
		for (int i = 0; i < n; ++i) {
			int tbek = p[i] - (1 << pw);
			while (tbek < 0)
				tbek += n;
			pn[cnt[c[tbek]]++] = tbek;
		}
		for (int i = 1; i < n; ++i) {
			int pos11 = pn[i - 1], pos12 = (pn[i - 1] + (1 << pw)), pos21 = pn[i], pos22 = pn[i] + (1 << pw);
			while (pos12 >= n)
				pos12 -= n;
			while (pos22 >= n)
				pos22 -= n;
			if (c[pos11] == c[pos21] && c[pos12] == c[pos22])
				cn[pos21] = cn[pos11];
			else
				cn[pos21] = cn[pos11] + 1;
		}
		memcpy (c, cn, sizeof (cn));
		memcpy (p, pn, sizeof (pn));
	}

	for (int i = 0; i < n; ++i)
		prev[p[i]] = i;
	
	for (int i = 0, k = 0; i < n; lcp[prev[i++]] = k) {
		int pos = prev[i];
		if (pos == 0) {
			k = 0;
			continue;
		}
		int x = p[pos - 1];
		k = max (0, k - 1);
		while (x + k < n && i + k < n && s[x + k] == s[i + k])	++k;
	}
	
	g[N].emplace_back (-1);
	
	for (int i = 0, balance = N; i < n - 1; ++i) {
		if (s[i] == '(')
			++balance;
		else
			--balance;
		g[balance].emplace_back (i);
		bracketb[i] = balance;
		upd (i, balance);
	}

	ll ans = calc (p[0], n - 2);
/*
	for (int i = 0; i < n; ++i) {
		cerr << p[i] << " ";
	}
	
	cerr << "\n";

	for (int i = 0; i < n; ++i) {
		cerr << lcp[i] << " ";
	}
	
	cerr << "\n";
*/
	for (int i = 1; i < n - 1; ++i) {
		ans += calc (p[i], n - 2) - calc (p[i - 1], min (p[i - 1] + lcp[i] - 1, n - 2));
		//cerr << p[i] << " " << p[i - 1] << " " << calc (p[i], n - 2) << " " << calc (p[i - 1], min (p[i - 1] + lcp[i] - 1, n - 2)) << "\n";
	}
	
	cout << ans;
	
	return 0;
}