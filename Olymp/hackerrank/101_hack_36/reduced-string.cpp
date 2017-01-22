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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1100;

#define mp make_pair

string s;
char st[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> s;

	int sz = 0;

	for (int i = 0; i < s.size (); ++i) {
		if (sz && st[sz] == s[i])
			--sz;
		else
			st[++sz] = s[i];
	}
	
	if (!sz) {
		cout << "Empty String";
	} else {
		for (int i = 1; i <= sz; ++i)
			cout << st[i];
	}

	return 0;
}