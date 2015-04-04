#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,m; 
inline long long get_ans(long long n){
	return n*(n-1)/2;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	if(m>=n){
		cout<<0<<" "<<0;
		return 0;
	}
	cout<<(get_ans(n/m+1)*(n%m))+(get_ans(n/m)*(m-(n%m)))<<" "<<get_ans(n-(m-1));
	return 0;
}