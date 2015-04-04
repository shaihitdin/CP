#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<pair<int,int> > a;
int x,y,z,n,m,k,i;        
vector
inline void dfs(int v,int col,int pe){
	u[v]=1;
	for(i=0;i<a[v].size();++i){
			dfs(
	}
}
int main(){
	freopen("metro.in","r",stdin);
	freopen("metro.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back(mkp(y,z));		
	}
	for(i=1;i<=n;++i){
		if(!u[i])
			dfs(i,0,0);
	}	
	return 0;
}