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

const int oo = 1e9, bpr = 1e9 + 7, N = 10;

int cnt[N], a[N][N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];
	
	for (int i = 0; i < 3; ++i) {
		cnt[0] += (a[0][i] < a[1][i]);
		cnt[1] += (a[0][i] == a[1][i]);
		cnt[2] += (a[0][i] > a[1][i]);	
	}
	
	cout << cnt[2] << " " << cnt[0];
	
	return 0;
}