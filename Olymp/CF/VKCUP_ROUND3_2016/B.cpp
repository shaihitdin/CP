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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2050;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int n, k, a, b, c, d, p[N];
bool u[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> k;

	cin >> a >> b >> c >> d;
	
	if (k <= n) {
		cout << -1;
		return 0;
	}
	if (n == 4) {
		cout << -1;
		return 0;
	}
	
	
	p[1] = a;
	p[n] = b;
	p[2] = c;
	p[n - 1] = d;
	
	u[a] = u[b] = u[c] = u[d] = 1;
	
	for (int i = 3; i < n - 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!u[j]) {
				u[j] = 1;
				p[i] = j;
				break;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
		cout << p[i] << " ";
	
	cout << "\n";

	for (int i = 2; i >= 1; --i)
		cout << p[i] << " ";
	
	for (int i = 3; i < n - 1; ++i)
		cout << p[i] << " ";
	
	for (int i = n; i >= n - 1; --i)
		cout << p[i] << " ";
	
	return 0;
}