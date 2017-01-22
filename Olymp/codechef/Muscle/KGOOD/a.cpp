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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

int cnt[256];
vector <int> cc;

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;
	cin >> t;

	while (t--) {
		string s;
		int k;
		cin >> s >> k;
		memset (cnt, 0, sizeof (cnt));
		for (auto it : s)
			++cnt[it];
		cc.clear ();
		for (int i = 'a'; i <= 'z'; ++i)
			if (cnt[i])
				cc.eb (cnt[i]);
		int ans = oo;
		sort (cc.begin (), cc.end ());
		for (int i = 0; i < cc.size (); ++i) {
			int res = 0;
			for (int j = 0; j < i; ++j)
				res += cc[j];
	    	for (int j = i; j < cc.size (); ++j)
	    		res += max (0, cc[j] - (cc[i] + k));
			ans = min (ans, res);
		}
		cout << ans << "\n";
	}
	
	return 0;
}