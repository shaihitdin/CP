#include <bits/stdc++.h>

using namespace std;

const int N = 4e5;

typedef long long ll;


ll l[N], r[N];
ll c2[N], c1[N];
ll need_mn[N], need_mx[N];
ll n, m;
ll a[N];
ll ans[N];

inline bool cmp1 (const ll &x, const ll &y) {
	return need_mn[x] < need_mn[y];
}

inline bool cmp2 (const ll &x, const ll &y) {
	return a[x] < a[y];
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}

	for (int i = 1; i <= m; ++i) {
		c2[i] = i;
	}
	
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}

	sort (c2 + 1, c2 + m + 1, cmp2);
	
	for (int i = 1; i < n; ++i) {
		need_mn[i] = l[i + 1] - r[i];
		need_mx[i] = r[i + 1] - l[i];
	}
	
	multimap <ll, ll> que;

	for (int i = 1; i < n; ++i) {
		c1[i] = i;
	}
		
	sort (c1 + 1, c1 + n, cmp1);

	for (int itt = 1, j = 1; itt <= m; ++itt) {
		int i = c2[itt];
		while (j < n) {
			int it = c1[j];
			if (need_mn[it] > a[i])
				break;
			que.insert (make_pair (need_mx[it], it));
			++j;
		}
		auto it = que.begin ();
		if (it == que.end ())
			continue;
		if (it -> first >= a[i]) {
			ans[it -> second] = i;
			que.erase (it);
		} else {
			cout << "No";
			return 0;
		}
	}
	
	
	
	for (int i = 1; i < n; ++i) {
		if (!ans[i]) {
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes\n";
	
	for (int i = 1; i < n; ++i) {
		cout << ans[i] << " ";
	}
	
	return 0;
}