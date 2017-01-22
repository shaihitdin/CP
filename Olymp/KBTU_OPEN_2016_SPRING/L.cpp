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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 110;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int a[N];
int n;

int main() {
	freopen ("oddandeven.in", "r", stdin);
	freopen ("oddandeven.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	sort (a + 1, a + n + 1);

	int ans = 0;

	for (;;) {
		int sum = 0;
		for (int i = 1; i <= n; i += 2)
			sum += a[i];
		int sum2 = 0;
		for (int i = 2; i <= n; i += 2)
			sum2 += a[i];
		if (sum % sum2 == 0)
			++ans;
		if (!next_permutation (a + 1, a + n + 1))
			break;
	}
	
	cout << ans;
	
	return 0;
}