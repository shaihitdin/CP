#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e4 + 100;

int n, q;
pair <ll, ll> a[N], b[N];
bool u[N];
int p[N];
ll tmp, tmp_val;
ll beg[N];
int b_s[N];
int cc[N];

inline void rec (const int &beg, const int &x, const int &till) {
	if (x == till + 1) {
		tmp = max (tmp, tmp_val);
		return;
	}
	for (int i = beg; i <= till; ++i) {
		if (!u[i] && p[a[x].second] != b[i].second) {
			ll check = a[x].first * b[i].first;
			tmp_val += check;
			u[i] = 1;
			rec (beg, x + 1, till);
			u[i] = 0;
			tmp_val -= check;
		}
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort (a + 1, a + n + 1);
	reverse (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	for (int i = 1; i <= n; ++i) {
		cin >> b[i].first;
		b[i].second = i;
	}	

	sort (b + 1, b + n + 1);
	reverse (b + 1, b + n + 1);
	
	for (int i = 1; i <= n; i += 5) {
		if (i + 8 > n) {
			for (int j = i; j <= n; ++j)
				b_s[j] = i;
			break;
		} else {
			b_s[i] = b_s[i + 1] = b_s[i + 2] = b_s[i + 3] = b_s[i + 4] = i;
		}
	}
	
	ll ans = 0;
	
	for (int i = 1; i <= n; i += 5) {
		tmp = 0;
		if (i + 8 > n) {
			rec (i, i, n);
			beg[i] = tmp;
			ans += tmp;
			break;
		} else {
			rec (i, i, i + 4);
			beg[i] = tmp;
			ans += tmp;
		}
	}

	for (int i = 1; i <= n; ++i)
		cc[a[i].second] = i;
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		swap (p[x], p[y]);
		tmp = 0;
		int t_x = cc[x], t_y = cc[y];
		ans -= beg[b_s[t_x]];
		if (b_s[t_x] + 8 > n)
			rec (b_s[t_x], b_s[t_x], n);
		else
			rec (b_s[t_x], b_s[t_x], b_s[t_x] + 4);
		ans += tmp;
		beg[b_s[t_x]] = tmp;
        tmp = 0;
        ans -= beg[b_s[t_y]];
		if (b_s[t_y] + 8 > n)
			rec (b_s[t_y], b_s[t_y], n);
		else
			rec (b_s[t_y], b_s[t_y], b_s[t_y] + 4);
		ans += tmp;
		beg[b_s[t_y]] = tmp;
		cout << ans << "\n";
	}
	
	return 0;
}