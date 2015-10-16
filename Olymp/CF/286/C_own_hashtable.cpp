#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const short N = 30001, sz = 345;
short ans, n, d, x;
short u[N], temp, add;
short it1, it2, it3;
inline void f_max (short &x, const short &y) {
	if (y > x)
		x = y;
}

pair <short, short> mp[N][sz];
short nxt[N][sz], last[N];
inline short max1 (const short &x, const short &y) {
	return x > y ? x : y;
}

inline void add_f (const short &where, const short &val, const short &val1) {
	short i = val % sz;
	while (mp[where][i].F != -1 && mp[where][i].F != val) {
		if (++i == sz)
			i = 0;
	}
	if (mp[where][i].F == -1) {
		nxt[where][i] = last[where];
		last[where] = i;
		mp[where][i].F = val;	
	}
	f_max (mp[where][i].S, val1);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	for (short i = 0; i < N; ++i) {
		last[i] = -1;
		for (short j = 0; j < sz; ++j) {
			mp[i][j].F = -1;
			nxt[i][j] = -1;
			mp[i][j].S = -1;
		}
	}
	cin >> n >> d;
	for (short i = 1; i <= n; ++i) {
		cin >> x;
		++u[x];
	}          
	add_f (d, d, 0);
	for (int i = d; i < N; ++i) {
		for (short it = last[i]; it != -1; it = nxt[i][it]) {
			temp = mp[i][it].S + u[i];
			f_max (ans, temp);
			for (int j = max1 (mp[i][it].F - 1, 1); i + j < N && j <= mp[i][it].F + 1; ++j)
				add_f (i + j, j, temp);
		}
	}
	fprintf (stderr, "%f", clock() / (float) CLOCKS_PER_SEC);
	cout << ans;
	return 0;
}