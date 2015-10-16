#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int l,r,a[100001],n,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&l,&r);
	n=l+r+1;
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	cout<<"YES\n";
	for(i=1;i<=r;++i){
		cout<<a[i]<<" R ";
	}
	for(i=n;i>n-l;--i){
		cout<<a[i]<<" L ";
	}
	cout<<a[n-l];
	return 0;
}