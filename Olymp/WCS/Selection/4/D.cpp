/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 100;

int a[N], d[N];

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;
		
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 2; i <= n; ++i)
		d[i] = d[i - 1] + (a[i] > a[i - 1]);
	
	while (m--) {
		int l, r;
		cin >> l >> r;
		
		if (l == r) {
			cout << "N";
			continue;
		}

		if (r - l == d[r] - d[l])
			cout << "Y";
		else
			cout << "N";
	}
	
	return 0;
}