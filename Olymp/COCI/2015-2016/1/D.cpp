#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map <int, int> cntx, cnty;
map <int, int> resx, resy;
map <pair <int, int>, int> power;

ll ans;

int n;

inline void add (const int &x, const int &y, const int &z) {

	ans += cntx[resy[y]];
	ans += cnty[resx[x]];
	
	--cntx[resx[x]];
	--cnty[resy[y]];
	
	resx[x] ^= z;
	resy[y] ^= z;
	
	++cntx[resx[x]];
	++cnty[resy[y]];

	ans -= cntx[resy[y]];
	ans -= cnty[resx[x]];
	
	power[make_pair (x, y)] = z;
}

inline void del (const int &x, const int &y) {

	int z = power[make_pair (x, y)];
	
	add (x, y, z);

	power.erase (make_pair (x, y));
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int k, p;
	
	cin >> n >> k >> p;

	cntx[0] = n;
	cnty[0] = n;
	
	for (int i = 1; i <= k; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		add (x, y, z);
	}	
	
	while (p--) {
		int sx, sy, fx, fy;
		cin >> sx >> sy >> fx >> fy;
		int f = power[make_pair (sx, sy)];
		
		del (sx, sy);
		add (fx, fy, f);
		
		cout << ans << "\n";
	}

	return 0;

}