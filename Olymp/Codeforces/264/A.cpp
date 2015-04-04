#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,a[2001],i,j,s,x,y,ans=-1;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&s);
	s*=100;
	for(i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		if(s-(x*100+y)>=0)
			ans=max(ans,(s-(x*100+y))%100);
	}
	printf("%d",ans);
return 0;
}