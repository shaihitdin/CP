#include<iostream>
#include<stdio.h>
using namespace std;
int a1,a2,a3,b1,b2,b3,n,ans;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
	ans=(a1+a2+a3)/5+((a1+a2+a3)%5>0?1:0);
	ans+=(b1+b2+b3)/10+((b1+b2+b3)%10>0?1:0);
	if(ans<=n)
	cout<<"YES";
	else
	cout<<"NO";
return 0;}