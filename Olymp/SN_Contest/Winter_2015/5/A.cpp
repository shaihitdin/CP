#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int a[N], t, n, b[N], c[N], s, p, k;
bool u[N];

inline bool cmp (const int &x, const int &y) {
	return a[x] > a[y];
}

inline bool operator < (const pair <int, int> &lh, const pair <int, int> &rh) {
	return lh.first > rh.second;
}

int main () {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	scanf ("%d", &t);

	while (t--) {
		scanf ("%d%d%d", &n, &s, &p);
		
		for (int i = 1; i <= p; ++i)
			scanf ("%d", &a[i]);
		
		for (int i = 1; i <= n; ++i)
			u[i] = 0;
		for (int i = 1; i <= p; ++i)
			u[i] = 1;
		
		for (int i = 1; i <= n - p; ++i)
			scanf ("%d", &a[i + p]);
		
		for (int i = 1; i <= n; ++i)
			b[i] = i;
		
		sort (b + 1, b + n + 1, cmp);
		
		scanf ("%d", &k);
		
		for (int i = 1; i <= k; ++i)
			scanf ("%d", &c[i]);

		sort (c + 1, c + k + 1);
		
		int j = 1;
		set <pair <int, int> > Set;
		for (int i = 1; i <= n && j <= k; ++i) {
			if (u[b[i]]) {
				if (Set.size() == k) {
					while (j <= k && a[b[i]] + c[j] < (*Set.begin()).first) {
						++j;
					}
					if (a[b[i]] + c[j] > )
				}
				else {
					
				}
			}
		}
		sort (b + 1, b + n + 1, cmp);
		
		int ans = 0;
		
		for (int i = 1; i <= n; ++i)
			if (u[b[i]] && a[b[s]] <= a[b[i]])
				++ans;
		
		printf ("%d\n", ans);
	}

	return 0;
}