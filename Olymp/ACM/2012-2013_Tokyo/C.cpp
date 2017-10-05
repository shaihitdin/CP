#include <bits/stdc++.h>

using namespace std;

typedef vector <vector <int> > matrix;

int m;
inline matrix operator * (matrix a, matrix b) {
	auto c = a;
	for (int i = 0; i < a.size (); ++i)
		for (int j = 0; j < a.size (); ++j)
			c[i][j] = 0;
	for (int k = 0; k < c.size (); ++k) {
		for (int i = 0; i < c.size (); ++i) {
			for (int j = 0; j < c.size (); ++j) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= m;
			}
		}
	}
	return c;
}

matrix zero;

inline matrix bin_pow (matrix a, int b) {
	if (!b)
		return zero;
	if (b & 1)
		return bin_pow (a, b - 1) * a;
	auto c = bin_pow (a, b / 2);
	return c * c;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	while (1) {
		int n, a, b, c, t;
		cin >> n >> m >> a >> b >> c >> t;
		if (n + m + a + b + c + t == 0)
			return 0;
		matrix mat;
		mat.resize (n + 1);
		zero.clear ();
		zero.resize (n + 1);
		for (int i = 0; i < n + 1; ++i) {
			zero[i].resize (n + 1);
			mat[i].resize (n + 1);
		}
		for (int i = 0; i < n + 1; ++i)
			zero[i][i] = 1;
		
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			mat[i][n] = x;
			if (i > 0)
				mat[i][i - 1] = a;
			mat[i][i] = b;
			if (i + 1 < n)
				mat[i][i + 1] = c;
		}
		
		/*		
		cerr << "HERE IS THE MATRIX: ";
		for (int i = 0; i < n; ++i) {
			cerr << mat[i][n] << " ";
		}
		cerr << "\n";
		*/
		mat = bin_pow (mat, t + 1);

		for (int i = 0; i < n; ++i)
			cout << mat[i][n] << " ";
		cout << "\n";
	}

	return 0;
}