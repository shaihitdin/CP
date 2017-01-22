/**
	Mom, I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100, bpr = 1e9 + 7;

vector <pair <int, int> > g[N];
int n, m;
int f[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	f[0] = 1;

	for (int i = 1; i < N; ++i) {
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	}
	
	for (int i = 1; i <= n; ++i) {
		int z;
		cin >> z;
		vector <int> a;
		while (z--) {
			int x;
			cin >> x;
			a.emplace_back (x);
		}
		sort (a.begin (), a.end ());
		for (int k = 0; k < a.size (); ++k) {
			int j = k;
			while (j < a.size () && a[k] == a[j])	++j;
			--j;
			g[a[k]].emplace_back (make_pair (j - k + 1, i));
			k = j;
		}
	}
	

	int ans = 1;

	sort (g + 1, g + m + 1);
	
	for (int i = 1; i <= m; ++i) {
		int j = i;
		while (j <= m && g[i] == g[j])	++j;
		--j;
		ans = (ans * 1ll * f[j - i + 1]) % bpr;
		i = j;
	}
	
	cout << ans;
	return 0;
}