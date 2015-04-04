#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[1000001],i,ans;
int main(){
	freopen("suffixgame.in","r",stdin);
	freopen("suffixgame.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(i=n;i>1;--i){
		ans+=(a[i]-a[i-1]-1);
	}
	ans+=(a[i]-1);
	if(ans&1){
		printf("First");
	}
	else{
		printf("Second");
	}
return 0;}