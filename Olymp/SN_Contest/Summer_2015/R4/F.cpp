#include <bits/stdc++.h>

using namespace std;

const int N = 51;

bool u[N];
int a[N];
map <int, int> Map1;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int x, y, n;

	cin >> x >> y >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 2; i * 1ll * i <= y; ++i) {
		while (y % i == 0) {
			++Map1[i];
			y /= i;
		}
	}
	
	if (y > 1)
		++Map1[y];

	for (int i = 1; i <= n; ++i)
		++Map1[a[i]];
	
	for (int i = 2; i * 1ll * i <= x; ++i) {
		while (x % i == 0) {
			--Map1[i];
			x /= i;
		}
	}
	
	if (x > 1)
		--Map1[x];
	
	for (auto it : Map1) {
		if (it.second < 0) {
			cout << -1;
			return 0;
		}
		for (int i = 1; i <= it.second; ++i) {
			int pos = -1;
			for (int j = 1; j <= n; ++j) {
				if (u[j] || a[j] < it.first)
					continue;
				if (pos == -1)
					pos = j;
				else if (a[pos] > a[j])
					pos = j;
			}
			if (pos == -1) {
				cout << -1;
				return 0;
			}
			a[pos] = it.first;
			u[pos] = 1;
		}
	}
	
	for (int i = 1; i <= n; ++i)
		if (!u[i])
			a[i] = 1;
	
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	
	return 0;
}