#include <bits/stdc++.h>

using namespace std;

const int N = 15, M = 1e4 + 100;

double prob[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			prob[i] = 1;
			for (int j = 1; j <= m; ++j) {
				double x;
				cin >> x;
				prob[i] *= x;
			}
		}

		double latest = 1e6;
		/*
		for (int i = 1; i <= n; ++i) {
			if (prob[i] == 0)
				continue;
			latest = min (latest, 1 / prob[i]);
		}
		*/
		double sum = 0;

		for (int i = 1; i <= n; ++i)
			sum += prob[i] * latest;
		
		cout << fixed;
		cout.precision (6);
		cout << (prob[1] * latest) / sum << "\n";
	}

	return 0;
}