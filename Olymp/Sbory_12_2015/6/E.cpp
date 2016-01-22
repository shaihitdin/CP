#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1020;
const ll oo = 1e13;

struct point {
	ll x, y, val, id;
};

inline ll sqr (ll x) {
	return x * 1ll * x;
}

inline ll dist (ll sx, ll sy, ll fx, ll fy) {
	return sqr (sx - fx) + sqr (sy - fy);
}

inline bool operator < (const point &a, const point &b) {
	return a.id < b.id;
}

vector <pair <ll, point> > la, lb;

ll pref[N][N];
int u[N];
ll d[2][N][N][2];
bool ud[2][N][N][2];
ll ok[2][N][N];
int n;
point a[N];

inline ll calc (int player, int prefa, int prefb, int taken) {
	if (prefa >= n || prefb >= n)
		return 0;
	if (ud[player][prefa][prefb][taken])
		return d[player][prefa][prefb][taken];
	ud[player][prefa][prefb][taken] = 1;
	ll res = -oo;
	if (player == 0) {
		if (prefa > 0 && la[prefa - 1].first == la[prefa].first) {
			res = max (res, ok[player][prefa][prefb] * la[prefa].second.val + calc (player, prefa + 1, prefb, taken | ok[player][prefa][prefb]));
		} else {
			res = max (res, ok[player][prefa][prefb] * la[prefa].second.val + calc (player, prefa + 1, prefb, taken | ok[player][prefa][prefb]));
			if (taken == 1)
				res = max (res, -calc (player ^ 1, prefa, prefb, 0));
		}
	} else {
		if (prefb > 0 && lb[prefb - 1].first == lb[prefb].first) {
			res = max (res, ok[player][prefa][prefb] * lb[prefb].second.val + calc (player, prefa, prefb + 1, taken | ok[player][prefa][prefb]));
		} else {
			res = max (res, ok[player][prefa][prefb] * lb[prefb].second.val + calc (player, prefa, prefb + 1, taken | ok[player][prefa][prefb]));
			if (taken == 1)
				res = max (res, -calc (player ^ 1, prefa, prefb, 0));
		}
	}
	return d[player][prefa][prefb][taken] = res;
}

ll xa, xb, ya, yb;

int main () {

	freopen ("map-game.in", "r", stdin);
	freopen ("map-game.out", "w", stdout);


	cin >> xa >> ya;
	cin >> xb >> yb;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].val;
		a[i].id = i;
	}

	for (int i = 1; i <= n; ++i) {
		la.push_back (make_pair (dist (a[i].x, a[i].y, xa, ya), a[i]));
		lb.push_back (make_pair (dist (a[i].x, a[i].y, xb, yb), a[i]));
	}
	
	sort (la.begin (), la.end ());
	sort (lb.begin (), lb.end ());
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (u[la[i].second.id])
				ok[0][i][j] = 0;
			else
				ok[0][i][j] = 1;
			if (u[lb[j].second.id])
				ok[1][i][j] = 0;
			else
				ok[1][i][j] = 1;
			++u[lb[j].second.id];
		}
		for (int j = 0; j < n; ++j)
			--u[lb[j].second.id];
		++u[la[i].second.id];
	}
	
	for (int i = 0; i < n; ++i)
		--u[la[i].second.id];
	
	ll ans = calc (0, 0, 0, 0);
	
	if (ans > 0)
		cout << "Toblerone";
	else if (ans == 0)
		cout << "Don't be an evil!!!";
	else
		cout << "Jack Daniels";

	return 0;
}