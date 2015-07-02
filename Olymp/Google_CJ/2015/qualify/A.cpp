#include <bits/stdc++.h>

using namespace std;


int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int test;

	cin >> test;

	for (int t = 1; t <= test; ++t) {
		
		int smax;
		string s;

		cin >> smax >> s;

		int now = 0, ans = 0;

		for (int i = 0; i <= smax; ++i) {
			if (now < i) {
				ans += i - now;
				now = i;
			}
			now += s[i] - '0';
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}

	return 0;
}