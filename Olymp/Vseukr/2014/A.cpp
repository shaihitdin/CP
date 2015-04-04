#include<iostream>
#include<stdio.h>
using namespace std;
int a[100003],b[100003],pos[100003],u[100003],ans,n,i,j;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		pos[a[i]]=i;	
	}
	for(i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;++i)	u[i]=1;
	for(i=1;i<=n;++i){
		if(pos[b[i-1]]+1==pos[b[i]])	u[pos[b[i-1]]]=0;	
	}
	for(i=1;i<=n;++i){
		ans+=u[i];
//		cerr<<u[i];
	}
	printf("%d",ans);
return 0;
}