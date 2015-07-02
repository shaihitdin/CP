#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, inf = 1e9 + 7;

int n;
bool u[N];
vector <int> a;

int p[N], d[N];



int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	
	cin >> n;

	u[1] = 1;

	for (int i = 1; i <= n; ++i) {
		if (u[i]) {
			a.push_back (i);
			if (i * 10 <= n)
				u[i * 10 + 1] = u[i * 10] = 1;
		}
	}
	
	for (int i = 1; i <= n; ++i)
		d[i] = inf;

	for (int i = 0; i < n; ++i) {
		for (auto it : a) {
			if (i + it <= n && d[i + it] > d[i] + 1) {
				d[i + it] = d[i] + 1;
				p[i + it] = it;
			}
		}
	}
	
	vector <int> ans;

	int now = n;

	while (now) {
		ans.push_back (p[now]);
		now -= p[now];
	}

	cout << ans.size () << "\n";
	
	for (auto it : ans) {
		cout << it << " ";
	}
	
	return 0;
}