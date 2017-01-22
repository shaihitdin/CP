/// izizi

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e6 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int n, m;

inline bool inside (int x, int y) {
	return 1 <= x && 1 <= y && x <= n && y <= n;
}

int dx[] = {-2, -2, -1, +1};
int dy[] = {+1, -1, -2, -2};

inline bool losing_position (int x, int y) {
	if ((x % 4 == 1 || x % 4 == 2) && (y % 4 == 1 || y % 4 == 2))
		return 1;
	if (x == n && y == n && x % 4 == 0)
		return 1;
	/*
	for (int j = 0; j < 4; ++j)
		if (inside (x + dx[j], y + dy[j]) && losing_position (x + dx[j], y + dy[j], depth + 1))
			return 0;
	return 1;
	*/
	return 0;
}

int movex[N], movey[N];

int main() {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
		
	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> m >> n;

	bool win = 1;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		if (losing_position (x, y))
			win = 0;
		int cnt = 0;
		for (int j = 0; j < 4; ++j)
			cnt += inside (x + dx[j], y + dy[j]);
		assert (cnt);
		for (int j = 0; j < 4; ++j)
			if (inside (x + dx[j], y + dy[j]) && losing_position (x + dx[j], y + dy[j]))
				movex[i] = x + dx[j], movey[i] = y + dy[j];
	}	

	if (!win) {
		cout << "NO";
		return 0;
	}	
	cout << "YES\n";

	for (int i = 1; i <= m; ++i)
		cout << movex[i] << " " << movey[i] << "\n";
	
	return 0;
}