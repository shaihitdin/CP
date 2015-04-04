#include <bits/stdc++.h>

using namespace std;

const int N = 302;

string d[N][N], ans[N];
int a[N], n;

inline bool cmp_string (const string &x, const string &y) {
	if (x.size() == y.size())
		return x < y;
	return x.size() < y.size();
}

string check;

inline bool can (const int &x) {

	ans[n] = d[x][a[n]];
	if (ans[n] == check)
		return 0;
	for (int i = n - 1; i; --i) {
		bool flag = 0;
		for (int j = N - 1; j; --j)
			if (cmp_string (d[j][a[i]], ans[i + 1])) {
				ans[i] = d[j][a[i]];
				flag = 1;
				break;
			}
		if (!flag)
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
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			d[i][j].append (N, '9');
	for (int i = 1; i <= n; ++i) {
		
	}

	check.append (N, '9');
	for (int i = 0; i <= 9; ++i)
		d[1][i] = char ('0' + i);	

	for (int i = 0; i < N - 1; ++i)
		for (int j = 0; j < N; ++j) {
			if (i == 1 && j == 0)
				continue;
			for (char add = '0'; j + add - '0' < N && add <= '9'; ++add)
				if (d[i + 1][j + add - '0'] > d[i][j] + add)
					d[i + 1][j + add - '0'] = d[i][j] + add;
	}
	/*
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << "\n";
	}
	*/
	int l = 0, r = N;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (can (mid))
			r = mid;
		else
			l = mid;
	}
	can (r);
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << "\n";
	return 0;
}