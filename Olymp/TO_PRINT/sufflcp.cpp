#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 100001;
string s;
int n, i, a[N], h[N], ans[N], p[N];
int main() {
	freopen("sufflcp.in", "r", stdin);
	freopen("sufflcp.out", "w", stdout);
	cin >> n;
	cin >> s;
	for(i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
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
			if(i +1 < n)
			ans[h[i+1]] = max(0, ans[h[i]]-1);
		}

	}
	for(i = 0; i < n-1; ++i)
		cout << ans[i] << " ";
return 0;}