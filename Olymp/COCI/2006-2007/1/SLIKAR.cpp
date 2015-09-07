#include <bits/stdc++.h>

using namespace std;

const int N = 55, oo = 1e9 + 7;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int ans;
int n, m;
char a[N][N];
bool flood[2][N][N];
bool d[2][N][N];
int fi, fj;


inline bool inside (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			flood[0][i][j] = (a[i][j] == '*');
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'S')
				d[0][i][j] = 1;
			else
				d[0][i][j] = 0;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'D')
				fi = i, fj = j;

	int ans = oo;
	
	//cerr << fi << " " << fj;
	
	for (int step = 1; step <= n + m + 100; ++step) {
		bool st = step & 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				flood[st][i][j] = 0;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				for (int dr = 0; dr < 4; ++dr)
					flood[st][i][j] |= flood[st ^ 1][i + dx[dr]][j + dy[dr]];
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				flood[st][i][j] |= flood[st ^ 1][i][j];
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (a[i][j] == 'X')
					flood[st][i][j] = 0;

		flood[st][fi][fj] = 0;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				d[st][i][j] = 0;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (!flood[st][i][j])
					for (int dr = 0; dr < 4; ++dr)
						d[st][i][j] |= d[st ^ 1][i + dx[dr]][j + dy[dr]];
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (a[i][j] == 'X')
					d[st][i][j] = 0;
		
		if (d[st][fi][fj]) {
			cout << step;
			return 0;
		}
	}
	
	cout << "KAKTUS";

	return 0;
}