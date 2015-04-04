#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

struct edge {
	int from, to, cost;
};

int p[N], n;
long long ans;

inline int get_p (const int &x) {
	return (x == p[x]) ? x : (p[x] = get_p (p[x]));
}

inline void Merge (int x, int y) {
	x = get_p (x);
	y = get_p (y);
	if (rand() & 1) {
		p[x] = y;
	}
	else {
		p[y] = x;
	}
}

inline bool operator < (const edge &x, const edge &y) {
	return x.cost > y.cost;
}

vector <edge> edges;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	srand (time (0));

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int dist, x;
		scanf ("%d%d", &x, &dist);
		edges.push_back ({i, x, dist});
	}
	sort (edges.begin(), edges.end());

	for (int i = 1; i <= n; ++i)
		p[i] = i;
		
	for (edge it : edges) {
		if (get_p (it.from) != get_p (it.to)) {
			ans += it.cost;
			Merge (it.from, it.to);
		}
	}

	printf ("%I64d", ans);

	return 0;
}