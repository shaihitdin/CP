/// izizi

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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int d[1100][1100];
int N;

inline bool inside (int x, int y) {
	return 1 <= x && 1 <= y && x <= N && y <= N;
}

inline bool losing_position (int x, int y) {
	if ((x % 4 == 1 || x % 4 == 2) && (y % 4 == 1 || y % 4 == 2))
		return 1;
/*
	if (x == N && y == N && x % 4 == 0)
		return 1;
*/
	/*
	for (int j = 0; j < 4; ++j)
		if (inside (x + dx[j], y + dy[j]) && losing_position (x + dx[j], y + dy[j], depth + 1))
			return 0;
	return 1;
	*/
	return 0;
}


inline int calc (int n, int m) {
	if (d[n][m] != -1)
		return d[n][m];
	set <int> Set;
	if (inside (n - 2, m + 1))
		Set.insert (calc (n - 2, m + 1));
	if (inside (n - 2, m - 1))
		Set.insert (calc (n - 2, m - 1));
	if (inside (n - 1, m - 2))
		Set.insert (calc (n - 1, m - 2));
	if (inside (n + 1, m - 2))
		Set.insert (calc (n + 1, m - 2));
	int mex = 0;
	for (;Set.count (mex); ++mex);
	return d[n][m] = mex;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	memset (d, -1, sizeof (d));
	for (N = 1; N <= 200; ++N) {
		memset (d, -1, sizeof (d));
		cout << N << ":\n";
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cout << calc (i, j) << " ";
			}
			cout << "\n";
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (calc (i, j) && losing_position (i, j)) {
					assert (0);
					cout << "Le toucan " << N << " " << i << " " << j << "\n";
				}/* else if (calc (i, j) == 0 && losing_position (i, j) == 0) {
					cout << "Le toucan " << N << " " << i << " " << j << "\n";				
				}*/
			}
		}
		cout << "\n";
	}	

	return 0;
}