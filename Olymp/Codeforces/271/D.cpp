#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long t,k,d[100001],sum[100001],a,b,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d%I64d",&t,&k);
	for(i=1;i<k;++i){
		d[i]=1;
	}
	d[0]=1;
	for(i=k;i<=100000;++i){
		 d[i]=(d[i-1]+d[i-k]+1000000007*1ll)%1000000007*1ll;
	}
	for(i=1;i<=100000;++i){
		sum[i]=(sum[i-1]+d[i]+1000000007*1ll)%1000000007*1ll;
	}
	++t;
	while(--t){
		scanf("%I64d%I64d",&a,&b);
		printf("%I64d\n",(sum[b]-sum[a-1]+1000000007*1ll)%1000000007*1ll);
		cerr<<sum[b]<<" "<<sum[a-1]<<"\n";
	}
	return 0;
}