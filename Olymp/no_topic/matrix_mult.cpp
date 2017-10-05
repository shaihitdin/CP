#include <bits/stdc++.h>

using namespace std;


int n1, m1, n2, m2, a[101][101], b[101][101], c[101][101];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n1 >> m1;

	for (int i = 1; i <= n1; ++i)
		for (int j = 1; j <= m1; ++j)
			cin >> a[i][j];

	cout << "\n";
	
	cin >> n2 >> m2;

	for (int i = 1; i <= n2; ++i)
		for (int j = 1; j <= m2; ++j)
			cin >> b[i][j];

	
	assert (m1 == n2);


	for (int k = 1; k <= m1; ++k) {
		for (int i = 1; i <= n1; ++i) {
			for (int j = 1; j <= m2; ++j) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	cout << "\n";
	
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= m2; ++j) {
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}