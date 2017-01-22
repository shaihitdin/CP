/// Oh, my dear
#include <bits/stdc++.h>

using namespace std;

const int N = 10, oo = 1e9;

int n, t;
int l[N], a[N][N], c[N];
vector <int> starta[N], startb[N];

map <pair <int, pair <int, pair <int, pair <vector <int>, vector <int> > > > > > Map;

inline int calc (int player, int num, vector <int> cnt1, vector <int> cnt2) {
	if (Map.count (make_pair (player, make_pair (num, make_pair (cnt1, make_pair (cnt2))))))
		return Map[make_pair (player, make_pair (num, make_pair (cnt1, make_pair (cnt2))))];
	if (num == t + 1) {
		Map[make_pair (player, make_pair (num, make_pair (cnt1, make_pair (cnt2))))] = 0;
		return 0;
	}
	int res = -oo;
	res = max (res, calc (player ^ 1, num + 1, cnt1, cnt2));
	if (player == 0) {
		for (int i = 0; i < n; ++i) {
			if (cnt1[i] < l[i]) {
				++cnt1[i];
				res = max (res, calc (player ^ 1, num + 1, cnt1, cnt2));
				--cnt1[i];
			}
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (cnt2[i] < l[i]) {
				++cnt2[i];
				res = max (res, calc (player ^ 1, num + 1, cnt1, cnt2));
				--cnt2[i];
			}
		}	
	}
	if (player == 0) {
	
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> t;

	for (int i = 0; i < n; ++i)
		cin >> l[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	starta.resize (n);
	startb.resize (n);
	for (int i = 0; i < n; ++i)
		cin >> starta[i];
	for (int i = 0; i < n; ++i)
		cin >> startb[i];

	cout << calc (0, 1, starta, startb);
	return 0;
}