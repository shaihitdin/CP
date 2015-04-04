#include<iostream>
#include<stdio.h>
using namespace std;
int l,l1,n,x,i,cnt[1000002],ans[1000002],it;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		++cnt[x];
	}     
	while(it!=n){
		++it;
		if(it&1){
			while(cnt[l]==0 && l<=1000000)	++l;
			if(cnt[l]==0){
				printf("-1");
				return 0;
			}
			ans[it]=l;
			--cnt[l];
		}
		else{
			l1=max(l1,l+1);
			while(cnt[l1]==0 && l1<=1000000)	++l1;
			if(cnt[l1]==0){
				printf("-1");
				return 0;
			}
			ans[it]=l1;
			--cnt[l1];
		}
		if(ans[it]==ans[it-1])
			swap(ans[it-1],ans[it-2]);
	}
	if(it==n){
		for(i=1;i<=n;++i){
			printf("%d ",ans[i]);
		}
	}
	else{
		printf("-1");
	}
	return 0;
}