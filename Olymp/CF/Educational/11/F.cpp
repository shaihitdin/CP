/// izizi

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);

#define mp make_pair
  
const int oo = 1e9, bpr = 1e9 + 7, N = 3e5 + 100, sz = 1 << 18;

typedef pair <ll, ll> line;

vector <line> cc[sz + sz + 100], st[sz + sz + 100];

int n;
ll a[N], d[3][N]; 

inline ld intersection (const line &x, const line &y) {
	if (x.first == y.first)
		assert (0);
	return (y.second - x.second) / ld (x.first - y.first);
}

inline ll optimus (vector <line> &st, int x) {
	/*
	ll val = -1e18;
	for (auto it : st)
		val = max (val, it.first * x + it.second);
	return val;
	*/
	if (!st.size ())
		return -1e18;
	int l = -1, r = st.size () - 1;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (intersection (st[mid], st[mid + 1]) < x)
			l = mid;
		else
			r = mid;
	}
	l -= 5;
	r += 5;
	ll val = -1e18;
	for (int i = max (0, l); i <= min ((int)st.size () - 1, r); ++i)
		val = max (val, st[i].first * x + st[i].second);
	return val;
}

inline ll optimus (int l, int r, int x) {
	ll res = -1e18;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res = max (res, optimus (st[l++], x));
		if (!(r & 1)) res = max (res, optimus (st[r--], x));
		if (l > r)	break;
	}
	return res;
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i)
		d[1][i] = d[1][i - 1] + a[i], d[2][i] = d[2][i - 1] + a[i] * 1ll * i;
	
	for (int i = 1; i <= n; ++i) {
		cc[i + sz].emplace_back (mp (-d[1][i], d[2][i]));
		st[i + sz] = cc[i + sz];
	}	
	
	for (int i = sz - 1; i >= 1; --i) {
		cc[i].resize (cc[i + i].size () + cc[i + i + 1].size ());
		merge (cc[i + i].begin (), cc[i + i].end (), cc[i + i + 1].begin (), cc[i + i + 1].end (), cc[i].begin ());
		for (auto it : cc[i]) {
			if (st[i].size () == 1 && st[i].back ().first == it.first) {
				st[i].pop_back ();
				st[i].emplace_back ();
				continue;
			}
			while (st[i].size () > 1 && (st[i][st[i].size () - 1].first == it.first || 
			intersection (st[i][st[i].size () - 2], it) < intersection (st[i][st[i].size () - 2], st[i][st[i].size () - 1])))
				st[i].pop_back ();
			st[i].emplace_back (it);
		}
	}
	
	ll ans = 0;
	
	for (int i = n; i >= 1; --i) {
		ans = max (ans, -d[2][i - 1] + d[1][i - 1] * (i - 1) + optimus (i, n, i - 1));
	}
	cout << ans;
	
	return 0;
}