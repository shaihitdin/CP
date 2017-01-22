#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

int n;
string s[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	int k = 6;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int tmp = 0;
			for (int kk = 0; kk < 6; ++kk) {
				if (s[i][kk] != s[j][kk])
					++tmp;
			}
			k = min (k, (tmp + 1) / 2 - 1);
		}
	}
	
	cout << k;
	
	return 0;
}