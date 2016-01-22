#include "boxes.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e7 + 100;

ll d_l[N], d_r[N];
ll total_l;

inline ll get_min (const ll &a, const ll &b) {
	if (a <= b)
		return a;
	return b;
}

inline ll dist (const ll &a, const ll &b) {
	if (a > b)
		return min (a - b, b + total_l - a);
	else
		return min (b - a, a + total_l - b);
}

ll delivery(int n, int k, int l, int p[]) {
    total_l = l;
    
    sort (p, p + n);
    int i = 0;
    while (i < n) {
    	int have = k;
    	if (i)
    		d_l[i] = d_l[i - 1] + dist (0, p[i]) + dist (0, p[i - 1]);
    	else
    		d_l[i] = dist (0, p[i]);
    	--have;
    	++i;
    	while (i < n && have) {
			d_l[i] = d_l[i - 1] + dist (p[i], p[i - 1]);
			--have;
			++i;
    	}
    }

    i = n - 1;
    while (i >= 0) {
    	int have = k;
    	if (i != n - 1)
    		d_r[i] = d_r[i + 1] + dist (0, p[i + 1]) + dist (0, p[i]);
    	else
    		d_r[i] = dist (0, p[i]);
    	--have;
    	--i;
    	while (i >= 0 && have) {
    		d_r[i] = d_r[i + 1] + dist (p[i + 1], p[i]);
    		--have;
    		--i;
    	}
    }

	ll ans = get_min (d_r[0] + dist (0, p[0]), d_l[n - 1] + dist (0, p[n - 1]));

	for (int i = 0; i < n - 1; ++i)
		ans = get_min (ans, d_l[i] + dist (0, p[i]) + d_r[i + 1] + dist (0, p[i + 1]));

	for (int i = n - 1; i > 0; --i)
		ans = get_min (ans, d_r[i] + dist (0, ((p[i] == 0) ? 0 : l - p[i])) + d_l[i - 1] + dist (0, p[i - 1]));

	
	return ans;
}