#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;

const int N = 220, MAGIC = 110000, inf = 1e9;

struct state {
	bool u[N];
	int res;
} cur, nxt;

int best;

int n, a[N], l[N];
short go[N][3], state_cnt;
char lolik[N * 2];
int rev_lolik[N * 2];

inline void calc (state &b) {
	int cnt = 0;
	memset (lolik, 0, sizeof (lolik));
	for (int i = 1; i <= n; ++i) {
		if (b.u[i] == 0) {
			++lolik[go[i][0]];
			--lolik[go[i][1]];
		} else {
			++lolik[go[i][1]];
			--lolik[go[i][2]];
		}
	}
	int now = 0;
	b.res = 0;
	int lst_cnt = 0;
	for (int i = 1; i <= state_cnt; ++i) {
		if (!lolik[i])
			continue;
		now += lolik[i];
		if (!now) {
			b.res += rev_lolik[i] - rev_lolik[lst_cnt];
			lst_cnt = 0;
		} else if (!lst_cnt) {
			lst_cnt = i;
		}
	}
}

char mod_n[70000];

inline int make_them_burn (const int &num) {
	for (int i = 1; i <= n; ++i)
		cur.u[i] = 0;
	for (int i = 1; i <= num; ++i)
		cur.u[i] = 1;
	calc (cur);
	
	best = cur.res;

	double t = n, alpha = 0.99;

	int till_mx = (MAGIC * 1.0) * (((abs (num - (n / 2)) + 1) * 1.0) / (n / 2.0));
	for (int till = 1; till <= till_mx; ++till) {
		nxt = cur;
		for (int i = 0; i <= int (t); ++i)
			swap (nxt.u[mod_n[rand ()] + 1], nxt.u[mod_n[rand ()] + 1]);
		calc (nxt);
		double d = (int)(nxt.res - cur.res);
		if (d < 0 || exp((-d) / t) > (rand () % 1024) / 1024)
			cur = nxt;
		best = max (best, cur.res);
		t *= alpha;
	}
	return best;
}


map <int, int> Map;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	srand (time (0));
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 0; i < 67000; ++i)
		mod_n[i] = i % n;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> l[i];

	for (int i = 1; i <= n; ++i) {
		Map[a[i] - l[i]] = 0;
		Map[a[i] + l[i]] = 0;
		Map[a[i]] = 0;
	}
	
	for (auto it = Map.begin (); it != Map.end (); ++it) {
		it -> second = ++state_cnt;
		rev_lolik[state_cnt] = it -> first;
	}

	for (int i = 1; i <= n; ++i) {
		go[i][0] = Map[a[i] - l[i]];
		go[i][1] = Map[a[i]];
		go[i][2] = Map[a[i] + l[i]];
	}
	
	Map.clear ();
	
	int ans = 0;
	int lo = 0, hi = n;
	
	/*
	while (hi - lo > 10) {
		int mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
		int check1 = make_them_burn (mid1), check2 = make_them_burn (mid2);
		ans = max (ans, max (check1, check2));
		if (check1 > check2)
			hi = mid2;
		else
			lo = mid1;
	}
	*/
	for (; lo <= hi; ++lo)
		ans = max (ans, make_them_burn (lo));
	
	
	cout << ans;

	return 0;
}