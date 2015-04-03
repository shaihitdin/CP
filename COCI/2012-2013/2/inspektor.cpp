#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, sz = 351;


typedef long long ll;

struct line {
	int a;
	ll b;
	bool u;
} a[N];

int n, m, block;

int b_n[N];
int b_s[sz];

inline bool operator < (const line &lhs, const line &rhs) {
	if (lhs.a == rhs.a)
		return lhs.b > rhs.b;
	return lhs.a < rhs.a;
}

vector <line> temp, b[sz];

int cross[sz][sz];
line st[N];
int enq;

inline float intersection (const line &x, const line &y) {
	if (x.a == y.a)
		assert (0);
	return (y.b - x.b) /  float (x.a - y.a);
}

inline void rebuild (const int &num) {
	temp.resize (0);
	for (int i = b_s[num]; b_n[i] == num; ++i)
		if (a[i].u)
			temp.push_back (a[i]);
	sort (temp.begin(), temp.end());
	enq = 0;
	for (auto it : temp) {
		if (enq && it.a == st[enq].a)
			continue;
		while (enq > 1 && intersection (st[enq - 1], it) < intersection (st[enq - 1], st[enq]))
			--enq;
		st[++enq] = it;
	}
	b[num].resize (0);
	for (int i = 1; i <= enq; ++i)
		b[num].push_back (st[i]);
	for (int i = 1; i < b[num].size(); ++i)
		cross[num][i] = intersection (b[num][i - 1], b[num][i]);
}

inline void smax (ll &x, const ll &&y) {
	if (x < y)
		x = y;
}

int cnt;

int main () {
	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d%d", &n, &m);

	block = sqrt (n) + 1;

	for (int i = 1; i <= n; ++i) {
		b_n[i] = i / block + 1;
		if (b_n[i] != b_n[i - 1])
			b_s[b_n[i]] = i;
	}
	
	for (int test = 1; test <= m; ++test) {
		int q;
		scanf ("%d", &q);
		if (q == 1) {
			int start, pos, profit, money;
			scanf ("%d%d%d%d", &start, &pos, &profit, &money);
			a[pos].a = profit;
			a[pos].u = 1;
			a[pos].b = money - (1ll * profit * start);
			rebuild (b_n[pos]);
		}
		else {
			int t, l, r;
		    scanf ("%d%d%d", &t, &l, &r);
		    if (l > r)
		    	swap (l, r);
		    ll ans = -1e18;
			if (b_n[l] == b_n[r]) {
				for (int i = l; i <= r; ++i)
					if (a[i].u)
						smax (ans, t * 1ll * a[i].a + a[i].b);
				if (ans == -1e18)
					puts ("nema");
				else
					printf ("%I64d\n", ans);
				continue;
			}
			int i = l;
			
						
			for (; b_n[i] == b_n[l]; ++i)
				if (a[i].u)
					smax (ans, t * 1ll * a[i].a + a[i].b);
			for (; b_n[i] != b_n[r]; i += block) {
				if (b[b_n[i]].size()) {
					int ss = b_n[i];
					int l_bin = 0, r_bin = b[ss].size() - 1;
					while (r_bin - l_bin > 1) {
						int mid = (r_bin + l_bin) >> 1;
						if (cross[ss][mid] < t)
							l_bin = mid;
						else
							r_bin = mid;
					}
					smax (ans, t * 1ll * b[ss][r_bin].a + b[ss][r_bin].b);
					smax (ans, t * 1ll * b[ss][l_bin].a + b[ss][l_bin].b);
				}
			}
			for (; i <= r; ++i)
				if (a[i].u)
					smax (ans, t * 1ll * a[i].a + a[i].b);
			if (ans == -1e18)
				puts ("nema");
			else
				printf ("%I64d\n", ans);			
		}
	}
	/*
	if (clock() * 1000 / CLOCKS_PER_SEC > 4000)
		exit (45);
	*/
	return 0;
}