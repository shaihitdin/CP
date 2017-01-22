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
#define int ll

const int oo = 1e9, bpr = 95542721, N = 5050;

int a[N], b[N], c[N];

inline int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

map <pair <int, int>, int> cnt;

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	sort (a + 1, a + n + 1);

	for (int i = 1; i <= n; ++i)
		b[i] = a[i];
	int m = unique (b + 1, b + n + 1) - b - 1;
	
	for (int i = 1; i <= n; ++i)
		++c[lower_bound (b + 1, b + m + 1, a[i]) - b];
	int ans = 0;
	int sum = 0;

	for (int i = 1; i <= m; ++i) {
		sum += c[i];
		for (int j = 1; j < i; ++j)
			ans += c[i] * (c[i] - 1) / 2 * c[j] * (c[j] - 1) / 2;
		ans += c[i] * (c[i] - 1) * (c[i] - 2) * (c[i] - 3) / 24;
		int t_ans = 0;
		for (int j = 1; j < i; ++j) {
			int g = gcd (b[i], b[j]);
			int cg = c[i] * c[j];
			t_ans += cg * cnt[mp (b[i] / g, b[j] / g)];
			cnt[mp (b[i] / g, b[j] / g)] += cg;
		}
		ans += t_ans / 2;
	}

	cout << ans;
	
	return 0;
}