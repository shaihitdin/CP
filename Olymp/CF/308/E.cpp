#include <bits/stdc++.h>

using namespace std;

const int N = 1e4, inf = 1e9;

typedef long long ll;

struct state {
	int begin, end;
	ll res;
} cur, nxt, best;

int n_cnt;
string s;
int n;


inline bool is_num (const int &pos) {
	return '0' <= s[pos] && s[pos] <= '9';
}

inline ll r_s (const ll &val1, const ll &val2, const char &action) {
	if (action == '+')
		return val1 + val2;
	return val1 * val2;
}


inline void calc (state &cur) {
	ll res = s[1] - '0';
	if (cur.begin != 0) {
		ll tmp_res = s[cur.begin] - '0';
		int k = i + 2, j1 = j + 1;
		for (; j1 <= cur.end; ++j1, k += 2)
			tmp_res = r_s (tmp_res, s[k] - '0', s[k - 1]);	
	}

	for (int i = 3, j = 2; i <= n; i += 2, ++j) {
		if (cur.begin == j) {
			res = r_s (res, tmp_res, s[i - 1]);
			--j1;
			k -= 2;
			i = k;
			j = j1;
		} else {
			res = r_s (res, s[i] - '0', s[i - 1]);
		}
	}
	cur.res = res;
}

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	srand (time (0));
	
	cin >> s;
	
	n = s.size ();

	s = '#' + s;

	for (int i = 1; i <= n; i += 2)
			++n_cnt;
	
	if (n_cnt < 3) {
		cur.begin = 0;
		cur.end = 0;
		calc (cur);
		cout << cur.res;
		return 0;
	}
	
	cur.begin = 2;
	cur.end = n_cnt;
	
	calc (cur);
	
	double t = n, alpha = 0.99;
	
	best = cur;

	for (int till = 1; till <= 42000; ++till) {
		nxt = cur;
		nxt.begin = 2 + (rand () % (n_cnt - 2));
		nxt.end = nxt.begin + (rand () % (n_cnt - nxt.begin));
		calc (nxt);
		double d = ll (nxt.res - cur.res);
		if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024)
			cur = nxt;
		if (cur.res < best.res) best = cur;
		t *= alpha;
	}

	
	cerr << best.begin << " " << best.end << " ";

	cout << best.res;
	
	return 0;
}