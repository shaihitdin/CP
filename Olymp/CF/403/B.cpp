#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair

const int N = 2000;

int n;
string f[N], s[N], ans[N];


map <string, int> p1;
string p2[N];
bool used[N];
vector <string> g[N];

inline bool dfs (int v) {
	if (used[v])
		return 0;
	used[v] = 1;
	for (auto it : g[v]) {
		if (!p1[it] || dfs (p1[it])) {
			p1[it] = v;
			p2[v] = it;
			return 1;
		}
	}
	return 0;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		string x, y;
		cin >> x >> y;
		f[i] = x[0];
		f[i] += x[1];
		s[i] = f[i];
		f[i] += x[2];
		s[i] += y[0];
	}
	
	for (int i = 1; i <= n; ++i) {
		bool flag = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			if (f[i] == f[j])
				flag = 1;
		}
		if (flag == 1)
			ans[i] = s[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!ans[i].size ()) {
			g[i].eb (f[i]);
			g[i].eb (s[i]);
		} else {
			g[i].eb (s[i]);
		}
	}	

	for (int run = 1; run;) {
		run = 0;
		memset (used, 0, sizeof (used));
		for (int i = 1; i <= n; ++i) {
			if (!p2[i].size ()) {
				if (dfs (i)) {
					run = 1;
				}
			}
		}
	}	

	for (int i = 1; i <= n; ++i) {
		if (!ans[i].size () && !p2[i].size ()) {
			cout << "NO\n";
			return 0;
		}
		if (!ans[i].size ())
			ans[i] = p2[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			if (ans[i] == ans[j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	
	cout << "YES\n";

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}