/*
ID: shaihit1
PROG: skidesign
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 101;

vector <int> g[N];
int h, n, l, r, ans;

inline int sqr (const int &x) {
	return x * x;
}

inline int count_sum (const int &x) {
	int res = 0;
	for (int it : g[x])
		res += (it * it - (sqr (it - 1)));
	return res;
}

inline void del (const int &x, const int &y) {
	for (int it : g[x])
		g[y].push_back (it + 1);
	g[x].resize (0);

}
int main() {
	
	freopen ("skidesign.in", "r", stdin);
	freopen ("skidesign.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &h);
		g[h].push_back (1);
	}	
	l = 0;
	r = 100;
	while (r - l > 17) {
		while (r >= 0 && g[r].empty())	--r;
		while (l <= 100 && g[l].empty())	++l;
		if (r - l <= 17)
			break;
		int res1 = count_sum (l),
		res2 = count_sum (r);
		if (res1 < res2) {
			del (l, l + 1);
			ans += res1;
		}
		else {
			del (r, r - 1);
			ans += res2;
		}
	}
	printf ("%d\n", ans);
	return 0;
}                    	