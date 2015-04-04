#include<iostream>
#include<stdio.h>
using namespace std;
long long n,m,t;
int main(){
		scanf("%lld",&t);
		while(t--){
		  scanf("%lld %lld",&n,&m);
		  if(n==1 & m==1)
		     printf("0/1\n");
		  else if(n&1 & m&1)
		  	printf("%lld/%lld\n",m*n/2,n*m);
		  else
		     printf("1/2\n");
		}
return 0;}