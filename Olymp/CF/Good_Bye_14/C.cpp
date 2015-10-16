#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>
using namespace std;
const int N = 1001;
int n, m, w[N], a[N], ans;
int place;
bool u[N];
vector <int> pl;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &w[i]);
	}
	for (int i = 1; i <= m; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= m; ++i) {
		if (!u[a[i]]) {
		    pl.push_back (a[i]);
			u[a[i]] = 1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		int j = 0;
		for (; pl[j] != a[i]; ++j)
			ans += w[pl[j]];
		pl.erase (pl.begin() + j);
		pl.insert (pl.begin(), a[i]); 
	}
	printf ("%d", ans);
	return 0;
}