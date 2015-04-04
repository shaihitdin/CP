#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
const int N = 100001;
string s;
int cnt[N];
int p[N], c[N], cn[N], pn[N], i;
int main() {
	freopen("suffarray.in", "r", stdin);
	freopen("suffarray.out", "w", stdout);
	getline(cin, s);
	s += char(1);
	for(i = 0; i < (int)s.size(); ++i) {
		++cnt[(int)s[i]];
	}
	for(i = 1; i < 256; ++i)
		cnt[i] += cnt[i-1];
	for(i = 0; i < (int)s.size(); ++i)
		p[--cnt[(int)s[i]]] = i;
	c[0] = 0;
	for(i = 1; i < (int)s.size(); ++i)
		if(s[p[i]] != s[p[i-1]])
			c[p[i]] = c[p[i-1]]+1;
		else
			c[p[i]] = c[p[i-1]];
	for(int k = 0; (1 << k) < (int)s.size(); ++k) {
		for(i = 0; i < (int)s.size(); ++i)
			pn[i] = (p[i]-(1 << k)+(int)s.size())%s.size();
		
		for(i = 0; i < (int)s.size(); ++i)
			cnt[i] = 0;
		for(i = 0; i < (int)s.size(); ++i)
			++cnt[c[pn[i]]];
		for(i = 1; i < (int)s.size(); ++i)
			cnt[i] += cnt[i-1];
		for(i = s.size()-1; i >= 0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		for(i = 1; i < (int)s.size(); ++i) {
			int x = p[i], y = p[i-1], k1 = 1 << k;
			if(c[x] != c[y] || c[(x+k1)%(int)s.size()] != c[(y+k1)%(int)s.size()])
				cn[p[i]] = cn[p[i-1]]+1;
			else
				cn[p[i]] = cn[p[i-1]];
		}
		for(i = 0; i < (int)s.size(); ++i)
			c[i] = cn[i];
	}
	for(i = 1; i < (int)s.size(); ++i)
		cout << p[i]+1 << " ";
return 0;}