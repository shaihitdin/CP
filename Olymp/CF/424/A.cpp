#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	int state = -1;

	for (int i = 2; i <= n; ++i) {
		int n_state = -2;
		if (a[i] > a[i - 1]) {
			n_state = -1;
		} else if (a[i] == a[i - 1]) {
			n_state = 0;
		} else {
			n_state = 1;
		}
		if (state > n_state) {
			cout << "NO";
			return 0;
		}
		state = n_state;
	}

	cout << "YES";
	return 0;
}