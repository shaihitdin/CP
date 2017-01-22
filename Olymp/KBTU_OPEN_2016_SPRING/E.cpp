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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 56;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int cnt[N];

inline int min_divisor (int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return i;
	return x;
}

int ans;
vector <vector <pair <int, int> > > ansc;
vector <pair <int, int> > cc;

inline void rec (int n) {
 	for (int i = 1; i < N; ++i) {
		if (!cnt[i])
			continue;
		if (n == 1) {
			if (ans > i) {
				ansc.clear ();
				ans = i;
			}
			ansc.eb (cc);
			return;
		}
		--cnt[i];
		for (int j = i; j < N; ++j) {
			if (!cnt[j])
				continue;
			--cnt[j];
			++cnt[min_divisor (i + j)];
			cc.eb (mp (i, j));
			rec (n - 1);
			cc.pop_back ();
			--cnt[min_divisor (i + j)];
			++cnt[j];
		}
		++cnt[i];
	}
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	for (int n = 1; n < 10; ++n) {
		fclose (stdout);
		cerr << n << "\n";
		char name[10] = "err";
		name[3] = '0' + n;
		freopen (name, "w", stdout);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 1; i <= n; ++i)
			cnt[i] = 1;
		ans = oo;
		ansc.clear ();
		rec (n);
		cout << "NEW N ";
		cout << n << " " << ans << "\n";
		for (auto xx : ansc) {
			for (auto x : xx) {
				cout << x.fe << " " << x.se << "\n";
			}
			cout << "\n\n";
		}
		cout << "KOKOKO\n\n";
	}
	
	return 0;
}