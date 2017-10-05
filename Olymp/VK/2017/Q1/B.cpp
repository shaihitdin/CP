#include <bits/stdc++.h>

using namespace std;

#define fe first
#define se second
#define mp make_pair
#define eb emplace_back

const int N = 1e4 + 100;

pair <int, int> a[N];

vector <pair <int, int > > ans;
vector <int> v;

inline void add (int x) {
	for (int i = 1; i <= a[x].fe; ++i)
		v.eb (a[x].se);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].fe;
		a[i].se = i;
	}	

	sort (a + 2, a + n + 1);
	reverse (a + 2, a + n + 1);	
	add (1);
	
	for (int i = 2; i <= n; ++i) {
		if (!v.size ()) {
			cout << -1;
			return 0;
		}
		ans.eb (mp (v.back (), a[i].se));
		v.pop_back ();
		add (i);
	}	
	

	cout << n - 1 << "\n";

	for (int i = 0; i < n - 1; ++i)
		cout << ans[i].fe << " " << ans[i].se << "\n";
	
	return 0;
}