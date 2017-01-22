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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 70;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

ll cnt[N];
int a[N][N];

int main() {
	//#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	//#endif

	
	int test_num;

	cin >> test_num;

	for (int test = 1; test <= test_num; ++test) {
		ll b, m;
		cin >> b >> m;
		cout << "Case #"<<test<<": ";
		//memset (a, 0, sizeof (a));
		for (int i = 2; i < b; ++i) {
			cnt[i] = (1ll << (b - 1 - i));
			for (int j = i + 1; j <= b; ++j)
				a[i][j] = 1;
		}
		cnt[b] = 1;
		for (int i = 2; i <= b; ++i) {
			if (m >= cnt[i]) {
				m -= cnt[i];
				a[1][i] = 1;
			}		
		}
		if (m) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		for (int i = 1; i <= b; ++i) {
			for (int j = 1; j <= b; ++j) {
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
	
	return 0;
}