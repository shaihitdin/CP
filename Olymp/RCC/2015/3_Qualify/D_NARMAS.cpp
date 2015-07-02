#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m;
bool u[N], killed[N], action[N], b[N][N], ans[N];
vector <int> res;

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m;

	string shit;
	cin >> shit;
	for (int i = 1; i <= n; ++i)
		ans[i] = (shit[i - 1] == '1');
	
	for (int i = 1; i <= m; ++i) {
		cin >> action[i];
		cin >> shit;
		for (int j = 1; j <= n; ++j)
			b[i][j] = (shit[j - 1] == '1');	
	}	
	
	for (int till = 1; till <= 505; ++till) {
		for (int i = 1; i <= m; ++i) {
			if (u[i])
				continue;
			bool flag = 0;
			for (int j = 1; j <= n; ++j) {
				if (killed[j])
					continue;
				if (!b[i][j])
					continue;
				if (action[i] != ans[j]) {
					flag = 1;
					break;
				}
			}
			if (flag)
				continue;
			for (int j = 1; j <= n; ++j) {
				if (killed[j])
					continue;
				if (b[i][j])
					killed[j] = 1;
			}
			res.push_back (i);
			u[i] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!killed[i] && ans[i]) {
			cout << "NO";
			exit (0);
		}
	}
	
	cout << "YES\n";
	cout << res.size () << "\n";
	reverse (res.begin (), res.end ());
	for (auto it : res) {
		cout << it << " ";
	}
	return 0;
}