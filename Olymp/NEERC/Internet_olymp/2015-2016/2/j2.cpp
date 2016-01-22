#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int timer[N], t[N], rule[N];
int cnt;

inline int get (int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += t[r];
	return res;
}

inline void upd (int r, const int &delta) {
	for (; r < N; r = (r | (r + 1)))
		t[r] += delta;
}

inline int get (int l, int r) {
	return get (r) - get (l - 1);
}


inline int get_pos () {
	int l = -1, r = N - 100;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (get (mid, N) == 0)
			r = mid;
		else
			l = mid;
	}
	return l;
}

int main () {


	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);


	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
	
	cin >> n;

	while (n--) {
		int x;
		cin >> x;
		if (x < 0) {
			x = -x;
			if (rule[x]) {
				int y = rule[x];
				rule[x] = 0;
				timer[y] = 0;
				upd (y, -1);
			}
		} else if (x == 0) {
			int y = get_pos ();
			int el = timer[y];
			rule[el] = 0;
			timer[y] = 0;
			upd (y, -1);
		} else {
			++cnt;
			timer[cnt] = x;
			rule[x] = cnt;
			upd (cnt, 1);
		}
		int y = get_pos ();
		if (y == -1) {
			cout << 0 << "\n";
		} else {
			cout << timer[y] << "\n";
		}
	}

	return 0;
}