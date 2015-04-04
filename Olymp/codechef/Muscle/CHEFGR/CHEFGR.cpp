#include<iostream>
#include<stdio.h>
using namespace std;
int t,n,m,mx,a[1000001],i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&t);
	++t;
	while(--t){
		scanf("%d%d",&n,&m);
		mx=0;
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		for(i=1;i<=n;++i){
			m-=(mx-a[i]);
		}
		if(m%n==0){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}