#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e3 + 100;

int a[N][5], d1[N][N], d2[N];


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < 5; ++k) {
				d1[i][j] += a[i][k] * a[j][k];
			}
		}
	}	
	
	vector <int> ans;
		
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d2[j] = 0;
			for (int k = 0; k < 5; ++k) {
				d2[j] -= a[j][k] * a[i][k];
			}
		}
		int value = 0;
		for (int j = 0; j < 5; ++j)
			value += a[i][j] * a[i][j];
		bool good = 1;
		for (int j = 1; j <= n; ++j) {
			if (j == i)
				continue;
			for (int k = j + 1; k <= n; ++k) {
				if (k == i)
					continue;
				if (d1[j][k] + d2[j] + d2[k] + value > 0)
					good = 0;
			}
		}
		if (good)
			ans.emplace_back (i);
	}	
	
	cout << ans.size () << "\n";

	for (auto it : ans)
		cout << it << " ";
	return 0;
}