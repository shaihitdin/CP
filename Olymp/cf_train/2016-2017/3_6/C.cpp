#include <bits/stdc++.h>

using namespace std;

int lim[6], cnt[2][6];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	map <string, int> parse;

	parse["white"] = 0;
	parse["black"] = 1;
	parse["king"] = 0;
	parse["queen"] = 1;
	parse["bishop"] = 2;
	parse["knight"] = 3;
	parse["rook"] = 4;
	parse["pawn"] = 5;
	
	lim[0] = 1;
	lim[1] = 1;
	lim[2] = 2;
	lim[3] = 2;
	lim[4] = 2;
	lim[5] = 8;
	
	int k1, k2;
	cin >> k1 >> k2;

	for (int i = 1; i <= k1; ++i) {
		string s;
		cin >> s;
		int x = parse[s];
		cin >> s;
		int y = parse[s];
		++cnt[x][y];
	}

	vector <string> ansv;
	
	for (int i = 1; i <= k2; ++i) {
		string s1, s2;
		cin >> s1;
		int x = parse[s1];
		cin >> s2;
		int y = parse[s2];
		if (cnt[x][y] < lim[y]) {
			++cnt[x][y], ansv.push_back (s1), ansv.push_back (s2);
		}

	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (cnt[i][j] < lim[j]) {
				puts ("impossible");
				return 0;
			}
		}
	}
	
	for (int i = 0; i < ansv.size (); i += 2)
		cout << ansv[i] << " " << ansv[i + 1] << endl;
	
	return 0;
}