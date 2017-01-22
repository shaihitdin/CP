/// Oh, my dear
#include <bits/stdc++.h>

using namespace std;

set <pair <int, int> > Set;

const int N = 410;

int n, m, k, a[N], b[N], c[N][N];
bool flag1, flag2;

inline bool can_add (int i, int j) {
	return c[i][j] != k;
}

inline bool can_del (int i, int j) {
	return c[i][j] != 0;
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	
	for (int i = 1; i <= n; ++i) {
		Set.clear ();
		for (int j = 1; j <= m; ++j)
			Set.insert (make_pair (b[j], j));
		for (int j = 1; j <= a[i]; ++j) {
			if (!Set.size ()) {
				cout << "Good Morning";
				return 0;
			}		
			int v = Set.rbegin () -> second;
			Set.erase (*Set.rbegin ());
			if (b[v] == 0) {
				cout << "Good Morning";
				return 0;
			}
			++c[i][v];
			--b[v];
			if (c[i][v] != k)
				Set.insert (make_pair (b[v], v));
		}
	}	
	for (int i = 1; i <= m; ++i) {
		if (b[i] != 0) {
			cout << "Good Morning";
			return 0;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			flag1 = flag2 = 0;
			for (int k1 = 1; k1 <= m; ++k1) {
				if (can_del (i, k1) && can_add (j, k1) && can_del (j, k1) && can_add (i, k1) && (flag1 || flag2)) {
					cout << "Multiple Maps";
					return 0;
				} else if (can_del (i, k1) && can_add (j, k1) && can_del (j, k1) && can_add (i, k1)) {
					flag1 = 1;
					flag2 = 1;
				} else if (can_del (i, k1) && can_add (j, k1) && flag2) {
					cout << "Multiple Maps";
					return 0;					
				} else if (can_del (i, k1) && can_add (j, k1)) {
					flag1 = 1;
				} else if (can_del (j, k1) && can_add (i, k1) && flag1) {
					cout << "Multiple Maps";
					return 0;					
				} else if (can_del (j, k1) && can_add (i, k1)) {
					flag2 = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}