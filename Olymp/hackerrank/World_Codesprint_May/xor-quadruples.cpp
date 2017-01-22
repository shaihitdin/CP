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

const int oo = 1e9, bpr = 1e9 + 7, N = 4096;

ll nx[N][N], pre[N][N];
int a[5];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	for (int i = 1; i <= 4; ++i)
		cin >> a[i];
	
	sort (a + 1, a + 4 + 1);

	for (int i = 0; i < N; ++i)
		nx[i][0] = 1;
		
	for (int i = 1; i <= 4; ++i) {
		memcpy (pre, nx, sizeof (pre));
		memset (nx, 0, sizeof (nx));
		for (int j = 1; j <= a[i]; ++j) {
			for (int k = 0; k < N; ++k) {
				nx[j][k] = pre[j][k ^ j];
			}
		}
		for (int j = 1; j < N; ++j)
			for (int k = 0; k < N; ++k)
				nx[j][k] += nx[j - 1][k];
	}
	
	ll ans = 0;

	for (int i = 1; i < N; ++i)
		ans += nx[a[4]][i];
	
	cout << ans;

	return 0;
}