#include <bits/stdc++.h>

using namespace std;

const int N = 501, inf = 1e9;

bitset <N> ans, b[N], c, calc;

struct state {
	vector <int> a;
	bitset <N> picked;
	int res;
} cur, nxt;

inline void print (const state &cur) {
	cout << "YES\n";
	cout << cur.a.size () << "\n";
	for (auto it : cur)
		cout << it << " ";
	exit (0);
}

inline void calc (state &cur) {
	cur.res = n;
	calc = c;
	for (int i = 0; i < m; ++i) {
		if (action[cur.a[i]] == 1) {
			calc &= ()
		} else {
		
		}
	}
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	
	srand (time (0));
	
	cin >> n >> m;

	cin >> ans;
	
	for (int i = 1; i <= m; ++i)
		cin >> action[i] >> b[i];
	
	for (int i = 1; i <= m; ++i)
		cur.a.push_back (i);
	
	
	calc (cur);
	
	best = cur;

	double t = n, alpha = 0.99;
	best = cur;

	for (int till = 1; till <= 1200000; ++till) {
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