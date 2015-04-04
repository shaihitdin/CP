#include <bits/stdc++.h>

using namespace std;
const int N = 101;
int n, k, a[N], b[N];
vector <int> ans;
inline bool cmp (const int &x, const int &y) {
	return a[x] < a[y];
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		b[i] = i;
	sort (b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		if (a[b[i]] <= k) {
			ans.push_back (b[i]);
			k -= a[b[i]];
		}
	}
	cout << ans.size() << "\n";
	for (auto it : ans)
		cout << it << " ";
	return 0;
}