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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100, K = 17, MAGIC = 63, S = 3;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

typedef vector <vector <int> > matrix;

int tin[N], tout[N], timer;
int go[N][K], lvl[N];
vector <int> g[N];

inline void dfs (const int &v, const int &p) {
	go[v][0] = p;
	tin[v] = ++timer;
	lvl[v] = lvl[p] + 1;
	for (int i = 1; i < K; ++i)
		go[v][i] = go[go[v][i - 1]][i - 1];
	for (auto to : g[v])
		dfs (to, v);
	tout[v] = ++timer;
}

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline int get_p (int v, const int &step) {
	for (int i = 0; i < K; ++i)
		if (bit (step, i))
			v = go[v][i];
	return v;
}

inline int lca (int a, int b) {
	if (lvl[a] < lvl[b])
		swap (a, b);
	a = get_p (a, lvl[a] - lvl[b]);
	if (a == b)
		return a;
	for (int i = K - 1; i >= 0; --i)
		if (go[a][i] != go[b][i])
			a = go[a][i], b = go[b][i];
	a = go[a][0];
	return a;
}

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline bool is_parent (const int &v, const int &u) { // is vertex u is parent of v
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

inline void c_m (matrix &a, const int &n, const int &m) {
	a.resize (n);
	for (int i = 0; i < n; ++i)
		a[i].resize (m);
}

inline matrix operator * (const matrix &a, const matrix &b) {
    matrix c;
	c_m (c, S, S);
	for (int i = 0; i < S; ++i) {
		for (int j = 0; j < S; ++j) {
			for (int k = 0; k < S; ++k) {
				if (!a[i][k] || !b[k][j])
					continue;
				c[i][j] = (c[i][j] + (a[i][k] * 1ll * b[k][j])) % bpr;
			}
		}
	}
	return c;
}

matrix zero_matrix;

inline matrix bin_pow (const matrix &a, const ll &power) {
	if (!power)
		return zero_matrix;
	if (power & 1)
		return bin_pow (a, power ^ 1) * a;
	matrix b = bin_pow (a, power >> 1);
	return b * b;
}

inline ll bin_pow (const ll &a, const ll &power) {
	if (power == 0)
		return 1;
	if (power & 1LL)
		return (bin_pow (a, power ^ 1) * a) % bpr;
	ll b = bin_pow (a, power >> 1LL);
	return (b * b) % bpr;
}

matrix fib[N + 1];

inline pair <int, int> get_kth (ll k) {	///kth, sum
	--k;
	if (k < 0)
		return mp (0, 0);
	auto e = bin_pow (fib[1], k);
	auto s = e[2][1] + e[1][1];
	add (s, 0);
	return mp (e[1][1], s);
}

inline matrix get_kth_m (ll k) {	///kth, sum
	--k;
	if (k < 0)
		return fib[N];
	auto e = bin_pow (fib[1], k);
	return e;
}

inline int get_kth_sum (const matrix &a) {
	int s = a[2][1];
	add (s, a[1][1]);
	return s;
}


int sum1[N], sum2[N], sum[N], d[N];
char q_type[N];
int x[N], k[N], y[N];
int n, m;
int qlca[N];
int ans[N];

inline void dfs2 (int v, int p1 = 0, int p2 = 0) {
	add (sum1[v], sum1[p1]), add (sum1[v], sum1[p2]), add (sum1[v], sum2[p1]);
	add (d[v], sum1[v]);
	sum[v] = sum[p1];
	add (sum[v], d[v]);
	for (auto to : g[v])
		dfs2 (to, v, p1);
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	c_m (zero_matrix, S, S);

	for (int i = 0; i < S; ++i)
		zero_matrix[i][i] = 1;
	
	fib[0] = zero_matrix;

	c_m (fib[1], S, S);
	fib[1][0][1] = fib[1][1][0] = fib[1][1][1] = fib[1][2][1] = fib[1][2][2] = 1;	
	for (int i = 2; i < N; ++i)
		fib[i] = fib[i - 1] * fib[1];

	c_m (fib[N], S, S);

	cin >> n >> m;

	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		g[x].eb (i);
	}
		
	dfs (1, 1);
	
	for (int i = 1; i <= m; ++i) {
		cin >> q_type[i];
		if (q_type[i] == 'U') {
			cin >> x[i] >> k[i];
		} else {
			cin >> x[i] >> y[i];
			qlca[i] = lca (x[i], y[i]);
		}
	}
	
	for (int i = 1, lst = 0; i <= m; ++i) {
		if (q_type[i] == 'U') {
			auto h = get_kth_m (k[i]), hl = get_kth_m (k[i] - 1);
			if (i % MAGIC != 0) {
				for (int j = i + 1; j % MAGIC != 0 && j <= m; ++j) {
					if (q_type[j] == 'Q') {
						if (is_parent (qlca[j], x[i])) {
							auto tmp = h * fib[lvl[x[j]] - lvl[x[i]]];
							matrix tmp2;
							if (lvl[qlca[j]] - lvl[x[i]] - 1 >= 0)
								tmp2 = h * fib[lvl[qlca[j]] - lvl[x[i]] - 1];
							else
								tmp2 = hl;
							add (ans[j], get_kth_sum (tmp));
							add (ans[j], bpr - get_kth_sum (tmp2));
							tmp = h * fib[lvl[y[j]] - lvl[x[i]]];
							tmp2 = h * fib[lvl[qlca[j]] - lvl[x[i]]];
							add (ans[j], get_kth_sum (tmp));
							add (ans[j], bpr - get_kth_sum (tmp2));
						} else if (is_parent (x[j], x[i])) {
							auto tmp = h * fib[lvl[x[j]] - lvl[x[i]]];
							add (ans[j], get_kth_sum (tmp));
							add (ans[j], bpr - get_kth_sum (hl));							
						} else if (is_parent (y[j], x[i])) {
							auto tmp = h * fib[lvl[y[j]] - lvl[x[i]]];
							add (ans[j], get_kth_sum (tmp));
							add (ans[j], bpr - get_kth_sum (hl));
						}
					}
				}
			}
		} else {
			int res = sum[x[i]];
			add (res, bpr - sum[qlca[i]]);
			add (res, sum[y[i]]), add (res, bpr - sum[qlca[i]]);
			add (res, d[qlca[i]]);
			add (res, ans[i]);
			cout << res << "\n";
		}
		//cerr << MAGIC << ": " << i % MAGIC << "\n";
		if (i % MAGIC == 0) {
			for (int j = lst + 1; j <= i; ++j) {
				if (q_type[j] == 'U') {
					add (sum1[x[j]], get_kth (k[j]).fe);
					add (sum2[x[j]], get_kth (k[j] - 1).fe);
					//cerr << k[j] << " " << get_kth (k[j]).fe << "\n";
				}
			}
			dfs2 (1);
			memset (sum1, 0, sizeof (sum1));
			memset (sum2, 0, sizeof (sum2));
			lst = i;
		}
	}

	return 0;
}