#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	cin >> n;

	vector <pair <int, int> > cc;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cc.emplace_back (make_pair (a[i], i - 1));
	}

	sort (cc.begin (), cc.end ());
	ll ans = 0;
	vector <int> nums;
	for (int i = 0, it = 0, lst = 1e9; i < n || nums.size ();) {
		ans += (n - (i - nums.size ()));
		lst = -1;
		int add = 0;
		while (1) {
			if (nums.size () && lst > nums.back ())
				break;
			if (!nums.size ()) {
				if (i == n)
					break;
				int j = i;
				while (j < n && cc[i].first == cc[j].first)	++j;
				--j;
				for (int k = i; k <= j; ++k)
					nums.emplace_back (cc[k].second);
				i = j + 1;
			}
			
			int val = lst;

			
			while (nums.size () && lst < nums.back ()) {
				val = max (val, nums.back ());
				nums.pop_back ();
				++add;
			}
			lst = val;
		}
	}
	cout << ans;
	return 0;
}