#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
const int N=3001;
char u[N];
int l[N],sz,n,m,x,y,i;
vector<int> g[N],g_rev[N];
int color[N],clrsz;
vector <int> ans;
bool flag[N];
inline void dfs1(int x){
	u[x]=1;
	for(int i=0;i<g[x].size();++i){
	  if(!u[g[x][i]])
	    dfs1(g[x][i]);
	}
	l[++sz]=x;
}
inline void dfs2(int x){
	color[x]=clrsz;
	for(int i=0;i<g_rev[x].size();++i){
	   if(!color[g_rev[x][i]])
	     dfs2(g_rev[x][i]);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d\n%d",&n,&m);
	for(i=1;i<=m;++i){
	  scanf("%d %d",&x,&y);
	  g[x].push_back(y);
	  g_rev[y].push_back(x);
	}
	for(i=1;i<=n;++i){
	  if(!u[i]) dfs1(i);
	}
	for(int j=n;j>=1;--j){
	  if(!color[l[j]]) ++clrsz,dfs2(l[j]);
	}
	for(i=1;i<=n;++i)
	 for(int j=0;j<g[i].size();++j){
	    if(color[i]!=color[g[i][j]])
	      flag[color[i]]=1;
	 }
	for(i=1;i<=n;++i)
	  if(!flag[color[i]]) ans.push_back (i), flag[color[i]]=1;
	
	printf ("%d\n", ans.size ());
	for (auto v : ans)
		printf ("%d ", v);
	return 0;
}