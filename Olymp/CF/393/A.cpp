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
#define lw lower_bound

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

int a[N], b[N], c[N], n;
int s[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i)
		c[i] = i;
	for (int i = 1; i <= n; ++i) {
		swap (c[i], c[a[i]]);
		s[c[a[i]]] = max (s[c[a[i]]], b[i]);
	}		
	
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += s[i];
	cout << n - ans;
	return 0;
}