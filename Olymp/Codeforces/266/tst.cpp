#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,a,b;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(a*m>=b)
		printf("%d",n/m*b + min(b,a*(n%m)));
	else
		printf("%d",a*n);
return 0;}