#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
#define F first
#define S second
const int N = 6001;
int a[N], b[N], n1, n2, i, j, ans;
pair<int, int> c[N];
int priority[N];
int g[N][N], d[N/2+2][N/2+2];
int main() {
	freopen ("lcis.in", "r", stdin);
	freopen ("lcis.out", "w", stdout);
	scanf ("%d%d", &n1, &n2);
	for (i = 1; i <= n1; ++i)
		scanf("%d", &a[i]);
	for (i = 1; i <= n2; ++i)
		scanf("%d", &b[i]);
	for (i = 1; i <= n1; ++i) 
		c[i].F = a[i], c[i].S = i;
	for (i = 1; i <= n2; ++i)
		c[i + n1].F = b[i], c[i + n1].S = i + n1;
	sort (c + 1, c + n1 + n2 + 1);
	c[0].F = -1;
	for (i = 1; i <= n1 + n2; ++i) {
		if (c[i].F != c[i-1].F)
			priority[c[i].S] = i;
		else
			priority[c[i].S] = priority[c[i-1].S];
	}
	
	for (j = 1; j <= n1; ++j)
		g[n1][priority[j]] = -1;
	for (i = n1 - 1; i >= 1; --i) {
		for (j = 1; j <= n1; ++j) {
			g[i][priority[j]] = g[i+1][priority[j]];
		}
		g[i][priority[i+1]] = i + 1;
	}
/*
	for (i = 1; i <= n1; ++i) {
		for (j = 1; j <= n1; ++j) {
			cerr<<g[i][priority[j]]<<" ";
		}
		cerr<<"\n";
	}
*/
	for (i = 1; i <= n1; ++i) {
		for (j = 1; j <= n2; ++j) {
			if(b[j] == a[i])
				d[i][j] = 1;
		}
	}
	
	for (i = 1; i <= n1; ++i) {
		for (j = 1; j <= n2; ++j) {
			if(i != 0) {
//				cerr<<d[i][j]<<" ";
				ans = max(ans, d[i][j]);
			}
			d[i][j + 1] = max(d[i][j], d[i][j + 1]);
			if (b[j + 1] > a[i]) {
				int k = g[i][priority[n1 + j + 1]];
				if(k == -1 || k == 0) continue;
				d[k][j + 1] = max(d[k][j + 1], d[i][j] + 1);
			}
		}
//		cerr<<"\n";
	}
	printf("%d", ans);
	return 0;
}