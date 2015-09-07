#include <bits/stdc++.h>

using namespace std;

#define left can

const int N = 210;

bool a[N], b[N], u[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, A, B;
	cin >> n >> A >> B;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	
	int ans = 0;
	
	while (++ans) {
		int left = A, first = 0, last = 0;
		memset (u, 0, sizeof (u));
		for (int i = 1; i <= n; ++i) {
			if (a[i] || b[i]) {
				first = i;
				break;
			}
		}

		if (first == 0)
			break;

		for (int i = first; left > 1 && i <= min (n, first + B - 1); ++i) {
			if (a[i] == 1 && b[i] == 1) {
				--left;
				a[i] = 0;
				u[i] = 1;
			}
		}
		for (int i = first; i <= min (n, first + B - 1) && left; ++i) {
			if (u[i])
				continue;
			if (a[i] == 1 && b[i] == 1) {
				--left;
				a[i] = 0;
				u[i] = 1;
			} else if (a[i] || b[i]) {
				--left;
				a[i] = 0;
				b[i] = 0;
			}
		}
	}
	
	--ans;
	cout << ans;
	
	return 0;
}