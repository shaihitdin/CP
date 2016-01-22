#include <bits/stdc++.h>


using namespace std;

int d[120][420][58][2][2];

int d_c[2];
int n;

string s;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> s;

	cin >> n;

	d_c[0] = 1;
	d_c[1] = -1;
	
	d[0][200][0][0][0] = 1;
	
	for (int i = 0; i < s.size (); ++i)
		for (int j = 1; j < 400; ++j)
			for (int k = 0; k <= n; ++k)
				for (int di = 0; di < 2; ++di)
						if (s[i] == 'T')
							d[i + 1][j][k][di ^ 1][0] |= d[i][j][k][di][0], d[i][j][k + 1][di][1] |= d[i][j][k][di][0], 
							d[i + 1][j + d_c[di]][k][di][0] |= d[i][j][k][di][1], d[i][j][k + 1][di][0] |= d[i][j][k][di][1];
						else
							d[i + 1][j + d_c[di]][k][di][0] |= d[i][j][k][di][0], d[i][j][k + 1][di][1] |= d[i][j][k][di][0],
							d[i + 1][j][k][di ^ 1][0] |= d[i][j][k][di][1], d[i][j][k + 1][di][0] |= d[i][j][k][di][1];
	
	int ans = 0;
	for (int j = 1; j < 400; ++j)
		for (int di = 0; di < 2; ++di)
			if (d[s.size ()][j][n][di][0])
				ans = max (ans, abs (200 - j));
	
	cout << ans;
	return 0;
}