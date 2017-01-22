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

vector <int> ans;

inline void add (int x) {
	vector <int> cc;
	while (x) {
		cc.eb (x % 10);
		x /= 10;
	}
	reverse (cc.begin (), cc.end ());
	for (int x : cc)
		ans.eb (x);
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	for (int i = 1; i <= 1000; ++i) {
		add (i);
	}
	
	int n;

	cin >> n;

	cout << ans[n - 1];
	
	return 0;
}