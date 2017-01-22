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

ld ans[N];
int n;
vector <int> g[N];
int sz[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	cout << fixed;
	cout << setprecision (7);

	cin >> n;

	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		g[x].eb (i);
	}
	
	for (int i = n; i >= 1; --i) {
		sz[i] = 1;
		for (auto to : g[i])
			sz[i] += sz[to];
	}
	
	ans[1] = 1;
	
	for (int i = 1; i <= n; ++i) {
		ld val = ans[i];
		for (auto to : g[i])
			val += 0.5 * sz[to];
		for (auto to : g[i])
			ans[to] = val - (0.5 * sz[to]) + 1;
	}
	
	for (int i =1; i <= n; ++i)
		cout << ans[i] << " ";
	
	return 0;
}