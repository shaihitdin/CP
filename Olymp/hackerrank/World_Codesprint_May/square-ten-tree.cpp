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

const int oo = 1e9, bpr = 95542721, N = 1e6 + 100;

string l, r;
vector <int> a, b;
vector <pair <int, pair <int, int> > > ans;
vector <pair <int, vector <int> > > ans2;

int lvl[N], lg[N];

inline void apply (int ps, int add) {
	if (add == 0)
		return;
	ans.eb (mp (lvl[ps], mp (add, ps - lg[ps])));
	a[ps] += add;
	if (a[ps] >= 10)
		++a[ps + 1];
	a[ps] %= 10;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> l >> r;

	reverse (l.begin (), l.end ());
	reverse (r.begin (), r.end ());
	
	while (l.size () < r.size ())
		l += '0';
	
	for (int i = 0; i < l.size (); ++i)
		a.eb (l[i] - '0'), b.eb (r[i] - '0');
	
	for (int i = 0, carry = 1; i < a.size (); ++i) {
		a[i] -= carry;
		if ((carry = (a[i] < 0)))
			a[i] += 10;
	}
	
	lg[0] = lvl[0] = 0;

	lg[1] = lvl[1] = 1;
	for (int i = 2; i < N; i *= 2)
		lg[i] = i, lvl[i] = lvl[i / 2] + 1;
	for (int i = 2; i < N; ++i) {
		if (!lg[i]) {
			lg[i] = lg[i - 1];
			lvl[i] = lvl[i - 1];
		}
	}

	for (int i = l.size () - 1, zeroes_till = 0; i >= 0; --i) {
		if (a[i] == b[i])
			continue;
		while (1) {
			while (zeroes_till < i && a[zeroes_till] == 0)	++zeroes_till;
			if (zeroes_till >= i)
				break;
			if (a[zeroes_till] >= 10)
				++a[zeroes_till + 1];
			a[zeroes_till] %= 10;
			if (a[zeroes_till] == 0)
				continue;
			apply (zeroes_till, 10 - a[zeroes_till]);
		}
		zeroes_till = i;
		apply (i, b[i] - a[i]);
	}
	
	for (int i = 0; i < ans.size (); ++i) {
		int j;
		vector <int> bb;
		for (j = i; j < ans.size () && ans[i].fe == ans[j].fe; ++j) {
			bb.resize (max ((int)bb.size (), ans[j].se.se + 1));
			bb[ans[j].se.se] += ans[j].se.fe;
		}
		--j;
		for (int k = 0; k < bb.size (); ++k) {
			if (bb[k] >= 10) {
				bb.resize (max (k + 2, (int)bb.size ()));
				bb[k + 1] += bb[k] / 10;
				bb[k] %= 10;
			}
		}
		reverse (bb.begin (), bb.end ());
		ans2.eb (mp (ans[i].fe, bb));
		i = j;
	}
	
	cout << ans2.size () << "\n";

	for (auto it : ans2) {
		cout << it.fe << " ";
		for (auto it2 : it.se)
			cout << it2;
		cout << "\n";
	}	
	return 0;
}