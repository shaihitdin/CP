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
#include <unordered_set>

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

const int oo = 1e9, bpr = 1e9 + 7, N = 610, K = 432857;

//int t[N];
bool u[N][N];
char a[N][N];
set <ull> bek[K];
/*
inline void upd (int y, int nw) {
	int delta = (nw == 1) ? 1 : -1;
	for (; y < N; y |= (y + 1))
		t[y] += delta;
}

inline int get (int r) {
	int res = 0;
	for (; r >= 0; r &= (r + 1), --r)
		res += t[r];
	return res;
}

inline int get (int l, int r) {
	return get (r) - get (l - 1);
}
*/
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector <string> ans;
string rs;
int n;
int cnt;
int done[N];

inline bool inside (int x, int y) {
	return 0 <= x && x < 2 && 1 <= y && y <= n;
}

inline void rec (int x, int y, ull ha = 0) {
	ha = ha * 131 + a[x][y];
	//upd (y, u[x][y] = 1);
	++cnt;
	++done[y];
	u[x][y] = 1;	
	if (/*get (1, n)*/cnt == 2 * n) {
		bek[ha % K].insert (ha);
		--cnt;
		--done[y];
		u[x][y] = 0;
		//upd (y, u[x][y] = 0);
		return;
	}
	if (done[y - 1] == 2 || done[y + 1] == 2) {
		if (inside (x + 1, y) && !u[x + 1][y]/*(get (1, y - 1) == 2 * (y - 1) || get (y + 1, n) == 2 * (n - y))*/)
			rec (x + 1, y, ha);
		if (inside (x - 1, y) && !u[x - 1][y]/*(get (1, y - 1) == 2 * (y - 1) || get (y + 1, n) == 2 * (n - y))*/)
			rec (x - 1, y, ha);
	}
	if (inside (x, y - 1) && !u[x][y - 1])
		rec (x, y - 1, ha);
	if (inside (x, y + 1) && !u[x][y + 1])
		rec (x, y + 1, ha);
	//rs.pop_back ();
	//upd (y, u[x][y] = 0);
	u[x][y] = 0;
	--cnt;
	--done[y];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int p;
	cin >> p;

	while (p--) {
		cin >> n;
		memset (done, 0, sizeof (done));
		done[0] = done[n + 1] = 2;
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> a[i][j];
		//bek.clear ();
		for (int i = 0; i < K; ++i)
			bek[i].clear ();
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= n; ++j)
				rec (i, j, 0);
		int ans = 0;
		for (int i = 0; i < K; ++i)
			ans += bek[i].size ();
		//ans += bek.size ();
		cout << ans << "\n";
	}
	
	return 0;
}