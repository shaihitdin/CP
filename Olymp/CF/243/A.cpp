#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,i,x,mx,s,sum;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>s;
	for(i=1;i<=n;++i){
	   cin>>x;
	   mx=max(mx,x);
	   sum+=x;
	}
	cout<<((sum-mx<=s)?"YES":"NO");
return 0;}