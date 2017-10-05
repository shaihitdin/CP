#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fe first
#define se second
#define mp make_pair
#define int ll

const int N = 2050;
const ll oo = 1e18;
const int bpr = 1e9 + 7;


int a[N][N], n;

inline vector <ll> slow (int n, int a[N][N], bool debug = 0) {
	assert (n <= 10);
	vector <ll> ans;
	ans.resize (n + 1);
	for (int i = 1; i <= n; ++i)
		ans[i] = oo;
	int b[n + 1];
	for (int i = 1; i <= n; ++i)
		b[i] = i;
	do {
		ll res = 0;
		int tmp = 1e9 + 7;
		for (int i = n - 1; i >= 1; --i) {
			tmp = min (tmp, a[b[i]][b[i + 1]]);
			res += tmp;
		}
		ans[b[n]] = min (ans[b[n]], res);
		if (debug == 1 && b[n] == 4 && res == ans[b[n]]) {
			for (int i = 1; i <= n; ++i)
				cerr << b[i] << " ";
			cerr << "\n" << res << "\n";
		}
	} while (next_permutation (b + 1, b + n + 1));
	return ans;
}



inline vector <ll> med (int n, int a[N][N], bool debug = 0) {
	/// (n) ... -> (4) -> (3) -> (2) -> (1)
	if (n <= 4) {
		return slow (n, a);
	}
	vector <ll> ans;
	ans.resize (n + 1);
	for (int i = 1; i <= n; ++i)
		ans[i] = oo;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			ll tmp = (n - 1) * 1ll * a[i][j];
			ans[i] = min (ans[i], tmp);
		}
	}
	/// 4 -> 3
	pair <int, int> b[N][N];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) {
				b[i][i] = mp (oo, i);
				continue;
			}				
			b[i][j] = mp (a[i][j], j);
		}
		random_shuffle (b[i] + 1, b[i] + n + 1);
		nth_element (b[i] + 1, b[i] + 2, b[i] + n + 1);
	}	
	
	/// 3 -> 2
	pair <int, int> c[N];
		/// (2) (4 -> 3)
	for (int i = 1; i <= n; ++i) {
		pair <int, int> x;
		x = mp (oo, 0);
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			x = min (x, mp (b[j][1].fe * (n - 3) + a[i][j], j));
		}
		assert (x.se != 0);
		c[i] = x;
	}
	pair <int, int> d[N];
		/// (2) (second 3)
	for (int i = 1; i <= n; ++i) {
		pair <int, int> x;
		x = mp (oo, 0);
		for (int j = 1; j <= n; ++j) {
			if (j == i || j == c[i].se) 
				continue;
			x = min (x, mp (b[j][1].fe * (n - 3) + a[i][j], j));
		}
		assert (x.se != 0);
		d[i] = x;
	}
	/// (1) (2)	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;					
			if (b[c[j].se][1].se == i) { /// 1 = 4
				ll tmp = 0;
				tmp = b[c[j].se][2].fe * (n - 3) + min (a[j][c[j].se], a[i][j]) + a[i][j];
				ans[i] = min (ans[i], tmp);
				tmp = d[j].fe + a[i][j];
				ans[i] = min (ans[i], tmp);
			} else if (c[j].se == i) { /// 1 = 3
				ll tmp = 0;
				tmp = d[j].fe + a[i][j];
				ans[i] = min (ans[i], tmp);
			} else {
				ll tmp = 0;
				tmp = c[j].fe + a[i][j];
				ans[i] = min (ans[i], tmp);
			}
		}
	}

	
	/// 3 -> 2
	pair <int, int> c2[N];
		/// (2) (4 -> 3)
	for (int i = 1; i <= n; ++i) {
		pair <int, int> x;
		x = mp (oo, 0);
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			x = min (x, mp (b[j][1].fe * (n - 3), j));
		}
		assert (x.se != 0);
		c2[i] = x;
	}
	pair <int, int> d2[N];
		/// (2) (second 3)
	for (int i = 1; i <= n; ++i) {
		pair <int, int> x;
		x = mp (oo, 0);
		for (int j = 1; j <= n; ++j) {
			if (j == i || j == c[i].se) 
				continue;
			x = min (x, mp (b[j][1].fe * (n - 3), j));
		}
		assert (x.se != 0);
		d2[i] = x;
	}
	/// (1) (2)	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;			
			if (b[c[j].se][1].se == i) { /// 1 = 4
				ll tmp = 0;
				tmp = b[c[j].se][2].fe * (n - 3) + min (a[j][c[j].se], a[i][j]) + a[i][j];
				ans[i] = min (ans[i], tmp);
				tmp = d2[j].fe + 2 * a[i][j];
				ans[i] = min (ans[i], tmp);
			} else if (c[j].se == i) { /// 1 = 3
				ll tmp = 0;
				tmp = d2[j].fe + 2 * a[i][j];
				ans[i] = min (ans[i], tmp);
			} else {
				ll tmp = 0;
				tmp = c2[j].fe + 2 * a[i][j];
				ans[i] = min (ans[i], tmp);
			}
		}
	}

	return ans;
}

inline void gen_input () {
	n = 2 + rand () % 4;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int x;
			x = 1 + rand () % 100;
			a[i][j] = x;
		}
		for (int j = 1; j < i; ++j)
			a[i][j] = a[j][i];
	}
}

inline void read_input () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int x;
			cin >> x;
			a[i][j] = x;
		}
		for (int j = 1; j < i; ++j)
			a[i][j] = a[j][i];
	}
}

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
/*
	read_input ();

	auto ans_fast = med (n, a);

	for (int i = 1; i <= n; ++i)
		cout << ans_fast[i] << "\n";
*/
	while (1) {
		gen_input ();	
			
		vector <ll> ans_slow, ans_fast;
	
		ans_slow = slow (n, a);
		ans_fast = med (n, a);
		if (ans_slow != ans_fast) {
			cout << n << "\n";
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					cout << a[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n\n\n";
			for (int i = 1; i <= n; ++i)
				cout << ans_slow[i] << " ";
			cout << "\n";
			for (int i = 1; i <= n; ++i)	
				cout << ans_fast[i] << " ";	
			slow (n, a, 1);
			return 0;
		}
	}	

	return 0;
}