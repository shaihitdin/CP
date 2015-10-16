#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int,int>> v;
int a[101];
#define mkp make_pair
#define F first
#define S second
long long n, r, x, y;
long long sum, avg, ans;
inline bool cazza (const pair <int, int> &l, const pair <int, int> &r) {
	if (l.second < r.second)
		return 1;
	else
		return 0;
} 
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%I64d%I64d%I64d", &n, &r, &avg);
	for (int i = 1; i <= n; ++i) {
		scanf ("%I64d%I64d", &x, &y);
		v.push_back ({x, y});
		sum += x;
	}
	avg *= n;
	sort (v.begin(), v.end(), cazza);
	for (auto x : v) {
		if (sum >= avg)
			break;
		cerr << sum << " " << avg << "\n";
		ans += ( min (avg - sum, r - x.F) * x.S);
		sum += ( min (avg - sum, r - x.F) );
	}
	printf ("%I64d", ans);
	return 0;
}