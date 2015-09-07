#include <bits/stdc++.h>

using namespace std;

const int N = 101, inf = 1e9;
int MAXCH;

struct state {
	bool a[N];
	int res;
} cur, nxt;

int best;

int n, m, k;
vector <pair <int, int> > g[N];
int del[N];
int a[N], b[N], c[N];

inline void calc (state &cur) {
	for (int i = 1; i <= m; ++i)
		g[i].resize (0);
	memset (del, 0, sizeof (del));
	for (int i = 1; i <= n; ++i) {
		if (cur.a[i])
			g[a[i]].emplace_back (make_pair (c[i], b[i]));
	}
	int now = 0;
	cur.res = 0;
	for (int i = 1; i <= m; ++i) {
		sort (g[i].begin (), g[i].end ());
		reverse (g[i].begin (), g[i].end ());
		now -= del[i];
		for (auto it : g[i]) {
			if (now == k)
				break;
			++del[it.second];
			cur.res += it.first;
			++now;
		}
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	srand (time (0));
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> k;
	
	if (n <= 50)
		MAXCH = 3e6;
	else
		MAXCH = 6e5;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i];

	for (int i = 1; i <= n; ++i)
		cur.a[i] = 0;
	for (int i = 1; i <= k; ++i)
		cur.a[i] = 1;
	calc (cur);
	best = max (best, cur.res);
	double t = n, alpha = 0.99;
	for (int till = 1; till <= MAXCH; ++till) {
		nxt = cur;
		int rnd = k + (rand () % (n - k + 1));
		int cnt = 0;
		
		for (int i = 1; i <= n; ++i)
			cnt += nxt.a[i] == 1;
		for (int i = 1; i <= n && cnt != rnd; ++i)
			if (nxt.a[i] == 0)
				nxt.a[i] = 1, ++cnt;
		for (int i = 1; i <= n && cnt != rnd; ++i)
			if (nxt.a[i] == 1)
				nxt.a[i] = 0, --cnt;
		
		
		for (int i = 0; i <= int (t); ++i)
			swap (nxt.a[rand() % n + 1], nxt.a[rand() % n + 1]);
		calc (nxt);
		double d = (int)(nxt.res - cur.res);
		if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024)
			cur = nxt;
		best = max (best, cur.res);
		t *= alpha;
	}

	cout << best;
	
	return 0;
}