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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 0;

int cnt[256];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;

	cin >> t;

	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		string s;
		cin >> s;
		string ts;
		for (int i = 0; i < s.size (); ++i) {
			int flag = 1;
			if (s[i] + ts > ts) {
				ts = s[i] + ts;
			} else {
				ts = ts + s[i];
			}
		}
		cout << ts << "\n";
	}
	
	
	return 0;
}