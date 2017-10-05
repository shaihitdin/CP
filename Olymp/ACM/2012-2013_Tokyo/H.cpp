#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;

int a[N][N];


inline bool make_sub (int& val, int nval) {
	if (val == nval)
		return 1;
	if (val == 0) {
		val = nval;
	} else if (val == 1) {
		if (nval == 2)
			val = nval;
		
	} else if (val == 2) {
	
	} else if (val == 3) {
	
	} else if (val == 4) {
	
	} else if (val == 5) {
	
	}
	return 1;
}
inline bool subs (int x, int y) {
	
	/// changes for x
	for (int i = 1; i <= n; ++i) {
		if (!a[i][x] && !a[i][y])
			continue;
		if ()
	}

	/// changes for y
	for (int i = 1; i <= n; ++i) {
		if (!a[i][x] && !a[i][y])
			continue;
		if (a[y][i] == 1) {
			if ()
			a[x][y] = 1;
		}
		if (a[y][i] == 2) {
			
		}
	}

	return 1;
}

inline bool eq (int x, int y) {

}

inline bool neq (int x, int y) {
	
}

inline bool common (int x, int y) {

}

inline bool nocommon (int x, int y) {

}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	while (1) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				a[i][j] = 0;
		for (int i = 1; i <= n; ++i)
			a[i][i] = 2;
		bool flag = 1;
		int ans = m;
		for (int i = 1; i <= m; ++i) {
			int q_type, x, y;
			cin >> q_type >> x >> y;
			if (!flag)
				continue;
			int res = 0;
			if (q_type == 1) {
				res = subs (x, y);
			} else if (q_type == 2) {
				res = eq (x, y);
			} else if (q_type == 3) {
				res = neq (x, y);			
			} else if (q_type == 4) {
				res = common (x, y);
			} else if (q_type == 5) {
				res = nocommon (x, y);
			}
			if (res == 0) {
				flag = 0;
				ans = i;
			}
		}
	}
	
	return 0;
}