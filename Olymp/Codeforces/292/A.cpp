#include <bits/stdc++.h>

using namespace std;

string s;

int n, cnt[10];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		int temp = s[i] - '0';
		for (int j = 2; j <= temp; ++j) {
			if (j == 4) {
				cnt[2] += 2;
			}
			else if (j == 6) {
				cnt[2] += 1;
				cnt[3] += 1;
			}
			else if (j == 8) {
				cnt[2] += 3;
			}
			else if (j == 9) {
				cnt[3] += 2;
			}
			else
				cnt[j] += 1;
		}
	}



	for (int i = 9; i > 1; --i) {
		while (cnt[i]--) {
			cout << i;
			for (int j = 2; j < i; ++j) {
				if (j == 4) {
					cnt[2] -= 2;
				}
				else if (j == 6) {
					cnt[2] -= 1;
					cnt[3] -= 1;
				}
				else if (j == 8) {
					cnt[2] -= 3;
				}
				else if (j == 9) {
					cnt[3] -= 2;
				}
				else
					cnt[j] -= 1;
			}
		}
	}

	return 0;
}