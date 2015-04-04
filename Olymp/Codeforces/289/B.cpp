#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int a[N], n, k, b[N], colored_prev;
vector <int> ans[N];

inline bool cmp (const int &x, const int &y) {
	return a[x] < a[y];
}

inline void color (const int &heap, const int &num, const int &colors) {
	for (int i = 1; i <= num; ++i)
		ans[heap].push_back (colors);
	a[heap] -= num;
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
	for (int i = 1; i <= k; ++i) {
		sort (b + 1, b + n + 1, cmp);
		colored_prev = a[b[1]];
		color (b[1], colored_prev, i);
		for (int j = 2; j <= n; ++j) {
			int temp = min (a[b[j]], colored_prev + 1);
			color (b[j], temp, i);
		}
		bool flag = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[j] != 0)
				flag = 1;
		}
		if (!flag) {
			cout << "YES\n";
			for (int i = 1; i <= n; ++i) {
				for (int stones : ans[i]) {
					cout << stones << " ";
				}
				cout << "\n";
			}
			return 0;
		}
	}
	cout << "NO";
	return 0;
}