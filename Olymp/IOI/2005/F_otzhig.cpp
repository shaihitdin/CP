#include <bits/stdc++.h>

using namespace std;

const int N = 101, inf = 1e9;

struct state {
	bool a[N];
	int res;
} cur, nxt, best;

int d[N];
vector <int> g[N];
int dist[N], cnt[N];
int n, k;

inline void dfs (const int &v, const int &dista, const state &cur) {
	d[v] = dista;
	if (cur.a[v])
		d[v] = 0;
	for (auto to : g[v])
		dfs (to, d[v] + dist[to], cur);
}

inline void calc (state &cur) {
	dfs (0, 0, cur);
	cur.res = 0;
	for (int i = 1; i <= n; ++i)
		cur.res += d[i] * cnt[i];
}

int main () {

	srand (time (0));
	
	scanf ("%d%d", &n, &k);

	for (int i = 1; i <= n; ++i) {
		int to;
		scanf ("%d%d%d", &cnt[i], &to, &dist[i]);
		g[to].push_back (i);
	}

	for (int i = 1; i <= k; ++i)
		cur.a[i] = 1;

	calc (cur);
	
	best = cur;

	double t = n, alpha = 0.99;
	best = cur;

	for (int till = 1; till <= 600000; ++till) {
		nxt = cur;
		for (int i = 0; i <= int (t); ++i)
			swap (nxt.a[rand() % n + 1], nxt.a[rand() % n + 1]);
		calc (nxt);
		double d = (int)(nxt.res - cur.res);
		if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024)
			cur = nxt;
		if (cur.res < best.res) best = cur;
		t *= alpha;
	}

	printf ("%d", best.res);
	
	return 0;
}