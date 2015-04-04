#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> t;
	cin >> k;

	for (int i = 1; i <= k; ++i)
		cin >> s[i];
	for (int i = 0; i <= 'z' - 'a'; ++i)
		cin >> c[i];
	
	for (int it = 1; it <= k; ++it) {
		string zz;
		zz = s[it] + '#' + t;
		memset (p, 0, sizeof (p));
		for (int i = 1; i < zz.size(); ++i) {
			j = p[i - 1];
			while (j && zz[i] != zz[j])
				j = p[j - 1];
			if (zz[i] == zz[j])
				++j;
			if (j == s[it].size())
				u[it][j - s[it].size() - 1] = 1;
		}
	}
	for (int i = 0; i <= 'z' - 'a'; ++i)
		nxt[t.size()][i] = t.size();
	for (int i = 1; i <= k; ++i)
		nxtw[t.size()][i] = 1e9;
	for (int i = t.size() - 1; i >= 0; --i) {
		for (int j = 0; j <= 'z' - 'a'; ++j)
			if (t[i] == j + 'a')
				nxt[i][j] = i;
			else
				nxt[i][j] = nxt[i + 1][j];
		for (int it = 1; it <= k; ++it)
			if (u[it][i])
				nxtw[i][it] = i;
			else
				nxtw[i][j] = nxtw[i + 1][j];
	}
	for (int i = 1; i < t.size(); ++i)
		d[i] = 1e9;
	d[0] = 0;
	
	for (int i = 0; i < t.size(); ++i) {
		need.resize (0);
		for (int j = 1; j <= k; ++j)
			if (nxtw[i][j] - s[j].size() + 1 <= i)
				need.push_back (j);
		for (int j = 0; j < 'z' - 'a'; ++j) {
			bool flag = 0;
			for (auto it : need) {
				if ()
			}
		}
	}
	return 0;
}