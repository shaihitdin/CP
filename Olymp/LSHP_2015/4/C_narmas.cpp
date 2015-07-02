#include <bits/stdc++.h>

using namespace std;

const int N = 101, inf = 1e9, up_limit = 1e6;

struct state {
	bool a[N];
	int res;
} cur, nxt, best, r_best;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	
mt19937 generator (seed);

int n, v[N], p[N], c[N];
int v0;
int limit[N];

inline void calc (state &cur) {
	int mass = 0;
	cur.res = 0;
	for (int i = 1; i <= n; ++i) {
		if (!cur.a[i])
			continue;
		mass += v[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!cur.a[i])
			continue;
		if (p[i] < mass - v0) {
			cur.res = -inf;
			break;
		}
		cur.res += c[i];
	}

}

inline int f (const int &k) {

	for (int i = 1; i <= k; ++i)
		cur.a[i] = 1;

	calc (cur);
	
	best = cur;

	double t = n, alpha = 0.99;
	best = cur;

	for (int till = 1; till <= limit[k]; ++till) {
		nxt = cur;
		for (int i = 0; i <= int (t); ++i)
			swap (nxt.a[1 + (generator() % n)], nxt.a[1 + (generator() % n)]);
		calc (nxt);
		double d = (int)(nxt.res - cur.res);
		if (d < 0 || exp((-d) / t) > (generator() % 1024) / 1024)
			cur = nxt;
		if (cur.res < best.res) best = cur;
		t *= alpha;
	}
	
	if (r_best.res < best.res)
		r_best = best;

	return best.res;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> v0;

	for (int i = 1; i <= n; ++i)
		cin >> v[i] >> c[i] >> p[i];
	
	int l = 0, r = n + 1;
		
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (f (mid) > f (mid + 1))
			l = mid;
		else
			r = mid;
	}

	
	vector <int> ans;

	for (int i = 1; i <= n; ++i) {
		if (!r_best.a[i])
			continue;
		ans.push_back (i);
	}

	cout << ans.size () << " " << r_best.res << "\n";
	
	for (auto it : ans)
		cout << it << " ";
	
	return 0;
}