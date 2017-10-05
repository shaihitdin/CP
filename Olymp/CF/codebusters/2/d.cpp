#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map <int, ll> cnt;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;
	scanf ("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
    	int x, y;
    	cin >> x >> y;
    	cnt[x] = y;
    }

	while (cnt.size ()) {
		auto it = *cnt.begin();
		cnt.erase (cnt.begin ());
		if (!cnt.size () && it.second <= 4) {
			cout << it.first + 1;
			return 0;
		}
		if (it.second > 4) {
			ll need = min (it.second, cnt[it.first + 1] * 4);
			it.second -= need;
			cnt[it.first + 1] += it.second / 4 + (it.second % 4 > 0);
		}

	}
	return 0;
}