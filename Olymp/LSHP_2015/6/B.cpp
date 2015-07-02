#include <bits/stdc++.h>

using namespace std;

const int N = 32, inf = 1e9;

struct state {
	int a[N];
	int res;
	vector <int> mg[4];
} cur, nxt, best;

int d[N][4][4];
int p[2][N][4][4];

inline int exc (const int &i, const int &j) {
	if (i != 1 && j != 1)
		return 1;
	if (i != 2 && j != 2)
		return 2;
	if (i != 3 && j != 3)
		return 3;
	assert (0);
}

int n;
int a[N][4];

inline void calc (state &cur) {
	cur.res = 0;

	for (int i = 1; i <= n; ++i) {
		int co = cur.a[i];
		for (int j = 1; j <= 3; ++j) {
			for (int k = 1; k <= 3; ++k) {
				if (j == k)
					continue;
				int zz = exc (j, k);
				d[i][j][k] = a[co][zz];
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		int co = cur.a[i];
		int prev = cur.a[i - 1];
		for (int j = 1; j <= 3; ++j) {
		for (int k = 1; k <= 3; ++k) {
			if (j == k)
				continue;
			int zz = exc (j, k);
			for (int j1 = 1; j1 <= 3; ++j1) {
			for (int k1 = 1; k1 <= 3; ++k1) {
				if (j1 == k1)
					continue;
				if (a[co][j] > a[prev][j1] || a[co][k] > a[prev][k1])
					continue;
				if (d[i][j][k] < d[i - 1][j1][k1] + a[co][zz]) {
					d[i][j][k] = d[i - 1][j1][k1] + a[co][zz];
					p[0][i][j][k] = j1;
					p[1][i][j][k] = k1;
				}
			}
			}
		}
		}
	}

	int mxs = -1, mxi, mxj, mxk;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			for (int k = 1; k <= 3; ++k) {
				if (mxs < d[i][j][k]) {
					mxs = d[i][j][k];
					mxi = i;
					mxj = j;
					mxk = k;
				}
			}
		}
	}

	cur.res = mxs;
	
	cur.mg[0].resize (0);
	cur.mg[1].resize (0);
	cur.mg[2].resize (0);
	cur.mg[3].resize (0);
	
	while (mxs > 0) {
		int co = cur.a[mxi];
		cur.mg[0].emplace_back (co);
		cur.mg[1].emplace_back (a[co][mxj]);
		cur.mg[2].emplace_back (a[co][mxk]);
		int zz = exc (mxj, mxk);
		cur.mg[3].emplace_back (a[co][zz]);
		mxs -= a[co][zz];
		int n_mxj = p[0][mxi][mxj][mxk], n_mxk = p[1][mxi][mxj][mxk];
		--mxi;
		mxj = n_mxj;
		mxk = n_mxk;
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	srand (time (0));
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		sort (a[i] + 1, a[i] + 4);
	}

	for (int i = 1; i <= n; ++i)
		cur.a[i] = i;


	calc (cur);
	
	best = cur;

	double t = n, alpha = 0.99;
	best = cur;

	for (int till = 1; till <= 850000; ++till) {
		nxt = cur;
		for (int i = 0; i <= int (t); ++i)
			swap (nxt.a[rand () % n + 1], nxt.a[rand () % n + 1]);
		calc (nxt);
		double d = (int)(cur.res - nxt.res);
		if (d < 0 || exp ((-d) / t) > (rand () % 1024) / 1024)
			cur = nxt;
		if (cur.res > best.res) best = cur;
		t *= alpha;
	}
	
	reverse (best.mg[0].begin (), best.mg[0].end ());
	reverse (best.mg[1].begin (), best.mg[1].end ());
	reverse (best.mg[2].begin (), best.mg[2].end ());
	reverse (best.mg[3].begin (), best.mg[3].end ());

	cout << best.res << "\n" << best.mg[0].size () << "\n";

	for (int i = 0; i < best.mg[0].size (); ++i)
		cout << best.mg[0][i] << " " << best.mg[1][i] << " " << best.mg[2][i] << " " << best.mg[3][i] << "\n";
	
	return 0;
}