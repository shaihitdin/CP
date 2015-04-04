#include <bits/stdc++.h>

using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N = 3001;

map <string, string> ch1, ch2;
map <string, int> pos1, pos2;
int sz;
string a[2][N], b[2][N], c[2][N];
int s[2][N], p[N];
vector <int> v;
int ch1[N], ch2[N], pos1[N], pos2[N];
int n, m, mx, ans;
char eq, pl;

string cs[4][N];
int main () {
	freopen ("code.in", "r", stdin);
	freopen ("code.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[0][i] >> eq >> b[0][i] >> pl >> c[0][i];
		if (b[0][i] > c[0][i])
			swap (b[0][i], c[0][i]);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> a[1][i] >> eq >> b[1][i] >> pl >> c[1][i];
		if (b[1][i] > c[1][i])
			swap (b[1][i], c[1][i]);	
	}
	for (int cnt = 1; cnt < n; ++cnt) {
		for (int i = 1; i <= 3; ++i)
			for (int j = 0; j < N; ++j)
				cs[i][j].resize(0);		
		v.resize (0);
		for (int j = cnt; j <= n; ++j) {
			cs[1][j - cnt] = a[0][j];
			cs[2][j - cnt] = b[0][j];
			cs[3][j - cnt] = c[0][j];
		}
		for (int j = 1; j <= m; ++j) {
			cs[1][n - cnt + j] = a[1][j];
			cs[2][n - cnt + j] = b[1][j];
			cs[3][n - cnt + j] = c[1][j];
		}
		memset (p, 0, sizeof (p));
		int i = 1;
		for (; v[i] != 0; ++i) {
			int j;
			for (j = p[i - 1]; j > 0 && v[j] != v[i]; j = p[j - 1]);						
			if (v[i] == v[j])
				++j;			
			p[i] = j;
		}
		++i;
		mx = 0;
		memset (ch1, 0, sizeof (ch1));
		memset (ch2, 0, sizeof (ch2));
		memset (pos1, 0, sizeof (pos1));
		memset (pos2, 0, sizeof (pos2));
		for (; i < v.size(); ++i) {
			int j;
			for (j = p[i - 1]; j > 0 && ( (pos1[v[j]] >= i - j + 1 && ch1[v[j]] != v[i]) || (pos2[v[i]] >= i - j + 1 && ch2[v[i]] != v[j])); j = p[j - 1]);
			if (!( (pos1[v[j]] >= i - j + 1 && ch1[v[j]] != v[i]) || (pos2[v[i]] >= i - j + 1 && ch2[v[i]] != v[j]))) {
				++j;
			}
			ch1[v[j]] = v[i];
			pos1[v[j]] = i;
			ch2[v[i]] = v[j];
			pos2[v[i]] = i;
			p[i] = j;
			mx = max (mx, p[i]);
		}		
		ans = max (ans, min (n, mx));
	}
	cout << ans;
	return 0;
}