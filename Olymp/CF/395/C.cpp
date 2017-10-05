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

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

vector <int> c;
int a[N];
int n, m;

inline void check (int x) {
	if (n > m / x * 100) {
		for (int i = 0; i < m; i += x) {
			int cnt = lower_bound (a + 1, a + n + 1, i + x) - lower_bound (a + 1, a + n + 1, i);
			if (cnt >= n / (m / x) + 2)
				return;
		}
	}
	int end = 0, cnt = 0;
	for (int i = 1; cnt != 2 && i <= n; ++i) {
		if (!binary_search (a + 1, a + n + 1, (a[i] + x) % m)) {
			++cnt, end = a[i];
		}
	}
	if (cnt == 2)
		return;
	if (cnt == 0) {
		cout << a[1] << " " << x;
	} else {
		cout << end << " " << m - x;
	}
	exit (0);
}

inline int Rand (int m) {
	return (rand () * 1ll * rand () + rand ()) % m;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	srand (time (0));

	cin >> m >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	sort (a + 1, a + n + 1);

	if (n == 1) {
		cout <<	a[1] << " " << m - 1;
		return 0;
	} else if (n == 2) {
		cout << a[1] << " " << a[2] - a[1];
		return 0;
	}

	for (int i = 2; i <= n; ++i) {
		c.eb ((a[i] - a[1]));
		c.eb ((m - a[i] + a[1]));
	}

	random_shuffle (c.begin (), c.end (), Rand);
	
	for (auto it : c)
		check (it);
	
	cout << -1;
	
	return 0;
}