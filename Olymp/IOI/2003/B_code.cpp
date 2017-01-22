/// fuck off

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

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 3200, pr = 3001, M = 1010;

ll p_pow[N], ghx1[M][M], ghx2[M][M], ghy1[M][M], ghy2[M][M];

inline void add (ll &x, ll y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

ll sh[N];

inline void calc_hash (int a[], int b[], int c[], int n, ll gh1[M][M], ll gh2[M][M]) {
	int pos[N];
	for (int i = 1; i <= n; ++i) {
		memset (pos, 0, sizeof (pos));
		for (int j = i, k = 1; j <= n; ++j, ++k) {
			gh1[i][j] = gh1[i][j - 1];
			if (!pos[a[j]]) {
				add (gh1[i][j], sh[0] * p_pow[k] % bpr);
			} else {
				add (gh1[i][j], sh[pos[a[j]]] * p_pow[k] % bpr);
			}
			gh2[i][j] = gh2[i][j - 1];
			pos[a[j]] = k + 1000;
			if (!pos[b[j]]) {
				add (gh2[i][j], sh[0] * p_pow[k] % bpr);
			} else {
				add (gh2[i][j], sh[pos[b[j]]] * p_pow[k] % bpr);
			}
			pos[b[j]] = k;
			if (!pos[c[j]]) {
				add (gh2[i][j], sh[0] * p_pow[k] % bpr);
			} else {
				add (gh2[i][j], sh[pos[c[j]]] * p_pow[k] % bpr);
			}
			//cerr << "HASH! " << gh1[i][j] << " " << gh2[i][j] << " ";
			pos[c[j]] = k;
			//pos[a[j]] = pos[b[j]] = pos[c[j]] = k;
		}
	}
}

string ax[N], bx[N], cx[N], ay[N], by[N], cy[N];
int cax[N], cbx[N], ccx[N], cay[N], cby[N], ccy[N];


int main() {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	srand (time (0));

	for (int i = 0; i < N; ++i)
		sh[i] = (rand () * 1ll * rand () + rand ()) % int (1e9);
	
	p_pow[0] = 1;

	for (int i = 1; i < N; ++i)
		p_pow[i] = p_pow[i - 1] * pr % bpr;

	
	int n, m;
	
	cin >> n >> m;

	map <string, int> cc;
	
	for (int i = 1; i <= n; ++i) {
		cin >> ax[i];
		cin >> bx[i];
		cin >> bx[i];
		cin >> cx[i];
		cin >> cx[i];
		if (!cc.count (ax[i]))
			cc[ax[i]] = cc.size () + 1;
		if (!cc.count (bx[i]))
			cc[bx[i]] = cc.size () + 1;
		if (!cc.count (cx[i]))
			cc[cx[i]] = cc.size () + 1;
		cax[i] = cc[ax[i]];
		cbx[i] = cc[bx[i]];
		ccx[i] = cc[cx[i]];
	}
	
	calc_hash (cax, cbx, ccx, n, ghx1, ghx2);

	cc.clear ();

	for (int i = 1; i <= m; ++i) {
		cin >> ay[i];
		cin >> by[i];
		cin >> by[i];
		cin >> cy[i];
		cin >> cy[i];
		if (!cc.count (ay[i]))
			cc[ay[i]] = cc.size () + 1;
		if (!cc.count (by[i]))
			cc[by[i]] = cc.size () + 1;
		if (!cc.count (cy[i]))
			cc[cy[i]] = cc.size () + 1;
		cay[i] = cc[ay[i]];
		cby[i] = cc[by[i]];
		ccy[i] = cc[cy[i]];
	}

	calc_hash (cay, cby, ccy, m, ghy1, ghy2);

	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int l = -1, r = min (m - j + 1, n - i + 1);
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (ghx1[i][i + mid] == ghy1[j][j + mid] && ghx2[i][i + mid] == ghy2[j][j + mid]) {
					//cerr << "HASH! " << ghx1[i][i + mid] << " " << ghx2[i][i + mid] << "\n";
					l = mid;
				} else {
					r = mid;
				}
			}
			//cerr << i << " " << j << " " << l + 1 << "\n";
			ans = max (ans, l + 1);
  		}
	}
	
	cout << ans;
	
	return 0;
}