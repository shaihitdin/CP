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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1050, sz = 1 << 10;

struct node {
	node *l, *r;
	node () {
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		l = Tl;
		r = Tr;
	}
};


inline int get (node *t, int Tl, int Tr, int x) {
	if (Tl > x || Tr < x)
		return 0;
	if (!t)
		return 0;
	if (Tl == x && Tr == x)
		return 1;
	int mid = (Tl + Tr) >> 1;
	return get (t -> l, Tl, mid, x) | get (t -> r, mid + 1, Tr, x);
}

inline int get (node *t, int Tl, int Tr, int x, int y) {
	if (Tl > x || Tr < x)
		return 0;
	if (!t)
		return 0;
	if (Tl == x && Tr == x)
		return get (t, 1, sz, y);
	int mid = (Tl + Tr) >> 1;
	return get (t -> l, Tl, mid, x, y) | get (t -> r, mid + 1, Tr, x, y);
}

inline node* upd (node *t, int Tl, int Tr, int x) {
	if (Tl > x || Tr < x)
		return t;
	if (Tl == x && Tr == x)
		return new node ();
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	int mid = (Tl + Tr) >> 1;
	return new node (upd (t -> l, Tl, mid, x), upd (t -> r, mid + 1, Tr, x));
}

inline node* upd (node *t, int Tl, int Tr, int x, int y) {
	if (Tl > x || Tr < x)
		return t;
	if (Tl == x && Tr == x)
		return upd (t, 1, sz, y);
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	int mid = (Tl + Tr) >> 1;
	return new node (upd (t -> l, Tl, mid, x, y), upd (t -> r, mid + 1, Tr, x, y));
}

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char a[N][N];

inline bool inside (int x, int y) {
	return a[x][y] == '.';
}

struct turn {
	int x, y, k;
};

int u[N][N][4];
turn p[N][N][4];
int dp[N][N][4];
bool cell[N][N];
node *root[N][N][4];

inline void bp (int &x, int &y, int &k, turn pp) {
	x = pp.x;
	y = pp.y;
	k = pp.k;
}

inline void cycle_found (turn x, turn y) {
	auto x2 = x;
	int res = 0;
	//cerr << x.x << " " << x.y << " " << x.k << " " << y.x << " " << y.y << " " << y.k << " ";
	node *tmp = new node ();
	for (; !(x.x == p[y.x][y.y][y.k].x && x.y == p[y.x][y.y][y.k].y && x.k == p[y.x][y.y][y.k].k); bp (x.x, x.y, x.k, p[x.x][x.y][x.k])) {
		if (!cell[x.x][x.y]) {
			++res;
			tmp = upd (tmp, 1, sz, x.x, x.y);
		}
		cell[x.x][x.y] = 1;
	}
	//cerr << res << "\n";
	x = x2;
	for (; !(x.x == p[y.x][y.y][y.k].x && x.y == p[y.x][y.y][y.k].y && x.k == p[y.x][y.y][y.k].k); bp (x.x, x.y, x.k, p[x.x][x.y][x.k])) {
		dp[x.x][x.y][x.k] = res;
		u[x.x][x.y][x.k] = 1;
		cell[x.x][x.y] = 0;
		root[x.x][x.y][x.k] = tmp;
	}
}

inline int calc (int x, int y, int k, turn pp) {
	if (dp[x][y][k] != -1)
		return dp[x][y][k];
	if (u[x][y][k] == 2) {
		cycle_found (pp, {x, y, k});
		return dp[x][y][k];
	}
	if (u[x][y][k] == 1)
		return dp[x][y][k];
	p[x][y][k] = pp;
	u[x][y][k] = 2;
	if (!inside (x + dx[k], y + dy[k])) {
		dp[x][y][k] = calc (x, y, (k + 1) % 4, {x, y, k});
		root[x][y][k] = root[x][y][(k + 1) % 4];
	} else {
		calc (x + dx[k], y + dy[k], k, {x, y, k});
		if (dp[x][y][k] == -1) {
			int flag = !get (root[x + dx[k]][y + dy[k]][k], 1, sz, x, y);
			dp[x][y][k] = calc (x + dx[k], y + dy[k], k, {x, y, k}) + flag;
			if (flag)
				root[x][y][k] = upd (root[x + dx[k]][y + dy[k]][k], 1, sz, x, y);
			else
				root[x][y][k] = root[x + dx[k]][y + dy[k]][k];
		}
	}
	u[x][y][k] = 1;
	return dp[x][y][k];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	
	memset (dp, -1, sizeof (dp));
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] != '.')
				continue;
			for (int k = 0; k < 4; ++k) {
				ans = max (ans, calc (i, j, k, {-1, -1, -1}));
				//cerr << "(" << i << ", " << j << ") -> direction (" << dx[k] << ", " << dy[k] << ") " << calc (i, j, k, {-1, -1, -1}) << "\n";
			}
		}
	}
	
	cout << ans;
		
	return 0;
}