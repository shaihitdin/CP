#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stdio.h>
using namespace std;
char a[21][21];
bool u[(1<<19) + 2];
int x, y, n, m, i, j, res, ans, cnt;
inline bool bit(int mask, int t) {
	return (mask & (1 << t) );
}
int q[(1<<19) + 2], stq, endq;
int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	cin >> n;
	for(i = 1; i <= n; ++i) {
		for(j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	q[++endq]=0;
	while(endq != stq) {
		x = q[++stq];
		cnt = 0;
		for(i = 1; i <= n; ++i) {
			if(bit(x, i)) ++cnt;
		}
		if(ans < cnt) {
			ans = cnt;
		}
		for(i = 1; i <= n; ++i) {
			for(j = 1; j <= n; ++j) {
				if(!bit(x, i) && !bit(x, j) && a[i][j] == 'Y' && !u[(x|1 << i)|1 << j]) {
					u[((x | 1 << i) | 1 << j)]=1;
					q[++endq]=((x | 1 << i) | 1 << j);
				}
			}
		}
	}
	cout << ans;
return 0;}