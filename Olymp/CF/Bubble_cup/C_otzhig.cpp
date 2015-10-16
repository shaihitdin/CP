#include <bits/stdc++.h>

using namespace std;

const int N = 21, inf = 1e9;

int d[2][N][N];

struct state {
	bool a[N];
	int b[N];
	int res;
} cur, nxt;


int best;
int n;

inline void calc (state &cur) {
	cur.res = 0;
	for (int i = 1; i <= n; ++i)
		cur.res += d[cur.a[i]][i][cur.b[i]];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	srand (time (0));
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> d[0][i][j];
	
	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= n; ++j)
			cin >> d[1][i][j];
	
	for (int i = 1; i <= n / 2; ++i)
		cur.a[i] = 1;
	for (int i = 1; i <= n; ++i)
		cur.b[i] = i;
	
	calc (cur);
	
	double t = n + 1, alpha = 0.99;
	best = cur.res;

	for (int till = 1; till <= 3000000; ++till) {
		nxt = cur;
		for (int i = 0; i <= int (t); ++i) {
			int x = rand() % n + 1;
			int y = rand() % n + 1;
			swap (nxt.b[x], nxt.b[y]);
			if (t > 0.1 || rand () % 1024 == 0)
				swap (nxt.a[x], nxt.a[y]);
		}
		calc (nxt);
		double d = (int)(nxt.res - cur.res);
		if (d > 0 || exp((d) / t) > (rand() % 1024) / 1024)
			cur = nxt;
		if (cur.res > best) best = cur.res;
		t *= alpha;
	}

	cout << best;
	
	return 0;
}