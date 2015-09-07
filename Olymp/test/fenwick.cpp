#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;


typedef long long ll;

const ll inf = 2e9;
const ll N = 4e9 + 1;


map <pair <ll, ll>, int> Map;

const int sz = 2e6;

ll key1[sz], key2[sz];
int val[sz];


inline int& change (const ll &skey1, const ll &skey2) {

}


inline void upd (const ll &x, const ll &y, const int &delta) {
	for (ll i = x; i < N; i |= (i + 1))
		for (ll j = y; j < N; j |= (j + 1))
			Map[make_pair (i, j)] += delta;
}

inline int get (const ll &x, const ll &y) {
	int res = 0;
	for (ll i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (ll j = y; j >= 0; j = (j & (j + 1)) - 1)
			res += Map[make_pair (i, j)];
	return res;
}

inline int get (const ll &sx, const ll &sy, const ll &fx, const ll &fy) {
	return get (fx, fy) - get (fx, sy - 1) - get (sx - 1, fy) + get (sx - 1, sy - 1);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	char q_type[6];
	
	while (scanf ("%s", &q_type) == 1) {
		if (q_type[0] == 'A') {
			int x, y;
			scanf ("%d%d\n", &x, &y);
			ll tx, ty;
			tx = x + inf;
			ty = y + inf;
			if (get (tx, ty, tx, ty) == 1) {
				printf ("ALREADY EXISTS\n");
			} else {
				printf ("ADDED\n");
				upd (tx, ty, 1);
			}
		} else if (q_type[0] == 'D') {
			int x, y;
			scanf ("%d%d\n", &x, &y);
			ll tx = x + inf, ty = y + inf;
			if (get (tx, ty, tx, ty) == 1) {
				printf ("DELETED\n");
				upd (tx, ty, -1);
			} else {
				printf ("NOT FOUND\n");
			}
		} else {
			int sx, sy, fx, fy;
			scanf ("%d%d%d%d", &sx, &sy, &fx, &fy);
			ll tsx = sx + inf, tsy = sy + inf, tfx = fx + inf, tfy = fy + inf;
			printf ("%d\n", get (tsx, tsy, tfx, tfy));
		}
		cerr << "OK";
	}
	
	return 0;
}