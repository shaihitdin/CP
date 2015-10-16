#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, inf = 1e9;

#define mkp make_pair

int n, x[N], h[N];
vector <pair <int, int> > a;
bool u[N];
int ans;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> h[i];
		a.push_back (mkp (x[i], i));
		a.push_back (mkp (x[i] + h[i], i));
	}

	int r = -inf - 10;

	sort (a.begin (), a.end ());

	for (auto it : a) {
		
		if (u[it.second]) {
			r = x[it.second];
			continue;
		}
		int i = it.second;
		if (x[i] + h[i] == it.first) {
			if (x[i] > r) {
				u[i] = 1;
				r = x[i] + h[i];
				++ans;
			}
		} else {
			if (x[i] - h[i] > r) {
				u[i] = 1;
				r = x[i];
				++ans;
			}
		}
		r = max (r, x[it.second]);
	}


	cout << ans;

	return 0;
}