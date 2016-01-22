#include <bits/stdc++.h>

using namespace std;

const int N = 2050;

struct problem {
	int diff, delta, t, id;
};

inline bool operator < (const problem &a, const problem &b) {
	return a.diff < b.diff;
}

int d[N][N];

int main () {
    
    freopen ("practice.in", "r", stdin);
    freopen ("practice.out", "w", stdout);

    int n, t, r0;
    
    cin >> n >> t >> r0;

	vector <problem> v;
	
	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back ({x, y, z, i});
	}
	
	sort (v.begin (), v.end ());

	d[0][0] = r0;
	
	for (int i = 0; i <= n; ++i) {
		auto it = v[i];
		for (int j = 0; j <= t; ++j) {
			if (i > 0)
				d[i][j] = max (d[i][j], d[i - 1][j]);
			if (j > 0)
				d[i][j] = max (d[i][j], d[i][j - 1]);
			if (i < n && d[i][j] >= it.diff && j + it.t <= t) {
				d[i + 1][j + it.t] = d[i][j] + it.delta;
			}
		}
	}
	
	cout << d[n][t] << "\n";
	
	int sd = n, st = t;

	vector <int> ans;
	
	while (sd != 0 && st != 0) {
		if (d[sd - 1][st] == d[sd][st])
			--sd;
		else if (d[sd][st - 1] == d[sd][st])
			--st;
		else
			ans.emplace_back (v[--sd].id), st -= v[sd].t;
	}
	
	reverse (ans.begin (), ans.end ());
	
	for (auto ff : ans)
		cout << ff << " ";
	
	return 0;
}