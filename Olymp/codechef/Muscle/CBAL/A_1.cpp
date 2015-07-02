#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 100, N_B = 3001, N_B1 = 530;
 
struct types {
	ll t0, t1, t2;
	types () {
		t0 = t1 = t2 = 0;
	}
	types (const ll &tt1, const ll &tt2, const ll &tt3) {
		t0 = tt1;
		t1 = tt2;
		t2 = tt3;
	}
};
 
inline types operator + (const types &t1, const types &t2) {
	return types (t1.t0 + t2.t0, t1.t1 + t2.t1, t1.t2 + t2.t2);
}
 
inline types operator - (const types &t1, const types &t2) {
	return types (t1.t0 - t2.t0, t1.t1 - t2.t1, t1.t2 - t2.t2);
}
 
int n, d[N];
string s;
types segment[N_B][N_B];
types cnt[N];
int b_num[N];
int block;
vector <int> aba;
vector <int> bii[N];
vector <types> position[N];
map <int, int> cc;
types pref[N_B1][N];
 
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
	for (int i = 0; i <= n; ++i) {
		bii[d[i]].resize (0);
		position[d[i]].resize (0);
	}
	for (int i = 0; i <= n; ++i) {
		bii[d[i]].push_back (i);
		if (position[d[i]].size ())
			position[d[i]].push_back (position[d[i]].back () + types (1, i, 1ll * i * i));
		else
			position[d[i]].push_back (types (1, i, 1ll * i * i));
	}
	
	for (int i = 0; i < min (N_B1, (int) aba.size () + 1); ++i) {
		if (d[0] == i)
			pref[i][0] = types (1, 0, 0);
		else
			pref[i][0] = types (0, 0, 0);
		for (int j = 1; j <= n; ++j) {
			if (d[j] == i)
				pref[i][j] = types (1, j, 1ll * j * j);
			else
				pref[i][j] = types (0, 0, 0);
			pref[i][j] = pref[i][j - 1] + pref[i][j];
		}
	}
	
	int j = 1;
	while (j <= n) {
		int st_p = j;
		for (; b_num[st_p] == b_num[j] && j <= n; ++j);
 
		for (int i = st_p; i <= n; ++i) {
			segment[b_num[st_p]][b_num[i]] = segment[b_num[st_p]][b_num[i]] + types (cnt[d[i]].t0, cnt[d[i]].t0 * i - cnt[d[i]].t1, cnt[d[i]].t2 + cnt[d[i]].t0 * i * i - 2 * i * cnt[d[i]].t1);
			cnt[d[i - 1]] = cnt[d[i - 1]] + types (1, i - 1, 1ll * (i - 1) * (i - 1));
		}
		for (int i = st_p; i <= n; ++i)
			cnt[d[i - 1]] = types (0, 0, 0);
		for (int i = b_num[st_p] + 1; i <= b_num[n]; ++i)
			segment[b_num[st_p]][i] = segment[b_num[st_p]][i] + segment[b_num[st_p]][i - 1];
	}
}
 
inline types get (const int &pos, const int &element) {
	if (element < N_B1)
		return pref[element][pos];
	int it = upper_bound (bii[element].begin (), bii[element].end (), pos) - bii[element].begin ();
	if (it == 0)
		return types (0, 0, 0);
	return position[element][it - 1];
}
 
inline ll solve (const int &l, const int &r, const int &type) {
	ll res = 0;
	int i = l;
	if (b_num[l] == b_num[r]) {
		for (; i <= r; ++i) {
			types ee = get (r, d[i - 1]) - get (i, d[i - 1]);
			if (type == 0)
				res += ee.t0;
			else if (type == 1)
				res += ee.t1 - ee.t0 * (i - 1);
			else if (type == 2)
				res += ee.t2 - 2 * i * ee.t1 + 2 * ee.t1 + ee.t0 * i * i - ee.t0 * 2 * i + ee.t0;
		}
		return res;
	}
	for (; b_num[i] == b_num[l]; ++i) {
		types ee = get (r, d[i - 1]) - get (i, d[i - 1]);
		if (type == 0)
			res += ee.t0;
		else if (type == 1)
			res += ee.t1 - ee.t0 * (i - 1);
		else if (type == 2)
			res += ee.t2 - 2 * i * ee.t1 + 2 * ee.t1 + ee.t0 * i * i - ee.t0 * 2 * i + ee.t0;
	}
	int b_s = i;
	if (type == 0)
		res += segment[b_num[l] + 1][b_num[r] - 1].t0;
	if (type == 1)
		res += segment[b_num[l] + 1][b_num[r] - 1].t1;
	if (type == 2)
		res += segment[b_num[l] + 1][b_num[r] - 1].t2;
 
	i = r - (r % block);
	for (; i <= r; ++i) {
		types ee = get (i - 1, d[i]) - get (b_s - 2, d[i]);
		if (type == 0)
			res += ee.t0;
		if (type == 1)
			res += i * ee.t0 - ee.t1;
		if (type == 2)
			res += ee.t0 * i * i - 2 * i * ee.t1 + ee.t2;
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
		for (int i = 1; i <= n; ++i)
			b_num[i] = (i / block) + 1;
		b_num[n + 1] = 0;
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
				segment[i][j] = types (0, 0, 0);
	}
 
	return 0;
}    