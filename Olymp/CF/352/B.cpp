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


int cnt[256];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	string s;
	
	int T;

	cin >> T;

	cin >> s;
	
	if (s.size () > 26) {
		cout << -1;
		return 0;
	}
	
	for (auto x : s)
		++cnt[x];
	
	int ans = 0;

	for (int i = 'a'; i <= 'z'; ++i) {
		if (cnt[i])
			ans += cnt[i] - 1;
	}
	
	cout << ans;
	
	return 0;
}