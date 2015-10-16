#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

vector <int> v[N];
int t_v[N], ans[N];

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, q;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		v[i].emplace_back (i);
		t_v[i] = i;
	}
	
	cin >> q;

	while (q--) {
		int s, t;
		cin >> s >> t;
		if (v[t_v[s]].size () > v[t_v[t]].size ()) {
			swap (t_v[s], t_v[t]);
		}
		for (auto it : v[t_v[s]])
			v[t_v[t]].emplace_back (it);
		v[t_v[s]].clear ();
	}

	for (int i = 1; i <= n; ++i) {
		for (auto it : v[t_v[i]])
			ans[it] = i;
	}

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	
	return 0;
}