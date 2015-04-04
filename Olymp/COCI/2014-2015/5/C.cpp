#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 1;
vector <int> vertical[N], horizontal[N], diagonal1[3 * N] /** \ **/, diagonal2[3 * N] /** /  **/;
int n, k, x, y;

inline void d (const int &x, const int &y) {
	int number = min (x - 1, y - 1);
	int check = 0;
	check = x - number;
	if (check == 1)
		diagonal1[y - number].push_back (number);
	else
		diagonal1[x - number + N - 1].push_back (number);
}

inline void d1 (const int &x, const int &y) {
	int number = min (x - 1, N - 1 - y);
	int check = 0;
	check = x - number;
	if (check == 1)
		diagonal2[y + number].push_back (number);
	else
		diagonal2[x - number + N - 1].push_back (number);
}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &x, &y);
		vertical[y].push_back (x);
		horizontal[x].push_back (y);
		d (x, y);
		d1 (x, y);
	}
	int ans = N;
	for (int i = 1; i < N; ++i) {
		sort (vertical[i].begin(), vertical[i].end());
		
	}
	for (int i = 1; i < N; ++i) {
		sort (horizontal[i].begin(), horizontal[i].end());
	}
	for (int i = 1; i < 3 * N; ++i) {
		sort (diagonal1[i].begin(), diagonal1[i].end());
	}
	for (int i = 1; i < 3 * N; ++i) {
		sort (diagonal2[i].begin(), diagonal2[i].end());
	}

	for (int i = 1; i < N; ++i) {
		for (int j = k - 1; j < vertical[i].size(); ++j)
			ans = min (ans, vertical[i][j] - vertical[i][j - k + 1] + 1);
	}
	for (int i = 1; i < N; ++i) {
		for (int j = k - 1; j < horizontal[i].size(); ++j)
			ans = min (ans, horizontal[i][j] - horizontal[i][j - k + 1] + 1);
	}
	for (int i = 1; i < 3 * N; ++i) {
		for (int j = k - 1; j < diagonal1[i].size(); ++j)
			ans = min (ans, diagonal1[i][j] - diagonal1[i][j - k + 1] + 1);
	}
	for (int i = 1; i < 3 * N; ++i) {
		for (int j = k - 1; j < diagonal2[i].size(); ++j)
			ans = min (ans, diagonal2[i][j] - diagonal2[i][j - k + 1] + 1);
	}
	if (ans == N)
		printf ("-1");
	else
		printf ("%d", ans);
	return 0;
}