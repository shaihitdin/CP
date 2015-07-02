#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

bool u[N];

int c[N];

typedef pair <int, int> pii;

pii a[N];

inline bool cmp (const int &x, const int &y) {
	if (a[x].first == a[y].first)
		return a[x].second < a[y].second;
	return a[x].first < a[y].first;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	
	for (int i = 1; i <= n; ++i)
		c[i] = i;

	sort (c + 1, c + n + 1, cmp);

	int mx = 0;

	for (int j = n; j; --j) {
		int i = c[j];

		if (a[i] == a[c[j + 1]])
			u[i] = u[c[j + 1]];
		
		if (mx < a[i].second) {
			mx = a[i].second;
			u[i] = 1;
			continue;
		}
		u[i] = 0;
	}

	
	for (int i = 1; i <= n; ++i) {
	
	}
	
	return 0;
}