#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 150001;
int cnt[N];
int p[N], c[N], cn[N], pn[N], i;
int n, m, st[N], st1[N], end1, res = 1, h[N], ans[N], res1 = 1, res2 = 1;
int s[N];
int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; ++i)
		scanf("%d", &s[i]);
	s[n++] = 0;
	for(i = 0; i < n; ++i) {
		++cnt[(int)s[i]];
	}
	for(i = 1; i < 11; ++i)
		cnt[i] += cnt[i-1];
	for(i = 0; i < n; ++i)
		p[--cnt[(int)s[i]]] = i;
	c[0] = 0;
	for(i = 1; i < n; ++i)
		if(s[p[i]] != s[p[i-1]])
			c[p[i]] = c[p[i-1]]+1;
		else
			c[p[i]] = c[p[i-1]];
	for(int k = 0; (1 << k) < n; ++k) {
		for(i = 0; i < (int)n; ++i)
			pn[i] = (p[i]-(1 << k)+(int)n)%n;
		
		for(i = 0; i < (int)n; ++i)
			cnt[i] = 0;
		for(i = 0; i < (int)n; ++i)
			++cnt[c[pn[i]]];
		for(i = 1; i < (int)n; ++i)
			cnt[i] += cnt[i-1];
		for(i = n-1; i >= 0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		for(i = 1; i < (int)n; ++i) {
			int x = p[i], y = p[i-1], k1 = 1 << k;
			if(c[x] != c[y] || c[(x+k1)%(int)n] != c[(y+k1)%(int)n])
				cn[p[i]] = cn[p[i-1]]+1;
			else
				cn[p[i]] = cn[p[i-1]];
		}
		for(i = 0; i < (int)n; ++i)
			c[i] = cn[i];
	}
	for(i = 0; i < n; ++i) {
		h[p[i]] = i;
	}
	for(i = 0; i < n; ++i) {
		if(h[i]+1 < n) {
			while((i+ans[h[i]] < n && p[h[i]+1]+ans[h[i]] < n)) {
				if(s[i+ans[h[i]]] == s[p[h[i]+1]+ans[h[i]]])
					++ans[h[i]];
				else
					break;
			}
			if(i + 1 < n)
				ans[h[i+1]] = max(0, ans[h[i]]-1);
		}
	}
	for(i = 0; i < n; ++i) {
		while(end1 > 0 && st[end1] > ans[i]) {
			if(res < (i-st1[end1]+1)*st[end1]) {
				res = (i-st1[end1]+1)*st[end1];
				res1 = ans[st1[end1]];
				res2 = st1[end1];
			}
			--end1;
		}
		st[++end1] = ans[i];
		st1[end1] = i;
	}
	while(end1 > 0) {
			if(res < (i-st1[end1]+1)*st[end1]) {
				res = (i-st1[end1]+1)*st[end1];
				res1 = ans[st1[end1]];
				res2 = st1[end1];
			}	
		--end1;
	}
	printf("%d\n%d\n", res, res1);
	for(i = 0; i < res1; ++i) {
		printf("%d ", s[p[res2]+i]);
	}
return 0;}