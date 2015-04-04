#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 1;

int crash[N];

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	crash[1] = 2;
	crash[2] = 1;
	crash[3] = 5;
	crash[4] = 7;
	crash[5] = 3;
	crash[7] = 4;
	for (int i = 6, m = 2; i < N / 2; ++i) {
		if (crash[i]) {
			++m;
		}
		else {
			crash[i] = i * 2 - m;
			crash[i * 2 - m] = i;
		}
	}	
	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		int a, b;
		cin >> a >> b;
		if (crash[a] == b) {
			cout << (a ^ b) << "\n";
		}
		else {
			cout << "MANSUR\n";
		}
	}
	return 0;
}