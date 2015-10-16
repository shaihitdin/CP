#include<iostream>
#include<stdio.h>
using namespace std;
int n,p,x,i;
int u[10001];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d %d",&p,&n);
	for(i=1;i<=n;++i){
	   scanf("%d",&x);
	   x=x%p;
	   if(u[x]){
	    printf("%d",i);
	    return 0;
	   }
	   u[x]=1;
	}
	printf("-1");
return 0;}