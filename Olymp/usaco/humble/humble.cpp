/*
ID: shaihit1
PROG: humble
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;
int n, a[N], k;

set <int> Set;


int main() {
	
	freopen ("humble.in", "r", stdin);
	freopen ("humble.out", "w", stdout);

	scanf ("%d%d", &k, &n);

	for (int i = 1; i <= k; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= k; ++i)
		Set.insert (a[i]);
	sort (a + 1, a + k + 1);
	for (int i = 1; i < n; ++i) {
		auto it = *Set.begin();
		Set.erase (Set.begin());
		for (int j = 1; j <= k; ++j)
			if (Set.size() >= n - i + 1 && *Set.rbegin() <= it * a[j])
				break;
			else
				Set.insert (it * a[j]);
	}
	printf ("%d\n", *Set.begin());
	return 0;
}
