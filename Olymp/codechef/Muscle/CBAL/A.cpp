#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 100, N_B = 1001, N_B1 = 670;
 
struct types {
	ll t1, t2, t3;
	types () {
		t1 = 0;
		t2 = t3 = 0;
	}
	types (const int &l1, const int &l2, const int &l3) {
		t1 = l1;
		t2 = l2;
		t3 = l3;
	}
};


int n, d[N];
string s;
types segment[N_B][N_B];
types cnt[N];
int b_num[N];
int block;
vector <int> aba;
vector <int> bii[N];
vector <types> sl[N];
map <int, int> cc;
types pref[N_B1][N];

inline types operator + (const types &t11, const types &t22) {
	return types (t11.t1 + t22.t1, t11.t2 + t22.t2, t11.t3 + t22.t3);
}

inline types operator - (const types &t11, const types &t22) {
	return types (t11.t1 - t22.t1, t11.t2 - t22.t2, t11.t3 - t22.t3);
}

inline bool cmp (const int &lhs, const int &rhs) {
	return cc[lhs] > cc[rhs];
}
 
inline void init () {
	cc[0] = 1;
	for (int i = 1; i <= n; ++i) {
		d[i] = (d[i - 1] ^ (1 << (s[i] - 'a')));
		++cc[d[i]];
	}
	aba.resize (0);
	for (auto it : cc)
		aba.push_back (it.first);
	sort (aba.begin (), aba.end (), cmp);
	for (int i = 0; i < aba.size (); ++i)
		cc[aba[i]] = i + 1;
	for (int i = 0; i <= n; ++i)
		d[i] = cc[d[i]];
	cc.clear ();
	for (int i = 0; i <= n; ++i)
		bii[d[i]].resize (0);
	for (int i = 0; i <= n; ++i)
		sl[d[i]].resize (0);
	for (int i = 0; i <= n; ++i) {
		bii[d[i]].push_back (i);
		sl[d[i]].push_back (types (1, i, i * i));
		if (bii[d[i]].size () > 1)
			sl[d[i]][bii[d[i]].size () - 1] = sl[d[i]][bii[d[i]].size () - 1] + sl[d[i]][bii[d[i]].size () - 2];
	}
	int j = 1;
	while (j <= n) {
		int st_p = j;
		for (; b_num[st_p] == b_num[j] && j <= n; ++j);
 		for (int i = st_p; i <= n; ++i) {
			segment[b_num[st_p]][b_num[i]] = segment[b_num[st_p]][b_num[i]] + types (cnt[d[i]].t1, cnt[d[i]].t1 * i - cnt[d[i]].t2, cnt[d[i]].t1 * i * i + cnt[d[i]].t3 - 2 * i * cnt[d[i]].t2);
			cnt[d[i - 1]] = cnt[d[i - 1]] + types (1, i - 1, (i - 1) * (i - 1));
		}
		for (int i = st_p; i <= n; ++i)
			cnt[d[i - 1]] = types ();
		for (int i = b_num[st_p] + 1; i <= b_num[n]; ++i)
			segment[b_num[st_p]][i] = segment[b_num[st_p]][i] + segment[b_num[st_p]][i - 1];
	}
	for (int i = 0; i < min (N_B1, (int) aba.size () + 1); ++i) {
		if (d[0] == i)
			pref[i][0] = types (1, 0, 0);
		else
			pref[i][0] = types ();
		for (int j = 1; j <= n; ++j) {
			if (d[j] == i)
				pref[i][j] = types (1, j, j * j);
			else
				pref[i][j] = types ();
			pref[i][j] = pref[i][j] + pref[i][j - 1];
		}
	}
}
 
inline types get (const int &pos, const int &element) {
	if (element < N_B1)
		return pref[element][pos];
	int it = upper_bound (bii[element].begin (), bii[element].end (), pos) - bii[element].begin ();
	if (it == 0)
		return types ();
	return sl[element][it - 1];
}
 
inline ll solve (const int &l, const int &r, const int &type) {
	ll res = 0;
	int i = l;
	types ee = types ();
	if (b_num[l] == b_num[r]) {
		for (; i <= r; ++i) {
			ee = get (r, d[i - 1]) - get (i, d[i - 1]);
			if (type == 0)
				for (; i <= r; ++i)
					res += ee.t1;
			else if (type == 1)
				for (; i <= r; ++i)
					res += ee.t2 - ee.t1 * i;
			else
				for (; i <= r; ++i)
					res += ee.t3 + ee.t1 * i * i - 2 * i * ee.t2;
		}
		return res;
	}
	for (; b_num[i] == b_num[l]; ++i) {
		ee = get (r, d[i - 1]) - get (i, d[i - 1]);
		if (type == 0)
			for (; i <= r; ++i)
				res += ee.t1;
		else if (type == 1)
			for (; i <= r; ++i)
				res += ee.t2 - ee.t1 * i;
		else
			for (; i <= r; ++i)
				res += ee.t3 + ee.t1 * i * i - 2 * i * ee.t2;
	}
	int b_s = i;
	if (type == 0)
		res += segment[b_num[l] + 1][b_num[r] - 1].t1;
	else if (type == 1)
		res += segment[b_num[l] + 1][b_num[r] - 1].t2;
	else
		res += segment[b_num[l] + 1][b_num[r] - 1].t3;
	i = r - (r % block);
	for (; i <= r; ++i) {
		ee = get (i - 1, d[i]) - get (b_s - 2, d[i]);
		if (type == 0)
			res += ee.t1;
		else if (type == 1)
			res += ee.t1 * i - ee.t2;
		else 
			res += ee.t1 * i * i + ee.t3 - 2 * i * ee.t2;
	}
	return res;
}
 
int main () {
 
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
 
	ios_base :: sync_with_stdio (0);
 
	int test;
 
	cin >> test;
	
	while (test--) {
		cin >> s;
		n = s.size ();
		block = 150;
		memset (b_num, 0, sizeof (b_num));
		for (int i = 1; i <= n; ++i)
			b_num[i] = (i / block) + 1;
		s = "#" + s;
		init ();
		int q, a = 0, b = 0;
		cin >> q;
		while (q--) {
			int x, y, type;
			cin >> x >> y >> type;
			int l = ((a + x) % n) + 1, r = ((y + b) % n) + 1;
			if (l > r)
				swap (l, r);
			ll ans = solve (l, r, type);
			a = b;
			b = ans % n;
			cout << ans << "\n";
		}
		for (int i = 0; i <= n; ++i)
			d[i] = 0;
		for (int i = 1; i <= b_num[n]; ++i)
			for (int j = 1; j <= b_num[n]; ++j)
				segment[i][j] = types ();
	}
 
	return 0;
}  