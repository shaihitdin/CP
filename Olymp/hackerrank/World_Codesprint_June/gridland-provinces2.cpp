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

int pp[2];
char a[N][N];
vector <ull> bek[K];
int n;
pair <int, ull> pre[2][N];
ull pows[2][N + N];

inline void gh (ull &hh, int a) {
	hh = 131 * hh + a;
	hh %= bpr;
}

inline void gh2 (int &hh, int a) {
	hh = 131 * hh + a;
	hh %= K;
}

inline void calc (int x, int y) {
	pair <int, ull> ha = mp (0, 0);
	for (int i = y; i >= 1; --i)
		gh2 (ha.fe, a[x][i]), gh (ha.se, a[x][i]);
	x ^= 1;
	for (int i = 1; i <= y; ++i)
		gh2 (ha.fe, a[x][i]), gh (ha.se, a[x][i]);
	for (int i = y; i <= n; ++i) {
		if (i != y)
			gh2 (ha.fe, a[x][i]), gh (ha.se, a[x][i]), gh2 (ha.fe, a[x ^= 1][i]), gh (ha.se, a[x][i]);
		auto ha2 = mp ((ha.fe * pows[0][(n - i) * 2] + pre[x][i + 1].fe) % K, (ha.se * 1ll * pows[1][(n - i) * 2] + pre[x][i + 1].se) % bpr);
		bek[ha2.fe].eb (ha2.se);
	}
}

inline void calcpre () {
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j < N; ++j) {
			pre[i][j] = mp (0, 0);
			for (int k = j; k <= n; ++k)
				gh2 (pre[i][j].fe, a[i][k]), gh (pre[i][j].se, a[i][k]);
			for (int k = n; k >= j; --k)
				gh2 (pre[i][j].fe, a[i ^ 1][k]), gh (pre[i][j].se, a[i ^ 1][k]);
		}
	}
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int p;
	cin >> p;


	for (int i = pows[1][0] = 1; i < N + N; ++i)
		pows[1][i] = pows[1][i - 1] * 131ll % bpr;
	for (int i = pows[0][0] = 1; i < N + N; ++i)
		pows[0][i] = pows[0][i - 1] * 131ll % K;
	
	while (p--) {
		cin >> n;
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> a[i][j];
		
		calcpre ();
		
		for (int i = 0; i < K; ++i)
			bek[i].clear ();
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= n; ++j)
				calc (i, j);
		
		reverse (a[0] + 1, a[0] + n + 1);
		reverse (a[1] + 1, a[1] + n + 1);

		calcpre ();

		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= n; ++j)
				calc (i, j);

		int ans = 0;
		for (int i = 0; i < K; ++i) {
			sort (bek[i].begin (), bek[i].end ());
			bek[i].resize (unique (bek[i].begin (), bek[i].end ()) - bek[i].begin ());
			ans += bek[i].size ();
		}
		cout << ans << "\n";
	}
	
	return 0;
}