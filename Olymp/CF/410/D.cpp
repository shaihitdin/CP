#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fe first
#define se second

const int N = 1e5 + 100;

int a[N], b[N], n;
pair <int, int> c[N], d[N];
int cnt[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		c[i] = mp (a[i], i);
		d[i] = mp (b[i], i);
	}

	sort (c + 1, c + n + 1);
	sort (d + 1, d + n + 1);

	for (int i = 1; i <= n / 2 + 1; ++i)
		++cnt[c[n - i + 1].se], ++cnt[d[n - i + 1].se];
	
	set <int> ans;
	
	for (int i = 1; i <= n; ++i)
		if (cnt[i] == 2)
			ans.insert (i);
	
	for (int i = n; i >= 1; --i) {
		if (ans.size () + (1 - ans.count (c[i].se)) <= n / 2 + 1) {
			ans.insert (c[i].se);
		}
		if (ans.size () + (1 - ans.count (d[i].se)) <= n / 2 + 1) {
			ans.insert (d[i].se);
		}

	}	

	
	cout << ans.size () << "\n";
	for (auto it : ans)
		cout << it << " ";
	
	return 0;
}