#include <bits/stdc++.h>

using namespace std;

const int N = 510;

pair <int, int> b[N];
int a[N];
char u[N][N];
int available[N];

int main () {

	freopen ("chip.in", "r", stdin);
	freopen ("chip.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m, h;
	
	cin >> n >> m >> h;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= m; ++i) {
		cin >> b[i].first;
		b[i].second = i;
	}	

	for (int i = 1; i <= n; ++i)
		available[i] = m;
	
	for (int i = 1; i <= n; ++i) {
		sort (b + 1, b + m + 1);
		for (int j = 1; j <= m && a[i]; ++j) {
			if (u[i][b[j].second] > 0)
				continue;
			--a[i];
			u[i][b[j].second] = '*';
		}
		if (a[i] > 0) {
			cout << "inconsistent";
			return 0;
		}
		for (int j = m; j >= 1; --j) {
			if (u[i][b[j].second] > 0)
				continue;
			bool flag = 1;
			if (b[j].first == 0)
				continue;
			for (int k = i + 1; k <= i + h - 1; ++k) {
				if (u[k][b[j].second] == 0 && available[k] - 1 < a[k]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				u[i][b[j].second] = '+';
				u[i + h - 1][b[j].second] = '+';
				--available[i + h - 1];
				for (int k = i + 1; k < i + h - 1; ++k) {
					--available[k];
					u[k][b[j].second] = '|';
				}
				--b[j].first;
			}
		}
	}
	
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (u[i][j] == 0) {
				cout << "inconsistent";
				return 0;
			}
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		if (b[i].first > 0) {
			cout << "inconsistent";
			return 0;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << u[i][j];
		cout << "\n";
	}	
	
	return 0;
}