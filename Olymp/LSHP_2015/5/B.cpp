#include <bits/stdc++.h>

using namespace std;

const int N = 51;

bool deactivated[N];

vector <int> g[N];
bool u[N];
int n, m;
vector <int> temp, ans;
int st[N], stq, enq;


inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline void bfs (const int &str) {
	stq = enq = 0;
	st[++enq] = str;
	u[str] = 1;
	while (stq < enq) {
		int v = st[++stq];
		for (auto to : g[v])
			if (!u[to] && !deactivated[to])
				u[to] = 1, st[++enq] = to;
	}
}

inline void check () {
	/*
	if (clock () * 1000 / CLOCKS_PER_SEC > 1990) {
		cout << ans.size () << "\n";
		for (auto it : ans)
			cout << it << " ";
		exit (0);
	}
	*/
	memset (u, 0, sizeof (u));
	for (int i = 1; i <= n; ++i) {
		if (!deactivated[i]) {
			bfs (i);
			break;
		}
	}

	temp.resize (0);

	for (int i = 1; i <= n; ++i)
		if (deactivated[i])
			temp.push_back (i);
	
	for (int i = 1; i <= n; ++i) {
		if (!u[i] && !deactivated[i]) {
			if (ans.size () > temp.size ())
				ans = temp;
			return;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (u[i]) return;
	if (ans.size () > temp.size ())
		ans = temp;
}

inline void rec (const int &lvl, const int &need) {
	if (lvl == n + 1) {
		check ();
		return;
	}
	if (need > 0) {
		deactivated[lvl] = 1;
		rec (lvl + 1, need - 1);
		deactivated[lvl] = 0;
	}
	rec (lvl + 1, need);
}


int main () {

	freopen ("hackers.in", "r", stdin);
	freopen ("hackers.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}
	
	for (int i = 1; i <= n; ++i)
		ans.push_back (i);

	
	
	if (n <= 21) {
		for (int i = 0; i < (1 << n); ++i) {
			memset (deactivated, 0, sizeof (deactivated));
			for (int j = 0; j < n; ++j)
				deactivated[j + 1] = bit (i, j);
			check ();
		}
	} else {
		if (n <= 22) {
			rec (1, 9);
		} else if (n <= 24) {
			rec (1, 8);
		} else if (n <= 34) {
			rec (1, 7);
		} else if (n <= 35) {
			rec (1, 6);
		} else {
			rec (1, 5);
		}
	}
	
	cout << ans.size () << "\n";

	for (auto it : ans)
		cout << it << " ";
	
	return 0;
}