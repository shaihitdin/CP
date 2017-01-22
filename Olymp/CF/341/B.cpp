/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> g;
ll sum;
const int N = 1100;

int d1[N][N], d2[N][N];
int stq, enq;
pair <int, int> st[N * N];
int cnt1[N + N], cnt2[N + N];
bool u[N][N];

inline bool inside (int x, int y) {
	return 1 <= x && x <= 1000 && 1 <= y && y <= 1000;
}
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

inline void bfs (int x, int y, int d[N][N]) {
	stq = enq = 0;
	st[enq++] = make_pair (x, y);
	d[x][y] = 1;
	while (stq != enq) {
		auto v = st[stq++];
		for (int i = 0; i < 4; ++i) {
			int nx = v.first + dx[i], ny = v.second + dy[i];
			if (!inside (nx, ny))
				continue;
			if (!d[nx][ny]) {
				d[nx][ny] = d[v.first][v.second] + 1;
				st[enq++] = make_pair (nx, ny);
			}
		}
	}
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		u[x][y] = 1;
	}
	bfs (1, 1, d1);
	bfs (1000, 1, d2);
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			cnt1[d1[i][j]] += u[i][j];
			cnt2[d2[i][j]] += u[i][j];
		}
	}
	ll ans = 0;
	for (int i = 1; i < N + N; ++i) {
		ans += ((cnt1[i] - 1) * cnt1[i]) / 2;
   		ans += ((cnt2[i] - 1) * cnt2[i]) / 2;
	}
	cout << ans;
	return 0;
}