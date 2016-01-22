#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int bpr = 1e9 + 7, oo = 1e9, N = 5e5 + 100;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

char s[N];

int dx[256];
int dy[256];
int nowx, nowy, mnx, mny, mxx, mxy;
int ans;
int n, k, m;
int mv;

struct buu {
	int nn, nm, nz, res;
};

inline void process () {
	for (int i = 1; i <= k; ++i) {
		add (mv, 1);
		nowx += dx[s[i]];
		nowy += dy[s[i]];
		if (n == 0 || m == 0) {
			cout << ans;
			exit (0);
		}
		if (mnx > nowx) {
			mnx = min (mnx, nowx);
			--n;
			add (ans, (mv * 1ll * m) % bpr);
		}
		if (mny > nowy) {
			mny = min (mny, nowy);
			--m;
			add (ans, (mv * 1ll * n) % bpr);
		}
		if (nowx > mxx) {
			mxx = max (mxx, nowx);
			--n;
			add (ans, (mv * 1ll * m) % bpr);
		}
		if (nowy > mxy) {
			mxy = max (mxy, nowy);
			--m;
			add (ans, (mv * 1ll * n) % bpr);
		}
	}
}

inline void cc () {
	int oldmnx = mnx, oldmny = mny, oldmxx = mxx, oldmxy = mxy;
	int oldnowx = nowx, oldnowy = nowy;
	for (int i = 1; i <= k; ++i) {
		
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> k >> n >> m;

	for (int i = 1; i <= k; ++i)
		cin >> s[i];
	
	dx['U'] = -1;
	dy['U'] = 0;
	dx['D'] = 1;
	dy['D'] = 0;
	dx['L'] = 0;
	dy['L'] = -1;
	dx['R'] = 0;
	dy['R'] = 1;
	
	process ();
	
	if (nowx == 0 && nowy == 0 && mxx - mnx + 1 <= n && mxy - mny + 1 <= m) {
		cout << -1;
		return 0;
	}
	
	while (nowx - mnx + 1 <= n && nowx + mxx <=) {
	
	}
	
	process ();
	
	return 0;

}