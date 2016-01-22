#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7, N = 55;

int n;

struct state {
	int a[N];
	int res;
} cur, nxt, best;

bool u[N];
vector <int> g[N];
int c[N];

inline int dfs (const int &v, const state &cur) {
	if (u[v])
		return c[v];
	int ps = 0;
	for (auto to : g[v])
		ps = max (ps, dfs (to));
	c[v] = ps + time
}

inline int calc (const state &cur) {
	for (int i = 0; i < n; ++i)
		u[i] = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!u[i])
			ans = max (ans, dfs (i));
	}
	return ans;
}

class Farmville {	
	
	public:
    int minTime(vector <string> s, vector <int> time, vector <int> cost, int budget) {
		
		n = s.size ();
		double t = 1250, alpha = 0.99;
		best = cur;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (s[i][j] == '1')
					g[i].emplace_back (j);
		for (int till = 1; till <= 1e7; ++till) {
			nxt = cur;
			for (int i = 0; i <= int (t); ++i) {
				int x = rand () % n + 1;
				if ()
				swap (nxt.a[rand() % n + 1], nxt.a[rand() % n + 1]);
			}
			calc (nxt);
			double d = (int)(nxt.res - cur.res);
			if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024)
				cur = nxt;
			if (cur.res < best.res) best = cur;
			t *= alpha;
		}
	}

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif