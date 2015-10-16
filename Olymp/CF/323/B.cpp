#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

bool u[N];
int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int now = 0;

	int cnt = 0;

	for (; now < n; ++cnt) {
		if (cnt & 1) {
			for (int i = n; i >= 1; --i) {
				if (now >= a[i] && !u[i]) {
					u[i] = 1;
					++now;
				}
			}
		} else {
			for (int i = 1; i <= n; ++i) {
				if (now >= a[i] && !u[i]) {
					u[i] = 1;
					++now;
				}
			}
		}
		cerr << now << " ";
	}

	--cnt;
	cout << cnt;
	
	return 0;
}