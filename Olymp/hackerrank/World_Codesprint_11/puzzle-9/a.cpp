#include <bits/stdc++.h>

using namespace std;

#define fe first
#define se second
#define mp make_pair
#define eb emplace_back

const int N = 25e3 + 10;

vector <int> ans[N];
pair <vector <pair <int, int> >, int> b[1515];

inline void Rotate (vector <pair <int, int> > &a) {
	int n = 0, m = 0;
	for (auto it : a) {
		n = max (n, it.fe);
		m = max (m, it.se);
	}	
	for (auto &it : a) {
		it.se = m - it.se + 1;
		swap (it.fe, it.se);
	}
}



bool cmp (const pair <vector <pair <int, int> >, int> &aa, const pair <vector <pair <int, int> >, int> &bb) {
	int na = 0, ma = 0;
	for (auto it : aa.fe) {
		na = max (na, it.fe);
		ma = max (ma, it.se);
	}	
	int nb = 0, mb = 0;
	for (auto it : bb.fe) {
		nb = max (nb, it.fe);
		mb = max (mb, it.se);
	}	
	return (na * ma < nb * mb);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	srand (time (0));


	int T;
	cin >> T;
	
	for (int i = 1; i <= T; ++i) {
		int n;
		cin >> n;
		vector <pair <int, int> > a;
		for (int i = 1; i <= n; ++i) {
			int x, y;
			cin >> x >> y;
			a.eb (mp (x, y));
		}
		b[i] = mp (a, i);	
	}

	//random_shuffle (b + 1, b + T + 1);
	sort (b + 1, b + T + 1, cmp);
	reverse (b + 1, b + T + 1);
	
	
	int old_n = 0, old_m = 0;
	for (int iter = 1; iter <= T; ++iter) {
		int it = b[iter].se;
		auto a = b[iter].fe;
		int mxn = 0, mxm = 0;
		for (auto it : a) {
			mxn = max (mxn, it.fe);
			mxm = max (mxm, it.se);
		}
		if (mxn > mxm) {
			Rotate (a);
			swap (mxn, mxm);
		}
		int oold_n = old_n, oold_m = old_m;
		old_n = max (old_n, mxn);
		old_m = max (old_m, mxm);
		for (int i = 1; i <= mxn; ++i)
			ans[i].resize (old_m + 1);

		for (int i = 0; i + mxn <= old_n; ++i) {
			for (int j = 0; j + mxm <= old_m; ++j) {
				for (int step = 1; step <= 4; ++step) {
					if (i + mxn <= old_n && j + mxm <= old_m) {
						bool gut = 1;
						for (auto x : a) {
							if (ans[i + x.fe][j + x.se] != 0)
								gut = 0;
						}
						if (gut) {
							for (auto x : a) {
								ans[i + x.fe][j + x.se] = it;
							}
							goto end;
						}
					}
					Rotate (a);
					swap (mxn, mxm);

				}

			}
		}
		{
		/*	
			old_n = oold_n;
			old_m = oold_m;
		*/			
			for (int i = 1; i <= max (old_n, mxn); ++i)
				ans[i].resize (old_m + mxm + 1);
			for (auto QQ : a) {
				ans[QQ.fe][old_m + QQ.se] = it;
			}
			old_n = max (old_n, mxn);
			old_m += mxm;
			continue;
		}		
		end:;
	}	

	cout << old_n << " " << old_m << "\n";

	for (int i = 1; i <= old_n; ++i) {
		for (int j = 1; j <= old_m; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}