#include <bits/stdc++.h>

using namespace std;

const double eps = 1 / 1e7;

const int N = 2e5 + 300;

int n, m, k;
int a[N];
vector <int> g[N];
bool u[N];
int in[N], inv[N];
int stq, enq;
int st[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	scanf ("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= k; ++i)
		scanf ("%d", &a[i]);

	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		g[x].push_back (y);
		++in[x];
		g[y].push_back (x);
		++in[y];
	}
	
	double l = 0, r = 1;

	for (int cnt = 1; cnt <= 50; ++cnt) {
		double mid = (r + l) / 2;
		stq = enq = 0;
		memset (inv, 0, sizeof (inv));
		memset (u, 0, sizeof (u));
		for (int i = 1; i <= k; ++i)
			st[++enq] = a[i];
	    for (int i = 1; i <= k; ++i)
	    	u[a[i]] = 1;
	    while (stq < enq) {
			int v = st[++stq];
			for (auto to : g[v]) {
				++inv[to];
				if (!u[to] && inv[to] / 1.0 / in[to] > mid)
					st[++enq] = to, u[to] = 1;
			}
	    }
	    if (enq < n) {
	    	r = mid;
	    } else {
	    	l = mid;
	    }
	}
			
	
	stq = enq = 0;
	memset (inv, 0, sizeof (inv));
	memset (u, 0, sizeof (u));
	for (int i = 1; i <= k; ++i)
		st[++enq] = a[i];
    for (int i = 1; i <= k; ++i)
    	u[a[i]] = 1;
    
    while (stq < enq) {
		int v = st[++stq];
		for (auto to : g[v]) {
			++inv[to];
			if (!u[to] && inv[to] / 1.0 / in[to] > r) {
				st[++enq] = to, u[to] = 1;
			}
		}
    }
	
	memset (u, 0, sizeof (u));

	for (int i = 1; i <= enq; ++i)
		u[st[i]] = 1;
	
	vector <int> ans;
	
	for (int i = 1; i <= n; ++i)
		if (!u[i])
			ans.push_back (i);
	
	printf ("%d\n", ans.size ());

	for (auto v : ans)
		printf ("%d ", v);
	
	return 0;
}