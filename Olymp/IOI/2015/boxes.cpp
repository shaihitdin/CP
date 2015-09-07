#include <bits/stdc++.h>
#include "boxes.h"

typedef long long ll;

const int N = 1e7 + 100;

ll d_l[N], d_r[N];

ll delivery(int n, int k, int l, int p[]) {
	int l_end, r_end;
	if (n & 1) {
		l_end = n / 2;
		r_end = l_end + 1;
	} else {
		l_end = n / 2;
		r_end = l_end;
	}

    for (int i = 0; i < n && p[i] <= l_end; ++i) {
    	
    }
    
    ll ans = 1e18;
	ll tmp = 0;
	int i = 0;
	while (1) {
		int have = k;
		while (i < n && p[i] <= l_end && have)
			++i, --have;
		int at_least = p[i - 1];
		if (p[i] > l_end) {
			
		}

		tmp += p[i] + p[i];
	}
	
	return ans;
}
