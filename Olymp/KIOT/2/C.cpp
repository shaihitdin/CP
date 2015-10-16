#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N][N];

int n, m;

int cnt[11];

inline bool check () {
	for (int i = 1; i + 2 <= n; ++i) {
		for (int j = 1; j + 2 <= m; ++j) {
			memset (cnt, 0, sizeof (cnt));
			for (int i1 = i; i1 < i + 3; ++i1)
				for (int j1 = j; j1 < j + 3; ++j1)
					++cnt[a[i1][j1]];
			for (int i1 = 1; i1 <= 5; ++i1)
				if (!cnt[i1])
					return 0;
			if (cnt[a[i + 1][j + 1]] != 1) {
				return 0;
			}
		}
	}
	return 1;
}

int main () {

	freopen ("field.in", "r", stdin);
	freopen ("field.out", "w", stdout);


	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		int cnt = a[i - 1][3];
		for (int j = 1; j <= 3; ++j) {
			cnt %= 5;
			++cnt;
			a[i][j] = cnt;
		}
		for (int j = 4; j <= m; ++j) {
			a[i][j] = a[i][j - 2];
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << check () << " ";
	
	return 0;
}