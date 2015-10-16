#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > tmp, ans;
int ans_done;
int n;
int u[2][10];
vector <int> lst[2][10];
int limit[2][10];
int a[10][10];

inline void reportans () {
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			while (a[i][j] > 0) {
				--a[i][j];
				ans.emplace_back (make_pair (i, j));
			}
		}
	}
	
	int sum = 0;
	
	for (int i = 0; i < ans.size (); ++i)
		if (ans[i].first == ans[i].second)
			swap (ans[0], ans[i]);

	for (int i = 0; i < ans.size (); ++i) {
		for (int j = i + 1; j < ans.size (); ++j)
			if (abs (sum + ans[i].first - ans[i].second) > abs (sum + ans[j].first - ans[j].second))
				swap (ans[i], ans[j]);
		sum += ans[i].first - ans[i].second;
	}
	
	for (int i = 0; i < ans.size (); ++i) {
		int from1 = ans[i].first, from2 = ans[i].second;
		cout << lst[0][from1].back () << " " << lst[1][from2].back () << "\n";
		lst[0][from1].pop_back ();
		lst[1][from2].pop_back ();
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



int now[2][10];
int balance;

inline bool calc (const int &x) {
	bool flag = 0;
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			int can = min (limit[0][i] - now[0][i], limit[1][j] - now[1][j]);
			if (can > 0) {
				++a[i][j];
				++now[0][i];
				++now[1][j];
				flag = 1;
				goto gogo;
			}
		}
	}			
	
	gogo:;
	
	assert (flag);
	for (int cnt = 0; cnt < 100; ++cnt) {
		for (int i = 0; i < 7; ++i) {
			for (int j = 0; j < 7; ++j) {
				for (int i1 = 0; i1 < 7; ++i1) {
					for (int j1 = 0; j1 < 7; ++j1) {
						
					}
				}
			}
		}
	}
	return abs (balance) <= (n - x) * 6;
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
		++limit[0][x];
		lst[0][x].emplace_back (i);
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++limit[1][x];
		lst[1][x].emplace_back (i);
	}
	
	
	for (int i = 1; i <= n; ++i) {
		if (!calc (i))
			reportans ();
	}

	reportans ();
	
	return 0;
}