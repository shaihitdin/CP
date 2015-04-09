#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll c, h[3], w[3];

ll ans;

inline void ss (ll &x, const ll &&y) {
    if (x < y)
        x = y;
}

inline ll calc (const ll &x) {
    return x * h[1] + ((c - x * w[1]) / w[2]) * h[2];
}

int main () {
    
    #ifndef ONLINE_JUDGE
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif

    cin >> c >> h[1] >> h[2] >> w[1] >> w[2];

    ll l = 0, r = c / w[1];

    while (r - l > 1000000) {
        ll mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (calc (mid1) > calc (mid2))
            r = mid2;
        else
            l = mid1;
    }

	ss (ans, calc (0));
    ss (ans, calc (c / w[1]));
    
    for (ll i = l; i <= r; ++i)
        ss (ans, calc (i));
	
	swap (h[1], h[2]);
	swap (w[1], w[2]);
    
    l = 0, r = c / w[1];

    while (r - l > 1000000) {
        ll mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (calc (mid1) > calc (mid2))
            r = mid2;
        else
            l = mid1;
    }

	ss (ans, calc (0));
    ss (ans, calc (c / w[1]));
    
    for (ll i = l; i <= r; ++i)
        ss (ans, calc (i));

    
    cout << ans;
    return 0;
}