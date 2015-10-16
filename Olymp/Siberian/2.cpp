#include <bits/stdc++.h>

using namespace std;

const int N = 3e5, LVL = 19;

map <string, int> Map;

int d[N][LVL];
int c_p[N], lvl[N];

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;

	cin >> n;

	for (int i = 1; i <= (1 << n); ++i) {
		string x;
		cin >> x;
		Map[x] = i;
		//cerr << x << " ";
	}

	for (int i = 1; i <= (1 << n); ++i) {
		d[i][0] = i;
	}
	

	for (int i = 1; i <= (1 << n); ++i) {
		lvl[i] = 0;
		c_p[i] = i;
	}
	
	
	
	for (int round = 1; round <= n; ++round) {
		for (int j = 1; j <= (1 << n); j += (1 << round)) {
			char e;
			cin >> e;
			if (e == 'W') {
				d[j][round] = d[j][round - 1];
			} else {
				d[j][round] = d[j + (1 << (round - 1))][round - 1];
			}
			c_p[d[j][round]] = j;
			lvl[d[j][round]] = round;
 		}
	}
	
	int q;
	
	cin >> q;

	while (q--) {
		string x, y;
		cin >> x >> y;
		int xx, yy;
		xx = Map[x];
		yy = Map[y];
		if (xx == yy) {
			cout << "Unknown\n";
			continue;
		}
		
		//cerr << c_p[yy] << " " << xx << " " << c_p[yy] + (1 << lvl[yy]) - 1 << "\n";
		if (c_p[xx] <= yy && yy <= c_p[xx] + (1 << lvl[xx]) - 1) {
			cout << "Win\n";
		} else if (c_p[yy] <= xx && xx <= c_p[yy] + (1 << lvl[yy]) - 1) {
			cout << "Lose\n";
		} else {
			cout << "Unknown\n";
		}
	}
	
	return 0;
}