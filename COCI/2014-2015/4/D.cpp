#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1001;
vector <int> g[N];
long double need[N], percent[N];
int x[N], y[N], n, super[N];
const long double eps = 1 / (1e18);
const long double eps1 = 1 / (1e4);
string s;
bool eq (const long double &a, const long double &b) {
	return fabs (a - b) < eps;
} 
bool dfs (const int &v, const long double &f) {
	if (need[v] != -1) {
		if (f > need[v] || eq(need[v], f))
			return 1;
		return 0;
	}
	for (auto id : g[v]) {
		long double n_f = (f / 100) * percent[id];
		if (super[id] == 1)
			n_f *= n_f;
		if (!dfs (y[id], n_f))
			return 0;
	}
	return 1;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> x[i] >> y[i] >> percent[i] >> super[i];
		
		g[x[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
		cin >> need[i];
	long double l = -1, r = 2e9;
	while (r - l > eps1) {
		long double mid = (r + l) / 2;
		if (dfs (1, mid) )
			r = mid;
		else
			l = mid;
	}
	cout.precision (20);
	cout << max (r, (long double)0.000);
	return 0;
}