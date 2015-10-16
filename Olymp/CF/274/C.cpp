#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define F first
#define S second
int n,ans,i;
pair<int,int> a[10001];
bool cmp(pair<int,int> lhs, pair<int,int> rhs){
	if(lhs.F==rhs.F)
		return lhs.S<rhs.S;
	lhs.F<rhs.F;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&a[i].F,&a[i].S);
	}
	sort(a+1,a+n+1,&cmp);
	ans=a[i].S;
	for(i=2;i<=n;++i){
		if(a[i].S>=ans)	ans=a[i].S;
		else	ans=a[i].F;
	}
	printf("%d",ans);
	return 0;
}