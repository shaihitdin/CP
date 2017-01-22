#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <int> big;

const int oo = 1e9, N = 1e5 + 100, BASE = 1e9;


inline big operator + (const vector <int> &a, const vector <int> &b) {
	vector <int> c;

	c.resize (max (a.size (), b.size ()));
	c.emplace_back (0);

	for (int i = 0; i < c.size (); ++i) {
		if (i < a.size ())
			c[i] += a[i];
		if (i < b.size ())
			c[i] += b[i];
		if (c[i] >= BASE) {
			c[i + 1] += 1;
			c[i] -= BASE;
		}
	}

	while (c.size () && c.back () == 0)
		c.pop_back ();

	if (!c.size ())
		c.emplace_back (0);

	return c;
}

inline big nw (int x) {
	vector <int> res;
	while (x) {
		res.emplace_back (x % BASE);
		x /= BASE;
	}
	reverse (res.begin (), res.end ());
	if (!res.size ())
		res.emplace_back (0);
	return res;
}

inline big operator * (const vector <int> &a, int b) {
	if (!b) {
		return nw (0);
	}
	if (b & 1)
		return a + (a * (b - 1));
	auto c = a * (b / 2);
	return c + c;
}

inline bool cmp2 (const vector <int> &a, const vector <int> &b) {
	if (a.size () == b.size ()) {
		int i = int (a.size ()) - 1;
		for (; i >= 0 && a[i] == b[i]; --i);
		if (i == -1 || a[i] > b[i])
			return 0;
		else
			return 1;
	}
	return a.size () < b.size ();
}

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

big sum[10];

inline bool cmp (const string &x, const string &y) {
	return x.size () < y.size ();
}


big dp[2][1024];

string s[N];
int n;
bool banned[10];

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		if (s[i].size () > 1)
			banned[s[i][0] - 'a'] = 1;
	}
	
	sort (s + 1, s + n + 1, cmp);
	
	big now = nw (1);
	for (int i = 0, j = 1; i <= 1e5; ++i, now = now * 10) {
		while (j <= n && s[j].size () <= i) ++j;
		for (int k = j; k <= n; ++k) {
			sum[s[k][i] - 'a'] = (sum[s[k][i] - 'a'] + now);
		}
	}
	
	for (int mask = 0; mask < (1 << 10); ++mask) {
		if (__builtin_popcount (mask) != 5)
			continue;
		vector <int> perm;
		for (int i = 0; i < 10; ++i)
			if (bit (mask, i))
				perm.emplace_back (i);
		for (;;) {
			if (banned[perm[0]]) {
				if (!next_permutation (perm.begin (), perm.end ()))
					break;
				continue;
			}
			big res = nw (0);
			for (int i = 0; i < perm.size (); ++i)
				res = (res + (sum[perm[i]] * i));
			if (cmp2 (dp[0][mask], res))
				dp[0][mask] = res;
			if (!next_permutation (perm.begin (), perm.end ()))
				break;
		}
		for (;;) {
			big res = nw (0);
			for (int i = 0; i < perm.size (); ++i)
				res = (res + (sum[perm[i]] * (i + 5)));
			if (cmp2 (dp[1][mask], res))
				dp[1][mask] = res;
			if (!next_permutation (perm.begin (), perm.end ()))
				break;
		}
	}
	
	big ans = nw (0);
	
	for (int mask = 0; mask < (1 << 10); ++mask) {
		if (__builtin_popcount (mask) != 5)
			continue;
		if (cmp2 (ans, dp[0][mask] + dp[1][((1 << 10) - 1) ^ mask]))
			ans = dp[0][mask] + dp[1][((1 << 10) - 1) ^ mask];
	}

	ans = ans + nw (0);
	
	reverse (ans.begin (), ans.end ());

	for (int i : ans)
		cout << i << " ";
	
	return 0;
}