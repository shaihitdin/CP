#include <bits/stdc++.h>

using namespace std;

const int N = 301;

int a[N][N];
int n, m;
int sz;
int vl[5020], vr[5020];
int d[N][N], buf1[N], buf2[N];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

// l = 0, r = 1

inline int Find (const int &v, const int &element, const int &now, const int &lvl) {
	if (lvl == -1)
		return now;
	if (bit (element, lvl)) {
		if (vl[v])
			return Find (vl[v], element, now | (1 << lvl), lvl - 1);
		else if (vr[v])
			return Find (vr[v], element, now, lvl - 1);
		else
			assert (0);	
	} else {
		if (vr[v])
			return Find (vr[v], element, now | (1 << lvl), lvl - 1);
		else if (vl[v])
			return Find (vl[v], element, now, lvl - 1);
		else
			assert (0);
	}

}

inline void add (const int &v, const int &element, const int &lvl) {
	if (lvl == -1)
		return;
	if (bit (element, lvl)) {
		if (!vr[v])
			vr[v] = ++sz;
		add (vr[v], element, lvl - 1);
	} else {
		if (!vl[v])
			vl[v] = ++sz;
		add (vl[v], element, lvl - 1);		
	}
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];


	
	return 0;
}