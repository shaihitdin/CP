/*
ID: shaihit1
PROG: holstein
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 30;

vector <int> ans, temp_v;
int temp[N], n, m, a[N], b[N][N];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int main() {
	
	freopen ("holstein.in", "r", stdin);
	freopen ("holstein.out", "w", stdout);

	scanf ("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf ("%d", &a[i]);
	
	scanf ("%d", &m);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf ("%d", &b[i][j]);
	for (int i = 0; i < m; ++i)
		ans.push_back (i);
	for (int i = 0; i < (1 << m); ++i) {
		
		memset (temp, 0, sizeof (temp));
		temp_v.resize (0);
		for (int j = 0; j < m; ++j) {
			if (bit (i, j)) {
				for (int k = 0; k < n; ++k)
					temp[k] += b[j][k];
				temp_v.push_back (j);
			}
		}
		bool flag = 0;
		for (int j = 0; j < n; ++j)
			if (temp[j] < a[j])
				flag = 1;
		if (flag)
			continue;
		if (temp_v.size() < ans.size() || (temp_v.size() == ans.size() && temp_v < ans)) {
			ans = temp_v;
		}
	}
	printf ("%d ", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf ("%d", ans[i] + 1);
		if (i + 1 == ans.size())
			putchar ('\n');
		else
			putchar (' ');
	}
	return 0;
}
