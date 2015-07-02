#include <bits/stdc++.h>

using namespace std;

const int N = 201;

#define next can

bitset <N> c[N], c_s;
bool u[N];
int n;
vector <int> g[N];

struct node {
	int cost;
	int order[N];
} cur, best, next;

inline node arrange (node &a) {
	memset (u, 0, sizeof (u));
	a.cost = 0;
	for (int j = 1; j <= n; ++j) {
		int i = a.order[j];
		bool flag = 0;
		for (auto it : g[i]) {
			if (u[it]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			u[i] = 1;
			a.cost += 1;
		}
	}
	for (int i = 1; i <= 3; ++i) {
		if (u[i])
			continue;
		bool flag = 0;
		for (auto it : g[i]) {
			if (u[it]) {
				flag = 1;
				break;
			}
		}
		a.cost -= flag;
	}
}

inline bool cmp (const int &x, const int &y) {
	return g[x].size () < g[y].size ();
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	srand (time (0));

	int m;

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
	    int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}

	double t = n, alpha = 0.99;
	
	for (int i = 1; i <= n; ++i)
		cur.order[i] = i;

	sort (cur.order + 1, cur.order + n + 1, cmp);

	arrange (cur);
	
	best = cur;

	for (int cnt = 1; cnt <= 10000000; ++cnt, t *= alpha) {
		if (cur.cost > best.cost)
			best = cur;
		next = cur;
		for (int i = 0; i <= int (t); ++i)
			swap (next.order[(rand () % n) + 1], next.order[(rand () % n) + 1]);
		arrange (next);
		double diff = next.cost - cur.cost;
		if (diff < 0 || exp((-diff) / t) > double (rand() % 1024) / 1024) {
			cur = next;
			arrange (cur);
		}
		if (cur.cost > best.cost)
			best = cur;
	}

	cout << best.cost << " ";
	
	return 0;
}