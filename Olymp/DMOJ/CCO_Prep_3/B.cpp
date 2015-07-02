#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 3e6;

ull d[N], sum[N], a[N];

int n, limit;

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	ios_base :: sync_with_stdio (0);

	cin >> n >> limit;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + 1 + a[i];
	
	for (int i = 2; i <= n; ++i)
		--d[i];
	
	d[1] = 0;

	for (int i = 1; i <= n; ++i) {
		int l = i, r = n;
		while (r - l > 30) {
			int mid = (r + l) >> 1;
			if (sum[mid] - sum[i - 1] - 1 <= ull (limit))
				l = mid;
			else
				r = mid;
		}
		for (; l <= r; ++l) {
			ll temp = sum[l] - sum[i - 1] - 1;
			temp -= limit;
			temp = abs (temp);
			temp *= temp;
			if (d[i] + ull (temp) >= d[i])
				d[l + 1] = min (d[l + 1], d[i] + temp);
		}
	}
	
	cout << d[n];
	
	return 0;
}