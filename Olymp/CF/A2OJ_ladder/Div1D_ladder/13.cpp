/// Forever

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
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 0;

#define mp make_pair


int d[31] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, };
bool bb[int (1e6)];

unordered_map <int, short> b;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline int calc (int mask) {
	if (b.count (mask))
		return b[mask];
	bool u[15];
	memset (u, 0, sizeof (u));
	for (int i = 1; i <= 29; ++i) {
		if (!bit (mask, i))
			continue;
		int nmask = mask;
		for (int j = i; j <= 29; j += i)
			nmask &= ((-1) ^ (1 << j));
		u[calc (nmask)] = 1;
	}
	int x = 0;
	for (;u[x];++x);
	return b[mask] = x;
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
/*	
	for (int i = 1; i <= 29; ++i)
		cout << (d[i] = calc ((1 << (i + 1)) - 1)) << ", ";
	
	cerr << clock () * 1000 / CLOCKS_PER_SEC << "\n";
*/
	int n;

	cin >> n;	
	
	int s = n;
	int ans = 0;
	for (int i = 2; i * i <= n; ++i) {
		if (bb[i])
			continue;
		int dudu = 0;
		for (ll j = i; j <= n; j *= i, ++dudu, --s) {
			if (j < (int)1e6) {
				if (bb[j])
					++s;
				bb[j] = 1;
			}
		}
		ans ^= d[dudu];
	}
	
	ans ^= (s & 1);

	if (ans)
		cout << "Vasya";
	else
		cout << "Petya";

	return 0;
}