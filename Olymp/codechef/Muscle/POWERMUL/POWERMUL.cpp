#include<iostream>
#include<stdio.h>
using namespace std;
#ifdef _WIN32
	#define ll "%lld"
#else
	#define ll "%I64d"
#endif
long long n,m,t,q,i,r,a[100001];
inline long long bin_pow(long long x,long long p){
	if(p==0)
		return 1;
	if(p&1){
		return (bin_pow(x,p-1)*x)%m;
	}
	else{
		long long b=bin_pow(x,p/2);
		return (b*b)%m;
	}
}
inline long long modulo_div(long long x,long long y){
	if(y==0)
		return 0;
	x=x%(m*y);
	return x/y;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf(ll,&t);
	++t;
	while(--t){
		scanf(ll ll ll,&n,&m,&q);
		a[0]=(1)%m;
		for(i=1;i<=n;++i){
			a[i]=(a[i-1]*bin_pow(i,i))%m;
			cerr<<a[i]<<" ";
		}
		for(i=1;i<=q;++i){
			scanf(ll,&r);
			if(m==1){
				printf("0\n");
			}
			printf(ll "\n",modulo_div(a[n],(a[r]*a[n-r])%m));
		}
	}
	return 0;
}