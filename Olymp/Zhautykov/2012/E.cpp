#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
int n, m, k;
int cycle_start, period, t;
inline bool inside (const int &x, const int &y) {
	return 0 < x && x < n && 0 < y && y < m;
}
map < vector <pair <int, pair <int, int> > >, int> mp;
vector <pair <int, pair <int, int> > > now;
inline void do_smth (pair <int, pair <int, int> > &temp) {
	if (temp.S.S == 1)
		++temp.F;
	if (temp.S.S == 2)
		++temp.S.F;
	if (temp.S.S == 3)
		--temp.F;
	if (temp.S.S == 4)
		--temp.S.F;
}
int cd[] = {0, 3, 4, 1, 2};
int u[101][101][5];
inline void print () {
	for (auto it : now) {
		printf ("%d %d %d\n", it.F, it.S.F, it.S.S);
	}
}
inline void check (const int &x, const int &y) {
	if (now[x].S.S == cd[now[y].S.S]) {
		int distx = abs (now[x].F - now[y].F);
		int disty = abs (now[x].S.F - now[y].S.F);
		if (distx == 0 && disty == 0) {
			now[x].S.S = cd[now[x].S.S];
			now[y].S.S = cd[now[y].S.S];
			return;
		}
		if (distx == 0 && disty == 1 && (now[x].S.S == 2 || now[y].S.S == 2))  {
			swap (now[x].S.F, now[y].S.F);
			now[x].S.S = cd[now[x].S.S];
			now[y].S.S = cd[now[y].S.S];
			return;
		}
		if (distx == 1 && disty == 0 && (now[x].S.S == 1 || now[y].S.S == 1))  {
			swap (now[x].F, now[y].F);
			now[x].S.S = cd[now[x].S.S];
			now[y].S.S = cd[now[y].S.S];
			return;
		}
	}
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d%d%d", &n, &m, &k, &t);
	for (int i = 0; i < k; ++i) {
		now.push_back (mkp (0, mkp (0, 0) ) );
		scanf ("%d%d%d", &now[i].F, &now[i].S.F, &now[i].S.S);
	}
	int cnt = 0;
	while (1) {
		if (cnt == t) {
			print();
			return 0;
		}
		int x = mp[now];
		if (x) {
			cycle_start = x;
			period = cnt - x - 3;
			break;
		}
		mp[now] = cnt;
		for (auto &it : now)
			do_smth (it);
		for (int i = 0; i < k; ++i)
			for (int j = i + 1; j < k; ++j)
				check (i, j);
		for (int i = 0; i < k; ++i)
			for (int j = i + 1; j < k; ++j)
				check (i, j);
		for (int i = 0; i < k; ++i)
			if (!inside (now[i].F, now[i].S.F))
				now[i].S.S = cd[now[i].S.S];				
		++cnt;
	}
	t %= (period);
	while (t) {
		for (auto &it : now)
			do_smth (it);
		int i = 0;
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				if (i != j)
					check (i, j);
		for (int i = 0; i < k; ++i)
			if (!inside (now[i].F, now[i].S.F))
				now[i].S.S = cd[now[i].S.S];
		--t;
	}
	print();
	return 0;
}