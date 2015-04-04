#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N=100001;
bool cycle[N];
int par_edge[N],p[N];
vector<pair<int,int> > g[N];
int x,y,n,m,i,ans;
inline void cycle_found(int to,int from){
	while(from!=to && cycle[par_edge[from]]!=1){
		cycle[par_edge[from]]=1;
		from=p[from];
	}
}
char u[N];
inline void cycle_dfs(int v,int p_e,int pr){
	u[v]=2;
	par_edge[v]=p_e;
	p[v]=pr;
	for(int i=0;i<g[v].size();++i){
		int to=g[v][i].F,id=g[v][i].S;
		if(id==p_e)	continue;
		if(u[to]==2){
			cycle[id]=1;
			cycle_found(to,v);
		}
		if(u[to]==0){
			cycle_dfs(to,id,v);
		}		
	}
	u[v]=1;
}
inline void dfs(int v,int p_e,int tmp){
	u[v]=1;
	ans+=max(0,tmp-1);
	for(int i=0;i<g[v].size();++i){
		int to=g[v][i].F,id=g[v][i].S;
		if(id==p_e)	continue;
		if(u[to]==0){
			if(cycle[id]==1)
				dfs(to,id,0);
			else
				dfs(to,id,tmp+1);
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(mkp(y,i));
		g[y].push_back(mkp(x,i));
	}
	for(i=1;i<=n;++i){
		if(!u[i]){
			cycle_dfs(i,0,0);
		}
	}
	memset(u,0,sizeof(u));
	for(i=1;i<=n;++i){
		if(!u[i]){
			dfs(i,0,0);
		}
	}
	printf("%d",ans);
	return 0;
}