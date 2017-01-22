#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

typedef long long ll;

const int N = 2e5 + 100;

ll l[N], r[N], protection[N], to[N], cnt[N];
ll optimus[N];

class SettingShield {

	public:
    ll getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m) {
		protection[0] = val0[0];
		for (ll i = 1; i < n; ++i)
			protection[i] = (a[0] * protection[i - 1] + b[0]) % m[0];
		l[0] = val0[1];
		r[0] = val0[2];
		for (ll i = 1; i < h; ++i) {
			l[i] = min (ll (n) - 1, (a[1] * l[i - 1] + b[1]) % m[1]);
			ll dist = r[i - 1] - l[i - 1];
			r[i] = min (ll (n) - 1, l[i] + (a[2] * dist + b[2]) % m[2]);
    	}
    	for (ll i = 0; i < h; ++i) {
    		++cnt[l[i]];
    		--cnt[r[i] + 1];
    		to[l[i]] = max (to[l[i]], r[i]);
		}
    	ll must = 0;
    	for (ll i = 0, j = 0; i < n; ++i) {
    		j += cnt[i];
    		if (j == 0) {
    			must = max (must, protection[i]);
    		}
    	}
    	memset (cnt, 0, sizeof (cnt));
    	ll ans = must * t;
    	for (ll i = 0; i < n; ++i)
    		protection[i] = max (0ll, protection[i] - must);
    	ll till = 0;
    	for (ll i = 0, j = 0; i < n; ++i) {
    		j += cnt[i];
    		till = max (till, to[i]);
    		protection[i] = max (0ll, protection[i] - j);
    		ll need = protection[i];
    		cnt[till + 1] -= need;
    		j += need;
    		ans += need;
    		++optimus[need];
    	}
    	
    	return ans;
    }

};

#ifdef LOCAL
main() {


}
#endif