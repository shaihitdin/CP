#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2, inf = 1e9;

#define mkp make_pair
#define F first
#define S second

string s;


int n, ans;

inline int get_num (const char &x) {
	if (x == 'M')
		return 1;
	if (x == 'B')
		return 2;
	if (x == 'F')
		return 3;
}

int d[2][5][5][5][5];

bool u[4];

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);


	cin >> n;

	cin >> s;


	memset (d, -1, sizeof (d));
	d[1][0][0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
	int temp = get_num (s[i - 1]);
	for (int k1 = 0; k1 <= 3; ++k1)
	for (int k2 = 0; k2 <= 3; ++k2)
	for (int k3 = 0; k3 <= 3; ++k3)
	for (int k4 = 0; k4 <= 3; ++k4) {
		if (d[i & 1][k1][k2][k3][k4] == -1)
			continue;
		memset (u, 0, sizeof (u));
		
		u[k1] = u[k2] = u[temp] = 1;
		int ddad = 0;
		for (int j = 1; j <= 3; ++j)
			ddad += u[j];
		d[(i + 1) & 1][k2][temp][k3][k4] = max (d[(i + 1) & 1][k2][temp][k3][k4], d[i & 1][k1][k2][k3][k4] + ddad);

		memset (u, 0, sizeof (u));

		u[k3] = u[k4] = u[temp] = 1;
		ddad = 0;
		for (int j = 1; j <= 3; ++j)
			ddad += u[j];
		d[(i + 1) & 1][k1][k2][k4][temp] = max (d[(i + 1) & 1][k1][k2][k4][temp], d[i & 1][k1][k2][k3][k4] + ddad);
	}							
	}
	int temp = get_num (s[n - 1]);
	for (int k1 = 1; k1 <= 3; ++k1)
	for (int k2 = 1; k2 <= 3; ++k2)
	for (int k3 = 1; k3 <= 3; ++k3)
	for (int k4 = 1; k4 <= 3; ++k4) {
		//ans = max (ans, d[(n + 1) & 1][k1][k2][k3][k4][k5][k6]);
		ans = max (d[(n + 1) & 1][k1][temp][k3][k4], ans);
		ans = max (d[(n + 1) & 1][k1][k2][k3][temp], ans);
	}
	cout << ans;
	return 0;
}