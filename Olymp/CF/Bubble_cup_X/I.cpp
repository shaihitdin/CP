#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

vector <int> timer;
int tin[N], tout[N];
vector <int> g[N];
bool zhigit[N];
int up[N][20];

inline void dfs (int v, int p = 0) {
	tin[v] = timer.size ();
	timer.emplace_back (v);
	up[v][0] = p ? p : v;
	for (int i = 1; i < 20; i++)
		up[v][i] = up[up[v][i-1]][i-1];
	for (auto to : g[v]) {
		if (to == p)
			continue;
		dfs (to, v);
	}
	tout[v] = timer.size ();
	timer.emplace_back (v);
}




inline bool is_parent (int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca (int a, int b) {
	if (is_parent (a, b))  return a;
	if (is_parent (b, a))  return b;
	for (int i=19; i>=0; --i)
		if (! is_parent (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

struct query {
	int l, r, id;
};

int K;

inline bool operator < (const query &a, const query &b) {
	if (a.l / K == b.l / K)
		return a.r < b.r;
	return a.l / K < b.l / K;
}

int cnt[N][2];
int ww[N];
ll ans;
ll res[N];
int n;
int f[N];

inline void add (int x, int s) {
	x = f[x];
	ans -= cnt[x][0] * 1ll * cnt[x][1];
	++cnt[x][s];
	ans += cnt[x][0] * 1ll * cnt[x][1];
}

inline void del (int x, int s) {
	x = f[x];
	ans -= cnt[x][0] * 1ll * cnt[x][1];
	--cnt[x][s];
	ans += cnt[x][0] * 1ll * cnt[x][1];
}


inline void mal (int x) {
	ww[timer[x]] ^= 1;
	if (ww[timer[x]] == 1) {
		add (timer[x], zhigit[timer[x]]);
	} else {
		del (timer[x], zhigit[timer[x]]);
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	K = sqrt (n) + 10;

	for (int i = 1; i <= n; ++i)
		cin >> zhigit[i];
	
	
	vector <int> cc;

	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
		cc.emplace_back (f[i]);
	}	
	
	sort (cc.begin (), cc.end ());
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());

	
	for (int i = 1; i <= n; ++i) {
		f[i] = lower_bound (cc.begin (), cc.end (), f[i]) - cc.begin ();
	}
	
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].emplace_back (b);
		g[b].emplace_back (a);
	}
	
	dfs (1);
	
	int q;	
	cin >> q;

	int x[N], y[N];
	
	vector <query> qs;
	
	for (int i = 1; i <= q; ++i) {
		cin >> x[i] >> y[i];
		if (tin[x[i]] > tin[y[i]])
			swap (x[i], y[i]);
		if (is_parent (x[i], y[i]))
			qs.push_back ({tin[x[i]], tin[y[i]], i});
		else
			qs.push_back ({tout[x[i]], tin[y[i]], i});
		//cerr << tout[x[i]] << " " << tin[y[i]] << "\n";
	}
	
	sort (qs.begin (), qs.end ());
		
	int l = 0, r = 0;
	
	mal (0);

	for (auto it : qs) {
		while (r < it.r)
			mal (++r);
		while (it.l < l)
			mal (--l);
		while (r > it.r)
			mal (r--);
		while (l < it.l)
			mal (l++);
		if (!is_parent(x[it.id], y[it.id])) {
			int haha = lca(x[it.id], y[it.id]);
			add(haha, zhigit[haha]);
		}
			
		res[it.id] = ans;
		if (!is_parent(x[it.id], y[it.id])) {
			int haha = lca(x[it.id], y[it.id]);
			del(haha, zhigit[haha]);
		}
	}	

	for (int i = 1; i <= q; ++i) {
		cout << res[i] << "\n";
	}
	
	return 0;
}