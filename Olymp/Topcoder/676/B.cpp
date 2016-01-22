#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;
int n, m;
int dp[51][51][2600];
vector <string> s_copy;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//int d[51][51];


class BoardEscape {	
	
	inline bool inside (const int &x, const int &y) {
		return 0 <= x && x < n && 0 <= y && y < m;
	}
	
	inline int calc (const int &vx, const int &vy, const int &turns) {
		if (dp[vx][vy][turns] != -1)
			return dp[vx][vy][turns];
		if (s_copy[vx][vy] == 'E')
			return dp[vx][vy][turns] = 0;
		if (turns == 0)
			return dp[vx][vy][turns] = 0;
		dp[vx][vy][turns] = 0;
		bool u[10];
		memset (u, 0, sizeof (u));
		for (int i = 0; i < 4; ++i) {
			auto nv = make_pair (vx + dx[i], vy + dy[i]);
			if (inside (nv.first, nv.second) && s_copy[nv.first][nv.second] != '#')
				u[calc (nv.first, nv.second, turns - 1)] = 1;
		}
		for (int i = 0;; ++i)
			if (!u[i])
				return dp[vx][vy][turns] = i;
	}
	
	public:
    string findWinner(vector <string> s, int k) {
		memset (dp, -1, sizeof (dp));
		s_copy = s;
		n = s.size (), m = s[0].size ();
        if (k > n * m) {
			int odd = k & 1;
            k = n * m + 10;
            if ((k & 1) != odd)
                k ^= 1;
        }
/*
		pair <int, int> st[50 * 50 * 2];
		int stq = 0, enq = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (s[i][j] == 'E') {
					d[i][j] = 0;
					st[enq++] = make_pair (i, j);
				} else {
					d[i][j] = -1;
				}
			}
		}
		while (stq < enq) {
			auto v = st[stq++];
			for (int i = 0; i < 4; ++i) {
				auto nv = make_pair (v.first + dx[i], v.second + dy[i]);
				if (inside (nv.first, nv.second) && d[nv.first][nv.second] == -1 && s[nv.first][nv.second] != '#') {
					d[nv.first][nv.second] = d[v.first][v.second] + 1;
					st[enq++] = nv;
				}
			}
		}
*/
		int win = 0;
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (s[i][j] == 'T')
					win ^= calc (i, j, k);

		if (win)
			return "Alice";
		else
			return "Bob";
	}

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif