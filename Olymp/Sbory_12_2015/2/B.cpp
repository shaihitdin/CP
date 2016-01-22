#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 17;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}
ld c1[1 << 16], c2[1 << 16]; // c1 - decline, c2 - accept
int cdf[1 << 16];

struct bribe {
	int money;
	double prob;
};

inline bool cmp0 (const bribe &a, const bribe &b) {
	return a.money < b.money;
}

inline bool cmp1 (const bribe &a, const bribe &b) {
	return a.prob < b.prob;
}

inline bool cmp2 (const bribe &a, const bribe &b) {
	return a.money * a.prob < b.money * b.prob;
}

ld d[18][1100][18];

inline void calc (vector <bribe> v) {
	for (int i = 0; i < 18; ++i)
		for (int j = 0; j < 1100; ++j)
			for (int k = 0; k < 18; ++k)
				d[i][j][k] = 0;
	for (int i = 0; i <= 1100; ++i)
		d[v.size ()][i][0] = 1;
	for (int suff = v.size () - 1; suff >= 0; --suff) {
		for (int j = 0; j <= 1000; ++j) {
			for (int k = v.size (); k >= 0; --k) {
				d[suff][j][k] = max (d[suff][j][k], d[suff + 1][j][k]);
				if (j > 0)
					d[suff][j][k] = max (d[suff][j][k], d[suff][j - 1][k]);
				if (j >= v[suff].money && k > 0)
					d[suff][j][k] = max (d[suff][j][k], d[suff + 1][j - v[suff].money][k - 1] * v[suff].prob + d[suff + 1][j - v[suff].money][k] * (1 - v[suff].prob));
				
			}
		}
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int t_num;

	cin >> t_num;

	cout.precision (7);
	cout << fixed;
	
	while (t_num--) {
		int n, c, m;
		cin >> n >> c >> m;
		vector <bribe> v;
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			v.push_back ({x, y / 100.0});
		}
		sort (v.begin (), v.end (), cmp0);
		calc (v);
		ld ans = d[0][m][c];
		sort (v.begin (), v.end (), cmp1);
		calc (v);
		ans = max (ans, d[0][m][c]);
		sort (v.begin (), v.end (), cmp2);
		calc (v);
		ans = max (ans, d[0][m][c]);
		cout << ans << "\n";
	}

	return 0;
}