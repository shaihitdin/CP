#include <bits/stdc++.h>

using namespace std;

const int N = 50;

int d[N][N];

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			for (int k = 1; k < i; ++k)
				if (!d[max (k, i - k)][j])
					d[i][j] = 1;
			for (int k = 1; k < j; ++k)
				if (!d[i][max (k, j - k)])
					d[i][j] = 1;			
			cout << i << " " << j << " == " << d[i][j] << " : ";
			for (int k = 1; k <= i / 2; ++k)
				if (!d[max (k, i - k)][j])
					cout << max (k, i - k) << " " << j << " || ";
			for (int k = 1; k <= j / 2; ++k)
				if (!d[i][max (k, j - k)])
					cout << i << " " << max (k, j - k) << " || ";
			cout << "\n";
		}
		cout << "\n";
	}
	
	/*
	while (1) {
		int n, m;
		cin >> n >> m;
		
		if (n == -1 && m == -1) {
			return 0;
		}

	}
	*/
	return 0;
}