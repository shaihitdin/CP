#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[3];
int	num[3];
int cnt[3];
int i,n,x;
int ans[100100];
int main(){
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	scanf("%d",&n);
	
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		++cnt[x%3];
		v[x%3].push_back(x);
	}
	if(cnt[1]+cnt[2]+1<cnt[0] || (cnt[0]==0 && !(cnt[1]==n || cnt[2]==n)) ){
		printf("impossible");
		return 0;
	}
	i=1;
	if(cnt[1]+cnt[2]+1==cnt[0]){
		ans[1]=0;
		++i;
		--cnt[0];
	}
	for(;i<=n && cnt[1]!=0;++i){
		ans[i]=1;
		--cnt[1];
		if(cnt[0]>1 && cnt[1]!=0){
			++i;
			ans[i]=0;
			--cnt[0];	
		}
	}
	if(ans[i-1]==0 || cnt[0]!=0){
		ans[i]=0;
		--cnt[0];
		if(i!=1)
			++i;
	}
	for(;i<=n;++i){
		ans[i]=2;
		--cnt[2];
		if(cnt[0]>0 && cnt[2]!=0){
			++i;
			ans[i]=0;
			--cnt[0];	
		}		
	}
	for(i=1;i<=n;++i){
		cout<<v[ans[i]][num[ans[i]]]<<" ";	
		++num[ans[i]];
	}
return 0;
}