#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3010;

const ll inf = 1e18;

ll ans;

int test, n, d, m[N];

int main () {
    /*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	cin >> test;

	for (int t = 1; t <= test; ++t) {
		
		cin >> n >> d;

		for (int i = 1; i <= n; ++i)
			cin >> m[i];

		sort (m + 1, m + n + 1);
		
	}

	return 0;
}