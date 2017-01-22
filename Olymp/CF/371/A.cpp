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
#include <iomanip>

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

map <ll, ll> Map;

inline bool bit (ll mask, ll pos) {
	return (mask >> pos) & 1;
}

inline ll parse (ll x) {
	ll res = 0;
	for (int i = 0; i < 18; ++i) {
		res <<= 1;
		res |= (x % 2);
		x /= 10;
	}
	ll res2 = 0;
	for (int i = 0; i < 18; ++i) {
		res2 <<= 1;
		res2 |= (res % 2);
		res /= 2;
	}
	return res2;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;
	cin >> t;

	while (t--) {
		char q_type;
		cin >> q_type;
		if (q_type == '+') {
			ll x;
			cin >> x;
			x = parse (x);
			++Map[x];
		} else if (q_type == '-') {
			ll x;
			cin >> x;
			x = parse (x);
			--Map[x];
		} else {
			string s;
			cin >> s;
			ll x = 0;
			reverse (s.begin (), s.end ());
			for (int i = 0; i < s.size (); ++i)
				if (s[i] == '1')
					x |= (1 << i);
			cout << Map[x] << "\n";
		}
	}
	
	return 0;
}