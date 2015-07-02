#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 2, N_B = 545;
 
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
char s[N];
types segment[N_B][N_B];
types cnt[N / 2];
int b_num[N];
int block;
vector <int> aba;
map <int, int> cc;
types git[N_B][N / 2];
 
inline void init () {
	cc[0] = 1;
	for (int i = 1; i <= n; ++i) {
		d[i] = (d[i - 1] ^ (1 << (s[i - 1] - 'a')));
		cc[d[i]] = 1;
	}
	aba.resize (0);
	for (auto it : cc)
		aba.push_back (it.first);
	sort (aba.begin (), aba.end ());
	for (int i = 0; i < aba.size (); ++i)
		cc[aba[i]] = i + 1;
	for (int i = 0; i <= n; ++i)
		d[i] = cc[d[i]];
	cc.clear ();
	for (int i = 1; i <= b_num[n]; ++i)
		for (int j = 1; j <= aba.size (); ++j)
			git[i][j] = types ();
	for (int i = 0; i <= n; ++i)
		git[b_num[i]][d[i]] = git[b_num[i]][d[i]] + types (1, i, 1ll * i * i);
	for (int i = 1; i <= b_num[n]; ++i)
		for (int j = 1; j <= aba.size (); ++j)
			git[i][j] = git[i][j] + git[i - 1][j];
	int j = 1;
	while (j <= n) {
		int st_p = j;
		for (int i = st_p; i <= n; ++i) {
			segment[b_num[st_p]][b_num[i]] = segment[b_num[st_p]][b_num[i]] + 
			types (cnt[d[i]].t0, 
			cnt[d[i]].t0 * i - (cnt[d[i]].t1 - cnt[d[i]].t0), 
			cnt[d[i]].t2 + cnt[d[i]].t0 * i * i - 2 * i * cnt[d[i]].t1 + 2 * cnt[d[i]].t0 * i - 2 * cnt[d[i]].t1 + cnt[d[i]].t0);
 
			cnt[d[i - 1]] = cnt[d[i - 1]] + types (1, i, 1ll * i * i);
		}
		for (int i = st_p; i <= n; ++i)
			cnt[d[i - 1]] = types ();
		for (int i = b_num[st_p] + 1; i <= b_num[n]; ++i)
			segment[b_num[st_p]][i] = segment[b_num[st_p]][i] + segment[b_num[st_p]][i - 1];
		j = (j - (j % block)) + block;
	}
}
 
inline types get (const int &r, const int &l, const int &element) {
	if (b_num[r] - 1 < b_num[l] + 1)
		return types ();
	return git[b_num[r] - 1][element] - git[b_num[l]][element];
}
 
types cnt1[N / 2];
 
inline ll solve (const int &l, const int &r, const int &type) {
	ll res = 0;
	int i = l;
	if (b_num[l] == b_num[r]) {
		for (int j = l; j <= r; ++j)
			cnt1[d[j]] = cnt1[d[j]] + types (1, j, 1ll * j * j);
		for (; i <= r; ++i) {
			types ee = cnt1[d[i - 1]];
			if (type == 0)
				res += ee.t0;
			else if (type == 1)
				res += ee.t1 - ee.t0 * (i - 1);
			else if (type == 2)
				res += ee.t2 - 2 * i * ee.t1 + 2 * ee.t1 + ee.t0 * i * i - ee.t0 * 2 * i + ee.t0;
			cnt1[d[i]] = cnt1[d[i]] - types (1, i, 1ll * i * i);
		}
		return res;
	}
	
	for (int j = l; b_num[j] == b_num[l]; ++j)
		cnt1[d[j]] = cnt1[d[j]] + types (1, j, 1ll * j * j);
	for (int j = r - (r % block); j <= r; ++j)
		cnt1[d[j]] = cnt1[d[j]] + types (1, j, 1ll * j * j);
 
	for (; b_num[i] == b_num[l]; ++i) {
		types ee = get (r, i, d[i - 1]) + cnt1[d[i - 1]];
		if (type == 0)
			res += ee.t0;
		else if (type == 1)
			res += ee.t1 - ee.t0 * (i - 1);
		else if (type == 2)
			res += ee.t2 - 2 * i * ee.t1 + 2 * ee.t1 + ee.t0 * i * i - ee.t0 * 2 * i + ee.t0;
		cnt1[d[i]] = cnt1[d[i]] - types (1, i, 1ll * i * i);
	}
 
	for (int j = r - (r % block); j <= r; ++j)
		cnt1[d[j]] = types ();
	
	int b_s = i;
	if (type == 0)
		res += segment[b_num[l] + 1][b_num[r] - 1].t0;
	if (type == 1)
		res += segment[b_num[l] + 1][b_num[r] - 1].t1;
	if (type == 2)
		res += segment[b_num[l] + 1][b_num[r] - 1].t2;
 
	i = r - (r % block);
 
	cnt1[d[b_s - 1]] = types (1, b_s - 1, 1ll * (b_s - 1) * (b_s - 1));
	
	for (; i <= r; ++i) {
		types ee = get (i, b_s - 1, d[i]) + cnt1[d[i]];
		if (type == 0)
			res += ee.t0;
		if (type == 1)
			res += i * ee.t0 - ee.t1;
		if (type == 2)
			res += ee.t0 * i * i - 2 * i * ee.t1 + ee.t2;
		cnt1[d[i]] = cnt1[d[i]] + types (1, i, 1ll * i * i);
	}
 
	cnt1[d[b_s - 1]] = types ();
	for (int j = r - (r % block); j <= r; ++j)
		cnt1[d[j]] = types ();
	
	return res;
}
 
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	int test;
 
	scanf ("%d\n", &test);
 
	while (test--) {
		scanf ("%s\n", s);
		n = strlen (s);
		block = 185;
		for (int i = 0; i <= n; ++i)
			b_num[i] = (i / block) + 1;
		b_num[n + 1] = 0;
		init ();
		int q, a = 0, b = 0;
		scanf ("%d\n", &q);
		while (q--) {
			int x, y, type;
			scanf ("%d%d%d\n", &x, &y, &type);
			int l = ((a + x) % n) + 1, r = ((y + b) % n) + 1;
			if (l > r)
				swap (l, r);
			ll ans = solve (l, r, type);
			a = b;
			b = ans % n;
			printf ("%lld\n", ans);
		}
		d[0] = 0;
		for (int i = 1; i <= b_num[n]; ++i)
			for (int j = 1; j <= b_num[n]; ++j)
				segment[i][j] = types ();
	}
 
	return 0;
}      