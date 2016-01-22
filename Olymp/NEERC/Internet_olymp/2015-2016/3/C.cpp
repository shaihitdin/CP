#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int n, k;

int a[N][N];

int main () {

	freopen ("competition.in", "r", stdin);
	freopen ("competition.out", "w", stdout);


	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cout << (i + j) % 11 << " ";
		}
		cout << "\n";
	}

	return 0;
}