#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100001;

long long pal1[N], pal2[N], i, l, r, n, m;
long long s[N];
vector<long long> ans;
int main() {
	freopen("cubes.in", "r", stdin);
	freopen("cubes.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		cin >> s[i];
	}
	/*
	for (i = 0, l = 0, r = -1; i < n; ++i) {
		int pal = (i > r ? 0 : min(pal1[l + r - i], r - i)) + 1;
		while(i - pal >= 0 && i + pal < n && 
		s[i + pal] == s[i - pal]) ++pal;
		pal1[i] = --pal;
		if(i + pal > r)
			l = i - pal, r = i + pal;
		cerr<<pal1[i]<<" ";
	}
	cerr<<"\n";
	*/
	for (i = 0, l = 0, r = -1; i < n; ++i) {
		int pal = (i > r ? 0 : min(pal2[l + r - i + 1], r - i + 1)) + 1;
		while(i - pal >= 0 && i + pal - 1 < n && 
		s[i + pal - 1] == s[i - pal]) ++pal;
		pal2[i] = --pal;
		if(i + pal - 1 > r)
			l = i - pal, r = i + pal - 1;
		if(i - pal2[i] == 0) {
			ans.push_back(n-i);
		}
	}
	for(i = ans.size() - 1; i >= 0 ; --i) {
		cout << ans[i] << " ";
	}
	return 0;
}