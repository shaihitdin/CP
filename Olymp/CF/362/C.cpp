/// Stupido del problemo

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second
#define int ll

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

typedef vector <vector <int> > matrix;

matrix zero_matrix;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline matrix operator * (const matrix &a, const matrix &b) {
	matrix c;
	c.resize (a.size ());
	for (int i = 0; i < c.size (); ++i)
		c[i].resize (b[0].size ());
	for (int k = 0; k < a[0].size (); ++k)
		for (int i = 0; i < a.size (); ++i)
			for (int j = 0; j < b[0].size (); ++j)
				add (c[i][j], b[k][j] * a[i][k] % bpr);
	return c;
}

inline matrix bin_pow (const matrix &a, ll b) {
	if (!b)
		return zero_matrix;
	if (b & 1)
		return bin_pow (a, b - 1) * a;
	auto c = bin_pow (a, b / 2);
	return c * c;
}


inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return bin_pow (x, y - 1) * x % bpr;
	int c = bin_pow (x, y / 2);
	return c * c % bpr;
}

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
		
	int n;
	cin >> n;
	int tema = 1, tema2 = 1;
	zero_matrix.resize (2);
	for (int i = 0; i < 2; ++i) {
		zero_matrix[i].resize (2);
		zero_matrix[i][i] = 1;
	}

	matrix tmp;
	tmp.resize (2);
	for (int i = 0; i < 2; ++i)
		tmp[i].resize (2);
	tmp[0][1] = 1;
	tmp[0][0] = 1;
	tmp[1][0] = 2;
	int part2 = 2;
	while (n--) {
		int x;
		cin >> x;
		x %= (bpr - 1);
		tema *= x;
		tema %= (bpr - 1);
/*	
		tmp = bin_pow (tmp, x);
		part2 = bin_pow (part2, x);
*/
	}
			
	tmp = bin_pow (tmp, tema);
	part2 = bin_pow (part2, tema);

	cout << (tmp[1][1] * bin_pow (2, bpr - 2) % bpr) << "/" << (part2 * bin_pow (2, bpr - 2) % bpr) << "\n";
	
	return 0;
}