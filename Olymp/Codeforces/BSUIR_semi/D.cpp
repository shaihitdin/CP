#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int a[2000001],n,k,i,x;
set<int> s;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=min(n,k);++i){
		s.insert(a[i]);
	}
	if(s.size()!=k){
		printf("0");
		return 0;
	}
	for(i=k+1;i<=n;++i){
		x=*s.begin();
		if(x+a[i]<=2*1000000)
			s.insert(x+a[i]);
	}
	printf("%d",*s.begin());
	return 0;
}