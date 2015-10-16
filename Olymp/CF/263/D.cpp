#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<long long> g[100001];
long long n,i,j,root,col[100001],ans,sz[100001];
void dfs(long long v){
	u[v]=1;
	for(int i=0;i<g[v].size();++i){
		if(!u[g[v][i]]){
			dfs(g[v][i]);
			ans*=sz[g[v][i]];			
		}
	}
	if(col[v]){
		sz[v]=1;
	}
	else{
		sz[v]
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d",&n);
	for(i=1;i<n;++i){
		scanf("%I64d",&x);
		++x;
		g[x].push_back(i+1);
		g[i+1].push_back(x);
	}
	for(i=1;i<=n;++i){
		scanf("%I64d",&col[i]);
		if(col[i])	root=i;
	}
	ans=1;
	dfs(root);
	printf("%I64d",ans);
return 0;
}