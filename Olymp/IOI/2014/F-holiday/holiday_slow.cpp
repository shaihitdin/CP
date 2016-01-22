#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 100;

inline int calc (const int &l, const int &r, const int &start) {
	if (l <= start && start <= r)
		return min (start - l, r - start) * 2 + max (start - l, r - start);
	return max (abs (start - l), abs (r - start));
}

ll findMaxAttraction(int n, int start, int d, int a[]) {
    if (n > 10000)
    	return 0;
    if (d == 0)
    	return 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	int l = i, r = i, cnt = 1;
    	ll res = a[i];
    	for (int j = i - 1; j >= 0; --j)
    		if (a[j] > a[i])
    			l = j, ++cnt, res += a[j];
    	for (int j = i + 1; j < n; ++j) {
    		if (a[j] > a[i])
    			r = j, ++cnt, res += a[j];
    		else if (a[j] == a[i] && cnt + 1 + calc (l, j, start) <= d)
    			r = j, ++cnt, res += a[j];
    	}
    	if (calc (l, r, start) + cnt <= d)
    		ans = max (ans, res);
    }
    return ans;
}
