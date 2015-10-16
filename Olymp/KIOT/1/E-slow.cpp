#include <bits/stdc++.h>

using namespace std;

vector <int> tmp, ans;
int ans_done;
int n;
int u[2][10];
vector <int> lst[2][10];

inline void reportans () {
	for (int i = 0; i < ans.size (); i += 3) {
		int from1 = ans[i], from2 = ans[i + 1], cnt = ans[i + 2];
		for (int j = 1; j <= cnt; ++j) {
			cout << lst[0][from1].back () << " " << lst[1][from2].back () << "\n";
			lst[0][from1].pop_back ();
			lst[1][from2].pop_back ();
		}
	}
	
	for (int i = 0; i < 7; ++i) {
		if (!lst[0][i].size ())
			continue;
		for (int j = 0; j < 7; ++j) {
			if (!lst[1][j].size ())
				continue;
			int cnt = min (lst[0][i].size (), lst[1][j].size ());
			while (cnt--) {
				cout << lst[0][i].back () << " " << lst[1][j].back () << "\n";
				lst[0][i].pop_back ();
				lst[1][j].pop_back ();
			}
		}
	}
	exit (0);
}

inline void rec (short points, short done, short lst_i) {
	if (done > ans_done) {
		ans_done = done;
		ans = tmp;
	}
	if (clock () * 1000 / CLOCKS_PER_SEC > 950) {
		reportans ();
	}
	for (int i = lst_i; i < 7; ++i) {
		if (!u[0][i])
			continue;
		for (int j = 0; j < 7; ++j) {
			if (!u[1][j])
				continue;
			int l = 0, r = n - done + 1;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (abs (points + mid * (i - j)) <= (n - done - mid) * 6) {
					l = mid;
				} else {
					r = mid;
				}
			}
			if (l > 0) {
				int does = min (l, min (u[0][i], u[1][j]));
				u[0][i] -= does;
				u[1][j] -= does;
				points += does * (i - j);
				tmp.emplace_back (i);
				tmp.emplace_back (j);
				tmp.emplace_back (does);
				rec (points, done + does, i);
				tmp.pop_back ();
				tmp.pop_back ();
				tmp.pop_back ();
				u[0][i] += does;
				u[1][j] += does;
				points -= does * (i - j);
			}
		}
	}
}

int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++u[0][x];
		lst[0][x].emplace_back (i);
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++u[1][x];
		lst[1][x].emplace_back (i);
	}
	
	
	tmp.resize (3000);
	tmp.resize (0);
		
	rec (0, 0, 0);
	
	reportans ();
	
	return 0;
}