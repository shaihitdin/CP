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

vector <pair <int, int> > c;
int a[256], k;

inline void print (int x) {
	cout << char (x);
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	for (int i = 'a'; i <= 'z'; ++i) {
		int x;
		cin >> x;
		if (x) {
			c.eb (mp (x, i));
			a[i] = ++k;
		}
	}
	
	sort (c.begin (), c.end ());
	
	if (a[c[0].se] == 1) {
		print (c[0].se);
		--c[0].fe;
		for (int i = 1; i < c.size (); ++i)
			swap (c[i].fe, c[i].se);
		sort (c.begin () + 1, c.end ());
		for (int i = 1; i < c.size ();) {
			if (c[0].fe) {
				print (c[0].se);
				--c[0].fe;
			}
			print (c[i].fe);
			if (!(--c[i].se))
				++i;
		}
		while (c[0].fe--)
			print (c[0].se);
		return 0;
	}
	
	cout << (char)c[0].se;
	--c[0].fe;
		
	for (int i = 0; i < c.size (); ++i)
		swap (c[i].fe, c[i].se);
	
	sort (c.begin (), c.end ());
	
	for (int i = 0; i < c.size (); ++i)
		for (int j = 0; j < c[i].se; ++j)
			print (c[i].fe);
	
	return 0;
}