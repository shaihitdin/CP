#include <bits/stdc++.h>

using namespace std;

string s1, s2, virus;

int nxt[110][256];
int d[110][110][110];
int p[110][110][110];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> s1 >> s2 >> virus;

	string tmp = "";
	string tmpp = "";
	
	for (int i = 0; i < virus.size (); ++i) {
		for (char j = 'A'; j <= 'Z'; ++j) {
			for (int n_len = 1; n_len <= i + 1; ++n_len) {
				tmp = "";
				if (i > 0) {
					for (int k = max (0, i - 1 - (n_len - 1) + 1); k < i; ++k)
						tmp += virus[k];
				}
				tmp += j;
				//cerr << i << " " << tmp.size () << " " << n_len << "\n";
				assert (tmp.size () == n_len);
				tmpp = "";
				for (int k = 0; k < n_len; ++k)
					tmpp += virus[k];
				if (tmpp == tmp)
					nxt[i][j] = n_len;
			}
		}
	}

	for (int i = 0; i <= s1.size (); ++i) {
		for (int j = 0; j <= s2.size (); ++j) {
			for (int k = 0; k < virus.size (); ++k) {
				d[i + 1][j][k] = max (d[i + 1][j][k], d[i][j][k]);
				d[i][j + 1][k] = max (d[i][j + 1][k], d[i][j][k]);
				if (i != s1.size () && j != s2.size () && s1[i] == s2[j]) {
					if (d[i + 1][j + 1][nxt[k][s1[i]]] < d[i][j][k] + 1)
						p[i + 1][j + 1][nxt[k][s1[i]]] = k;
					d[i + 1][j + 1][nxt[k][s1[i]]] = max (d[i + 1][j + 1][nxt[k][s1[i]]], d[i][j][k] + 1);
				}
			}
		}
	}
	
	int ans = 0;

	for (int i = 0; i < virus.size (); ++i)
		ans = max (ans, d[s1.size ()][s2.size ()][i]);
	
	for (int i = 0; i < virus.size (); ++i) {
		if (ans == d[s1.size ()][s2.size ()][i]) {
			string ans_s;
			int v = s1.size (), u = s2.size (), k = i;
			while (d[v][u][k] > 0) {
				if (d[v - 1][u][k] == d[v][u][k]) {
					--v;
				} else if (d[v][u - 1][k] == d[v][u][k]) {
					--u;
				} else {
					ans_s += s1[v - 1];
					k = p[v][u][k];
					--v;
					--u;
				}
			}
			reverse (ans_s.begin (), ans_s.end ());
			assert (ans_s.size () == ans);
			cout << ans_s;
			if (ans_s.size () == 0)
				cout << 0;
			return 0;
		}
	}
	
	return 0;
}