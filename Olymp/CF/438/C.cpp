#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 20;

int a[N];
double b[N][5];
bool pre[17][17][17][17], nxt[17][17][17][17];

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;
	cin >> n >> k;

	
	for (int i = 1; i <= n; ++i) {
		int mask = 0;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			mask |= (x << j);
		}		
		++a[mask];
	}

	
	
	for (int i = 0; i < 16; ++i) {
		a[i] = min (a[i], 8);
	}

	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 4 && j < k; ++j) {
			if (bit (i, j))
				b[i][j + 1] = -0.5;
			else
				b[i][j + 1] = +0.5;
		}
	}
	
	
	map <float, int> p;
	
	for (double i = -4, j = 0; i <= 4; i += 0.5, j++) {
		p[i] = j;
	}
	
	for (int i = 0; i < 16; ++i) {
		while (a[i]--) {
			memcpy (pre, nxt, sizeof (nxt));
			//memset (nxt, 0, sizeof (nxt));
			//cerr << i << ":\n";
			double it[5];
			for (it[1] = -4.0; it[1] <= 4; it[1] += 0.5)
			for (it[2] = -4.0; it[2] <= 4; it[2] += 0.5)
			for (it[3] = -4.0; it[3] <= 4; it[3] += 0.5)
			for (it[4] = -4.0; it[4] <= 4; it[4] += 0.5) {
				bool flag = 1;
				for (int j = 1; j <= 4; ++j)
					if (!(-4 <= it[j] + b[i][j] && it[j] + b[i][j] <= 4))
						flag = 0;
				if (!flag)
					break;
				if (pre[p[it[1]]][p[it[2]]][p[it[3]]][p[it[4]]]) {
					//cerr << "OK ";
					nxt[p[it[1] + b[i][1]]][p[it[2] + b[i][2]]][p[it[3] + b[i][3]]][p[it[4] + b[i][4]]] = 1;
					/*
					for (int tt = 1; tt <= 4; ++tt) {
						cerr << it[tt] + b[i][tt] << " ";
					}
					cerr << "\n";
					*/
				}
			}
			nxt[p[b[i][1]]][p[b[i][2]]][p[b[i][3]]][p[b[i][4]]] = 1;
			/*
			for (int tt = 1; tt <= 4; ++tt) {
				cerr << b[i][tt] << " ";
			}
			cerr << "\n";
			*/
		}
	}
	double it[5];
	for (it[1] = 0; it[1] <= 4; it[1] += 0.5)
	for (it[2] = 0; it[2] <= 4; it[2] += 0.5)
	for (it[3] = 0; it[3] <= 4; it[3] += 0.5)
	for (it[4] = 0; it[4] <= 4; it[4] += 0.5) { 
		if (nxt[p[it[1]]][p[it[2]]][p[it[3]]][p[it[4]]]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";	
	return 0;
}