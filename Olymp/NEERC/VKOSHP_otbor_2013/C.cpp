#include<iostream>
#include<stdio.h>
using namespace std;
int n,v,fact[10],i,j,cnt;
int main(){
	freopen("cipher.in","r",stdin);
	freopen("cipher.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("1");
		return 0;
	}
	fact[1]=1;
	for(i=2;i<=n;++i){
		fact[i]=fact[i-1]*i;
	}
	printf("%d\n",fact[n]*2);
	printf("1 ");
	++cnt;
	v=1;
	for(i=1;;++i){
		for(j=1;j<n+i;++j){
			v=
		}
	}	
	return 0;
}