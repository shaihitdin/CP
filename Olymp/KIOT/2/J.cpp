#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 100;

int lpd[N], d[N];
int n;
vector <int> ans;

inline int get_cnt (const int &i) {
	int x = i, div_cnt = 1;
	while (x > 1) {
		int dc = lpd[x];
		int cnt = 0;
		while (lpd[x] == dc) {
			x /= lpd[x];
			++cnt;
		}
		div_cnt *= (cnt + 1);
	}
	return div_cnt;
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	srand (time (0));
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 2; i < N; i += 2) {
		lpd[i] = 2;
	}
	
	for (int i = 3; i * i < N; i += 2) {
		if (!lpd[i]) {
			lpd[i] = i;
			for (int j = i * i; j < N; j += (2 * i)) {
				if (!lpd[j])
					lpd[j] = i;
			}
		}
	}
	
	for (int i = 3; i < N; i += 2) {
		if (!lpd[i])
			lpd[i] = i;
	}
	
	memset (d, -1, sizeof (d));

	d[0] = 0;
	
	for (int i = 1; i < N; ++i) {
		int x = get_cnt (i);
		if (x > 300) {
			continue;
		}
		if (d[i - x] == -1) {
			continue;
		}
		d[i] = d[i - x] + 1;
	}	
	for (int i = 1; i < N; ++i) {
		if (d[i] == n) {
			while (i > 0) {
				int x = get_cnt (i);
				ans.emplace_back (x);
				i -= x;
			}
			break;
		}
	}
	
	reverse (ans.begin (), ans.end ());
	
	if (ans.size () == n) {
		for (auto it : ans)
			cout << it << " ";
	} else {
		cout << "Impossible";
	}

	return 0;
}