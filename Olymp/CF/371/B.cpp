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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

inline int query (int sx, int fx, int sy, int fy) {
	if (sx > fx)
		swap (sx, fx);
	if (sy > fy)
		swap (sy, fy);
	cout << "? " << sx << " " << sy << " " << fx << " " << fy << endl;
	int x;
	cin >> x;
	return x;
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n;
	
	int l = 0, r = n + 1;


	//FIND MAX X OF BOTH
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (query (1, mid, 1, n) == 2)
			r = mid;
		else
			l = mid;
	}
	
	maxx = r;

	int l = 0, r = n + 1;

	//FIND MIN X OF BOTH
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (query (mid, n, 1, n) == 2)
			l = mid;
		else
			r = mid;
	}
	
	minx = l;

	if (minx == maxx || query (minx, maxx - 1, 1, n) == 0) {
		if (minx == maxx || query (minx + 1, maxx, 1, n) == 0) {
			// BOTH X1 and X2 are equal
		}
		l = 0, r = maxx + 1;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (query (mid, maxx, 1, n) > 0)
				l = mid;
			else
				r = mid;
		}
		secondx = l;

	}
	
	
	return 0;
}