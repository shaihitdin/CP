#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
long long n,i;
long long a[3*100001],sum,ans;
int main(){
	scanf("%I64d",&n);
	for(i=1;i<=n;++i)
		scanf("%I64d",&a[i]);
   	sort(a+1,a+n+1);
   	for(i=1;i<=n;++i){
   		sum+=a[i];
   	}
   	ans+=sum;
   	for(i=1;i<n;++i){
   		ans+=sum;
   		sum-=a[i];
   	}
   	printf("%I64d",ans);
return 0;
}