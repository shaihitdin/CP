/// Forever

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

int a[N][N];
bool f1[N], f2[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	
	for (int run = 1; run;) {
		run = 0;
		for (int i = 1; i <= n; ++i) {
			int sum = 0;
			for (int j = 1; j <= m; ++j)
				sum += a[i][j];
			if (sum < 0) {
				run = 1;
				f1[i] ^= 1;
				for (int j = 1; j <= m; ++j)
					a[i][j] = -a[i][j];
			}		
		}			
		
		for (int j = 1; j <= m; ++j) {
			int sum = 0;
			for (int i = 1; i <= n; ++i)
				sum += a[i][j];
			if (sum < 0) {
				run = 1;
				f2[j] ^= 1;
				for (int i = 1; i <= n; ++i)
					a[i][j] = -a[i][j];
			}
		}
	}
	
	vector <int> ans1, ans2;
	for (int i = 1; i <= n; ++i)
		if (f1[i])
			ans1.emplace_back (i);
	for (int i = 1; i <= m; ++i)
		if (f2[i])
			ans2.emplace_back (i);
	cout << ans1.size () << " ";
	for (auto it : ans1)
		cout << it << " ";
	cout << "\n";
	cout << ans2.size () << " ";
	for (auto it : ans2)
		cout << it << " ";
	cout << "\n";
	return 0;
}