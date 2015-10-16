#include<iostream>
#include<stdio.h>
using namespace std;
const int N=101;
int a[N],i,n,m,left1,ans;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>a[i];
	}
	for(i=1;i<=n;++i){
	    if(left1<a[i]){
	     left1=m,++ans;
	     }
	     left1-=a[i];
	}
	cout<<ans;
return 0;}