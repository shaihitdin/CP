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

const int oo = 1e9, bpr = 1e9 + 7, N = 5e4 + 100;

inline int parse (char x) {
	if (x <= '9')
		return x - '0';
	return x + 10 - 'A';
}

inline char reparse (int x) {
	if (x <= 9)	
		return '0' + x;
	return 'A' + x - 10;
}
string a, b, c, anw, bnw;
int poss[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int q;
	cin >> q;

	while (q--) {
		int k;
		cin >> k;
		cin >> a >> b >> c;
		a.insert (a.begin (), int (5e4) - int (a.size ()), '0');
		b.insert (b.begin (), int (5e4) - int (b.size ()), '0');
		c.insert (c.begin (), int (5e4) - int (c.size ()), '0');
		anw = a, bnw = b;
		for (int i = 0; i < 5e4; ++i) {
			int s1 = parse (a[i]), s2 = parse (b[i]), s3 = parse (c[i]);
			poss[i] = oo;
			for (int aa = 0; aa < 16; ++aa)
				for (int bb = 0; bb < 16; ++bb)
					if ((aa | bb) == s3 && __builtin_popcount (aa ^ s1) + __builtin_popcount (bb ^ s2) < poss[i])
						poss[i] = __builtin_popcount (aa ^ s1) + __builtin_popcount (bb ^ s2);
			if (poss[i] > k) {
				cout << -1 << "\n";
				goto end;
			}
			k -= poss[i];
		}
		for (int i = 0; i < 5e4; ++i) {
			int s1 = parse (a[i]), s2 = parse (b[i]), s3 = parse (c[i]);
			k += poss[i];
			for (int aa = 0; aa < 16; ++aa) {
				for (int bb = 0; bb < 16; ++bb) {
					if ((aa | bb) == s3 && __builtin_popcount (aa ^ s1) + __builtin_popcount (bb ^ s2) <= k) {
						anw[i] = reparse (aa), bnw[i] = reparse (bb);
						k -= (__builtin_popcount (aa ^ s1) + __builtin_popcount (bb ^ s2));
						goto tt;
					}
				}
			}
			tt:;
		}
		{
			int ke = 0;
			for (; anw[ke] == '0' && ke + 1 < 5e4; ++ke);
			cout << anw.substr (ke) << "\n";
			ke = 0;
			for (; bnw[ke] == '0' && ke + 1 < 5e4; ++ke);
			cout << bnw.substr (ke) << "\n";
			
		}
		end:;
	}

	return 0;
}