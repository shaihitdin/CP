#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 100;

map <int, int> cc;
set <int> Set;
int a[N], b[N];
int pos[N], pos2[N];
int n, m;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif	
	scanf ("%d%d%*d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		Set.insert (a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%d", &b[i]);
		Set.insert (b[i]);
	}	
	
	
	int cnt = 0;
	for (auto it : Set) {
		cc[it] = ++cnt;
	}	
	
	for (int i = 1; i <= n; ++i)
		a[i] = cc[a[i]];
	for (int i = 1; i <= m; ++i)
		b[i] = cc[b[i]];

	for (int i = 1; i <= n; ++i) {
		++pos[a[i]];
	}

	for (int i = 1; i <= m; ++i) {
	    --pos[b[i]];
	}

	cnt = 0;

	for (int i = N - 1; i >= 0; --i) {
		if (cnt > 0) {
			printf ("YES");
			return 0;
		}
		cnt += pos[i];
	}
	
	printf ("NO");
	
	return 0;
}