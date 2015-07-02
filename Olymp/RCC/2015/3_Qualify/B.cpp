#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> ans;
ll cnt[15];

int main () {

	ios_base :: sync_with_stdio (0);

	int t;
	cin >> t;
	
	while (t--) {
		ll a, b;
		cin >> a >> b;
		memset (cnt, 0, sizeof (cnt));
		ll mx = 0;
		ans.resize (0);
		for (ll i = a; i <= min (b, a + 8); ++i)
			cnt[i % 9] = (b - i) / 9 + 1;
		cnt[9] = cnt[0];
		for (int i = 1; i <= 9; ++i)
			mx = max (mx, cnt[i]);
		for (int i = 1; i <= 9; ++i)
			if (cnt[i] == mx)
				ans.push_back (i);
		cout << ans.size () << " ";
		for (auto it : ans)
			cout << it << " ";
		cout << "\n";
	}

	return 0;
}