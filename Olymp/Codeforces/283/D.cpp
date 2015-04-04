#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N = 1000001;    
int n, nn, a[N];
int cnt[N];
int g[5];
int st[5];	
vector <pair <int, int> > v;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	nn = cnt[a[n]];
	for (int i = 1; i <= nn; ++i) {
		for 
	}
	sort (v.begin(), v.end(), cmp);
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].F << " " << v[i].S << "\n";
	}
	return 0;
}