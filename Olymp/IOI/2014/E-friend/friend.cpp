#include "grader.h"
#include <bits/stdc++.h>

inline int get_p (const int &v) {
	return v == p[v] ? v : p[v] = get_p (p[v]);
}

inline void dfs (const int &v) {
	for (auto to : g[v]) {
		dfs (to);
	}
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (auto to : g[v]) {
		
	}
}

int findSample(int n, int confidence[], int host[], int protocol[]) {
	for (int i = 0; i < n; ++i)
		p[i] = i;
	
	for (int i = 1; i < n; ++i) {
		host[i] = get_p (i);
		if (protocol[i] == 0) {
			g[host[i]].emplace_back (i);
			flag[i] = 0;
		} else if (protocol[i] == 1) {
			p[i] = host[i];
		} else {
			g[host[i]].emplace_back (i)
			flag[i] = 1;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		confidence[get_p (i)] = max (confidence[get_p (i)], confidence[i]);
	}
	
	dfs (0);
	
	return max (d[0][0][0], max (d[0][0][1], max (d[0][1][0], d[0][1][1])));
}
