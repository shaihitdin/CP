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

const int oo = 1e9, bpr = 1e9 + 9, N = -1;

/** Read */

inline int readChar() {
  int c = getchar();
  while ((c <= 32 && c != EOF) || c == ',')
    c = getchar();
  if (c == EOF)
  	exit (0);
  return c;
}

inline __int128 readInt() {
  int s = 1, c = readChar();
  __int128 x = 0;
  if (c == '-')
    s = -1, c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return s == 1 ? x : -x;
}

/** Read */

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	__int128 x;
	while (1) {
		x = readInt ();
		x = x % bpr;
		cout << int (x) << ", ";
	}
	
	return 0;
}

