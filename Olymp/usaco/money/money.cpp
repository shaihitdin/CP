/*
ID: shaihit1
PROG: money
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int n, v;

long long d[10001];
int a[26];
int main() {
	
	freopen ("money.in", "r", stdin);
	freopen ("money.out", "w", stdout);

	cin >> v >> n;

	for (int i = 1; i <= v; ++i)
		cin >> a[i];
	d[0] = 1;

	for (int i = 1; i <= v; ++i)
		for (int j = 0; j + a[i] <= n; ++j)
			d[j + a[i]] += d[j];
	cout << d[n] << "\n";
	
	return 0;
}
