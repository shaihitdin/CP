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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

map <int, int> cc;
int n, m, a[N], b[N], c[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cc[a[i]];
	}
	
	cin >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	
	for (int i = 1; i <= m; ++i) {
		cin >> c[i];
	}
	
	int mx = 1;

	for (int i = 2; i <= m; ++i) {
		if (mp (cc[b[i]], cc[c[i]]) > mp (cc[b[mx]], cc[c[mx]]))
			mx = i;
	}	
	
	cout << mx;
	
	return 0;
}