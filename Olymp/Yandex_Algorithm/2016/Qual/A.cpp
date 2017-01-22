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

const int oo = 1e9, bpr = 95542721, N = 2000;

string s[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		bool flag = 1;
		for (int j = 1; j <= n; ++j) {
			int cnt = 0;
			for (int k = 0; k < s[j].size (); ++k)
				cnt += (s[j][k] != s[i][k]);
			flag &= (cnt <= 1);
		}
		if (flag) {
			cout << s[i];
			return 0;
		}
	}
	
	return 0;
}