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

const int oo = 1e9, bpr = 1e9 + 7, N = 510;

bool dp[N][N][N];
int n, sum, c[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> sum;

	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	
	dp[1][0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (!dp[i][j][k])
					continue;
				if (j + c[i] <= sum) {
					if (k + c[i] <= sum)
						dp[i + 1][j + c[i]][k + c[i]] = 1;
					dp[i + 1][j + c[i]][k] = 1;
				}
				dp[i + 1][j][k] = 1;
			}
		}
	}
	
	vector <int> ans;

	for (int i = 0; i <= sum; ++i) {
		if (dp[n + 1][sum][i])
			ans.eb (i);
	}
	
	cout << ans.size () << "\n";

	for (auto it : ans)
		cout << it << " ";
	
	return 0;
}