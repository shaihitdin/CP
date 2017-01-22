#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int sz = 1 << 19, bpr = 1e9 + 7, N = 4e5 + 100;

int tin[N], tout[N], lvl[N], timer;
vector <int> g[N];

inline void upd (int t[], int pos, int delta, int type) {
	t[pos += sz] = delta;
	while (pos >>= 1) {
		t[pos] = (type ? (min (t[pos + pos], t[pos + pos + 1])) : (max (t[pos + pos], t[pos + pos + 1])));
	}
}

inline int get (int t[], int l, int r, int type) {
	int res = type ? oo : 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	add (res, t[l++]);
		if (!(r & 1)) add (res, t[r--]);
		if (l > r)	break;
	}
	return res;
}

int t1[sz + sz + 100], t2[sz + sz + 100];

bool flag[N];
int f_enc[N], s_enc[N];
int cnt, st[3][N], si[3];
vector <int> ans[3];

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n + n; ++i) {
		cin >> a[i];
	}	
	
	for (int i = 1; i <= n + n; ++i) {
		if (!flag[a[i]]) {
			f_enc[a[i]] = i;
		} else {
			s_enc[a[i]] = i;
			a[i] = -a[i];
		}
		flag[a[i]] = 1;
	}
	
	for (int i = 1; i <= n + n; ++i) {
		if (a[i] < 0) {
			bool flag = 0;
			for (int j = 1; j <= 2; ++j) {
				if (st[j][si[j]] == -a[i]) {
					ans[j].emplace_back (a[i]);
				}
			}
		} else {
		
		}
	}
	
	return 0;
}