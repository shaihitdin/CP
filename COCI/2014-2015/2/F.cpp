#include<iostream>
#include<stdio.h>
using namespace std;
const long long inf=10000000000001,mod=10000000000;
long long mx[500001],mn[500001],len[500001],n,a[500001],sum,i,j;
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		mn[i]=inf;
	}
	for(i=1;i<=n;++i){
		for(j=i;j>=1;--j){
			++len[j];
			mx[j]=max(mx[j],a[i]);
			mn[j]=min(mn[j],a[i]);
			sum=(sum+(len[j]*((mx[j]*mn[j])%mod)))%mod;
		}
	}
	printf("%lld",sum);
	return 0;
}