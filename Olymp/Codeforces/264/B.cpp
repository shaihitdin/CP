#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,a[100001],i,j,ans=-1;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		ans=max(ans,a[i]);
	}
	printf("%d",ans);
return 0;
}