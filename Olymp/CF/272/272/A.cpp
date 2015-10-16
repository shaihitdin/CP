#include<iostream>
#include<stdio.h>
using namespace std;
int n,k,i,ans,tmp;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(i=(n/2)+(n&1);i<=n;++i){
		if(i%k==0){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}