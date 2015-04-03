#include <bits/stdc++.h>

using namespace std;

int a[100001], d1[100001], d2[100001], n;
int main () {
	freopen ("out", "r", stdin);	
	n = 15468;
	//cin >> n;	
	for (int j = 1; j <= n; ++j)
		cin >> a[j];
	for (int it1 = 1; it1 <= n; ++it1)
		d1[it1] = d2[it1] = 1;
	for (int it1 = 1; it1 <= n; ++it1)
			for (int it2 = 1; it2 < it1; ++it2)
				if (a[it1] > a[it2])
					d2[it1] = max (d2[it1], d2[it2] + 1);
				else
					d1[it1] = max (d1[it1], d1[it1] + 1);
	int ans = 0;
	for (int it1 = 1; it1 <= n; ++it1)
		ans = max (ans, max (d1[it1], d2[it1]));
	cerr << ans;
	return 0;
}