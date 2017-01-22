#include <bits/stdc++.h>

using namespace std;
const int N = 3010;

#define fe first
#define se second
#define mp make_pair

int m, n;
char ans[N][N];
int a[N], cc[N];
pair <int, int> b[N];

int main () {
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    #endif

    ios_base :: sync_with_stdio (0);
    cin.tie (0);

    cin >> m >> n;

    for (int i = 1; i <= m; ++i)
    	for (int j = 1; j <= m; ++j)
    		ans[i][j] = 'D';
    for (int i = 1; i <= m; ++i)
    	ans[i][i] = 'X';
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	cc[i] = a[i];
    	a[i] -= (m - 1);
    }

	for (int i = n + 1; i <= m; ++i) {
		a[i] = cc[n] - (m - 1);
		cc[i] = cc[n];
	}

	for (int i = 1; i <= m; ++i)
		b[i] = mp (a[i], i);
	
	for (int step = 0; step < m; ++step) {
		sort (b + 1, b + m + 1 - step);
		for (int i = 1; i < m - step && b[m - step].fe > 0; ++i) {
			b[m - step].fe--;
			b[i].fe++;
			ans[b[m - step].se][b[i].se] = 'W';
			ans[b[i].se][b[m - step].se] = 'L';
		}
		if (step < n && b[m - step].fe != 0) {
			cout << "no\n";
			return 0;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		int res = 0;
		for (int j = 1; j <= m; ++j) {
			if (ans[i][j] == 'W')
				res += 2;
			if (ans[i][j] == 'D')
				res += 1;
		}
		if ((i <= n && res != cc[i]) || (i > n && res > cc[i])) {
			assert (0);
			cout << "no\n";
			return 0;
		}

	}

	cout << "yes\n";

	
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}