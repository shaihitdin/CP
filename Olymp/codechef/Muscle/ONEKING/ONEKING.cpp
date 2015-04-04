#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stdio.h>
using namespace std;
const int N = 2001, M = 1e5 + 1;
set <int> id;
vector <int> increase[N], decrease[N];
int t, n, x[M], y[M];
bool banned[M];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		scanf ("%d", &n);
		for (int i = 0; i < M; ++i)
			banned[i] = 0;
		for (int i = 0; i < N; ++i)
			increase[i].clear(), decrease[i].clear();
		for (int i = 1; i <= n; ++i) {
			scanf ("%d%d", &x[i], &y[i]);
			increase[x[i]].push_back(i);
			decrease[y[i]].push_back(i);
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			int temp = 0;
			for (auto it : increase[i])
				id.insert (it);
			for (auto it : decrease[i])
				if (!banned[it])
					++temp;
			if (temp) {
				for (auto it : id)
					banned[it] = 1;
				id.clear();
				++ans;
			}
			for (auto it : decrease[i])
				id.erase (it);
		}
		printf ("%d\n", ans);
	}
	return 0;
}