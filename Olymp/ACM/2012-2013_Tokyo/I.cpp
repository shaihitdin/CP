#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 1e5 + 100;

int a[N], sum[N], dp[N], dp_sum[N];
int n, w;

inline int get_sum (int l, int r, int x) {
	if (l == 0)
		return sum[r] + r * x;
	return sum[r] - sum[l - 1] + (r - l) * x;
}

inline bool get_sum_dp (int l, int r) {
	if (l > r)
		return 0;
	if (l > 0)
		return dp_sum[r] - dp_sum[l - 1] > 0;
	return 1;
}

inline bool check (int x) {
    for (int i = 1; i <= n; ++i)
    	dp[i] = dp_sum[i] = 0;
	dp[0] = dp_sum[0] = 1;
	int L = 1, R = 1;
	for (int i = 1; i <= n; ++i) {
		dp_sum[i] += dp_sum[i - 1];

		if (get_sum (1, i, x) < w)
			continue;
		
		/*
		int l = 0, r = i + 1;
		while (r - l > 1) {
	    	int mid = (r + l) / 2;
	    	if (get_sum (mid, i, x) < w)
	    		r = mid;
			else
				l = mid;
		}
		int R = l;
		*/
		while (R < i + 1 && get_sum (R, i, x) >= w)	++R;
		R--;
		/*
		if (l == 0 || get_sum (l, i, 1) > w)
			continue;
		*/
		
		/*
		r = l, l = 0;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (get_sum (mid, i, 1) <= w)
				r = mid;
			else
				l = mid;
		}

		int L = r;
		*/
		while (L < i + 1 && get_sum (L, i, 1) > w)	++L;
		//--L;
		
		if (get_sum (L, i, 1) <= w && get_sum (R, i, x) >= w && get_sum_dp (L - 1, R - 1))
			dp[i] = 1, dp_sum[i]++;
		
	}
	for (int i = 1; i <= n; ++i)
		if (dp[i - 1] && get_sum (i, n, 1) <= w)
			return 1;
	return dp[n];
}

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	while (1) {
		cin >> w >> n;
		if (w + n == 0) {
			break;
		}
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			sum[i] = sum[i - 1] + a[i];
		int l = 0, r = w + 1;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (check (mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << r << "\n";
	}

	
	return 0;
}