#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;

int n, m;

string s, t, tt;

int pos[256], anti[256];

int p[N];

int cnt[N][140];

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	cin >> t;

	cin >> s;

	tt = s + "#" + t;

	for (int i = 1; i < s.size (); ++i) {
		int j = p[i - 1];
		while (j && tt[i] == tt[j])
			j = p[j - 1];
		if (tt[i] == tt[j])
			++j;
		p[i] = j;
	}

	for (int i = 0; i < s.size (); ++i) {
		for (int j = 'a'; j <= 'z'; ++j)
			cnt[i][j] = cnt[i - 1][j];
		++cnt[i][s[i]];
	}
	
	
	for (int i = s.size () + 1; i < tt.size (); ++i) {
		int j = p[i - 1];
		while (j) {
			if ((!j || !cnt[j - 1][s[j]]) || (anti[s[j]] == tt[i] && anti[tt[i]] == s[j])) {				
				break;
			} else {
				j = p[j - 1];
			}
		}
		if ((!j || !cnt[j - 1][s[j]]) || (anti[s[j]] == tt[i] && anti[tt[i]] == s[j])) {				
			/*
			pos[tt[i]] = i;
			pos[tt[j]] = i;
			*/
			anti[tt[i]] = s[j];
			anti[s[j]] = tt[i];
			++j;
		}

		if (j > s.size ())
			--j;

		cerr << s[j - 1] << " " << char (anti[s[j]]) << "\n";		
		
		if (j == s.size ())
			cout << i - s.size () - s.size () + 1 << " ";
		cerr << j << " ";
		p[i] = j;
	}
	
	return 0;
}