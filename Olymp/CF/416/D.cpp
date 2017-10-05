#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;

int n, m;
char a[N][N];
int sw[2];
int x, y;
int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};
int d[N][N];
inline pair <int, int> make_move (char q) {
	if (q == 'R' || q == 'L') {
	    if (sw[0])
	    	q = (q == 'R') ? 'L' : 'R';
	} else if (q == 'U' || q == 'D') {
		if (sw[1])
			q = (q == 'U') ? 'D' : 'U';			
	}
	cout << q << "\n";
	fflush (stdout);
	int tmp1, tmp2;
	cin >> tmp1 >> tmp2;
	if (tmp1 == x && tmp2 == y) {
		if (q == 'R' || q == 'L')
			sw[0] = 1;
		else
			sw[1] = 1;
	}
	x = tmp1;
	y = tmp2;
	return make_pair (tmp1, tmp2);
} 

inline pair <int, int> make_move (int q) {
	if (q == 0) {
		return make_move ('L');
	}
	if (q == 1) {
		return make_move ('R');
	}
	if (q == 2) {
		return make_move ('U');
	}
	if (q == 3) {
		return make_move ('D');
	}
}

inline char transfer (int q) {
	if (q == 0) {
		return 'L';
	}
	if (q == 1) {
		return 'R';
	}
	if (q == 2) {
		return 'U';
	}
	if (q == 3) {
		return 'D';
	}
}

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '*';
}

int st[110 * 110 * 2];
int stq, enq;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	
	#endif

	cin >> n >> m;


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	
	int to_check = 0;

	x = 1, y = 1;

	for (int i = 2; i <= n; ++i) {
		if (a[i][y] == '.' && (a[i][y + 1] == '.' || a[i][y + 1] == 'F')) {
			to_check = max (to_check, 1);
			break;
		} else if (a[i][y] == '*') {
			break;
		} else if (a[i][y] == 'F') {
			to_check = max (to_check, 10);
		}
	}
	
	for (int i = 2; i <= m; ++i) {
		if (a[x][i] == '.' && (a[x + 1][i] == '.' || a[x + 1][i] == 'F')) {
			to_check = max (to_check, 2);
			break;
		} else if (a[x][i] == '*') {
			break;
		} else if (a[x][i] == 'F') {
			to_check = max (to_check, 20);
		}
	}	
	
	
	if (to_check == 10) {
		while (a[x][y] != 'F') {
			make_move ('D');
		}
		return 0;
	}
	if (to_check == 20) {
		while (a[x][y] != 'F') {
			make_move ('R');
		}	
		return 0;
	}	
	
	if (to_check == 1) {
		while (!(a[x][y] == '.' && (a[x][y + 1] == '.' || a[x][y + 1] == 'F'))) make_move ('D');
		make_move ('R');
	}
	if (to_check == 2) {
		while (!(a[x][y] == '.' && (a[x + 1][y] == '.' || a[x + 1][y] == 'F'))) make_move ('R');
		make_move ('D');
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			d[i][j] = 0;
	
	st[++enq] = x;
	st[++enq] = y;
	d[x][y] = 1;
	while (stq != enq) {
		int ox = st[++stq], oy = st[++stq];
		for (int i = 0; i < 4; ++i) {
			int nx = ox + dx[i], ny = oy + dy[i];
			if (inside (nx, ny) && !d[nx][ny]) {
				d[nx][ny] = d[ox][oy] + 1;
				st[++enq] = nx;
				st[++enq] = ny;			
			}
		}
	}	

	int psx = 0, psy = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'F')	
				psx = i, psy = j;
	
	string ans;

	while ((psx != x || psy != y)) {
		for (int i = 0; i < 4; ++i) {
			if (d[psx + dx[i]][psy + dy[i]] + 1 == d[psx][psy]) {
				ans += transfer (i ^ 1);
				psx += dx[i];
				psy += dy[i];
				break;
			}
		}
	}
	reverse (ans.begin (), ans.end ());

	for (int i = 0; i < ans.size (); ++i) {
		make_move (ans[i]);
	}
	
	return 0;
}