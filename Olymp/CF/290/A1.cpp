#include <bits/stdc++.h>

using namespace std;
const int N = 101;

string s[N];
char u[N];
int in[N];
vector <int> g[N], top_sort;
char ans[N];
int n;

inline void dfs (const int &v) {
	u[v] = 2;
	for (auto to : g[v]) {
		if (u[to] == 2) {
			cout << "Impossible";
			exit (0);
		}
		if (u[to] == 0) {
			dfs (to);
		}
	}
	u[v] = 1;
	top_sort.push_back (v);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	for (int i = 2; i <= n; ++i) {
		for (int k = 1; k < i; ++k) {
			int j = 0;
			for (; j < s[i].size() && j < s[k].size() && s[i][j] == s[k][j]; ++j);
			if (j == s[i].size() || j == s[k].size()) {
				if (s[i].size() < s[k].size()) {
					cout << "Impossible";
					return 0;
				}
			}
			else {
				g[s[i][j] - 'a'].push_back (s[k][j] - 'a');
			}
		}
		
	}
	for (int i = 25; i >= 0; --i)
		if (u[i] == 0)
			dfs (i);

	reverse (top_sort.begin(), top_sort.end());

	for (int i = 0; i < top_sort.size(); ++i) {
		ans['z' - i - 'a'] = top_sort[i];
		cerr << top_sort[i] << " ";
	}
	for (int i = 0; i < 26; ++i)
		cout << char (ans[i] + 'a');
	return 0;
}