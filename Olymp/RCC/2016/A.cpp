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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 0;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

pair <int, short> dp[23][23][23][23];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int test;
	
	cin >> test;

	while (test--) {
		cin >> a >> b >> c >> d;
		if (abs (b - c) > 1) {
			cout << "IMPOSSIBLE";
		}
		if (b < c) {
		
		} else if (b == c) {
		
		} else {
		
		}
	}

	return 0;
}