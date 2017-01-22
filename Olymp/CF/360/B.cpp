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

const int oo = 1e9, bpr = 1e9 + 7, N = 1e6 + 100;

int n, k, a[N], cnt[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++a[x];
	}
	
	for (int i = 1; i < N; ++i) {
		int cc = 0;
		for (int j = i; j < N; j += i) {
			cc += a[j];
		}
		cnt[i] = cc;
	}

	bool flag = 0;
	
	if (cnt[k]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
	return 0;
}