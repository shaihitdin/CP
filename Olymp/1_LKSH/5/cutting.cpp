#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
const int K = 150001;
int silly_thing1, silly_thing2;
int n, m, k, i;
int x[K], y[K];
string s[K];
vector<string> ans;
int p[K];
int get(int v) {
	if (p[v] == v)
		return v;
	return p[v] = get(p[v]);
}
void Merge(int x, int y) {
	x = get(x);
	y = get(y);
	if(rand()&1) 
		p[x] = y;
	else 
		p[y] = x;
}
int main() {
	freopen("cutting.in", "r", stdin);
	freopen("cutting.out", "w", stdout);
	ios_base :: sync_with_stdio(false);
	srand(time(0));
	cin >> n >> m >> k;
	for(i = 1; i <= n; ++i)	p[i]=i;
	for(i = 1; i <= m; ++i) {
		cin >> silly_thing1 >> silly_thing2;
	}
	for(i = 1; i <= k; ++i) {
		cin >> s[i] >> x[i] >> y[i];
	}
	for(i = k; i >= 1; --i) {
		if(s[i] == "cut") {
			Merge(x[i], y[i]);
		} else {
			x[i] = get(x[i]);
			y[i] = get(y[i]);
			if(x[i] == y[i]) 
				ans.push_back("YES\n");
			else 
				ans.push_back("NO\n");
		}
	}
	for(i = ans.size()-1; i >= 0; --i)
		cout << ans[i];
return 0;}