#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 100;

#define mp make_pair
#define fe first
#define se second

pair <string, int> a[N];
int len[N];
int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		char q;
		string s;
		cin >> q >> s;
		a[i] = mp (s, q == '+');
	}
	
	vector <string> ans;

	sort (a + 1, a + n + 1);

	for (int i = 1, lst = 0; i <= n; ++i) {
		if (a[i].se) {
			lst = i;
			continue;
		}
		int x = 0;
		for (; x < a[lst].fe.size () && x < a[i].fe.size () && a[i].fe[x] == a[lst].fe[x]; ++x);
		len[i] = max (len[i], x);
	}
	
	for (int i = n, lst = n + 1; i >= 1; --i) {
		if (a[i].se) {
			lst = i;
			continue;
		}
		int x = 0;
		for (; x < a[lst].fe.size () && x < a[i].fe.size () && a[i].fe[x] == a[lst].fe[x]; ++x);
		len[i] = max (len[i], x);
	}
	
	for (int i = 1; i <= n; ++i) {
		if (a[i].se)
			continue;
		string s;
		for (int j = 0; j < len[i]; ++j)
			s += a[i].fe[j];
		if (len[i] == a[i].fe.size ()) {
			cout << -1;
			return 0;
		}
		s += a[i].fe[len[i]];
		ans.emplace_back (s);
	}
	
	sort (ans.begin (), ans.end ());
	ans.resize (unique (ans.begin (), ans.end ()) - ans.begin ());
	
	cout << ans.size () << "\n";

	for (auto it : ans)
		cout << it << "\n";
	
	return 0;
}