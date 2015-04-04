#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long col[4], tmp_col[4], ans; 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin >> col[1] >> col[2] >> col[3];
	sort(col+1,col+4);
	tmp_col[1] = col[3]-col[1];
	tmp_col[2] = col[2]-col[1];
	ans += min(tmp_col[1]/2,tmp_col[2]);
	ans += min((tmp_col[2]-ans)/2,tmp_col[1]-(ans*2));
	ans += col[1];
	cout << ans;
	return 0;
}