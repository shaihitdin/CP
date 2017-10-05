#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int t;

	cin >> t;

	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": ";
		string x;
		int k;
		cin >> x >> k;
		int ans = 0;
		for (int i = 0; i + k - 1 < x.size (); ++i) {
			if (x[i] == '-') {
				++ans;
				for (int j = 0; j < k; ++j)
					if (x[i + j] == '-')
						x[i + j] = '+';
					else
						x[i + j] = '-';
			}
		}
		for (int i = 0; i < x.size (); ++i) {
			if (x[i] == '-') {
				ans = 1e9;
			}
		}
		if (ans == 1e9)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << "\n";
	}


	return 0;
}