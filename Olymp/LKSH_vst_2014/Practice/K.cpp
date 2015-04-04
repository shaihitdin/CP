#include<stdio.h> 
#include<vector>
using namespace std;
#define NAME "edges."
#define mkp make_pair
#define F first
#define S second
const int N=200001;
vector<pair<int,int > > g[N];
bool u[N],b[N];
int n,m,x,y;
int tin[N],fup[N],s[N],t,t1,cnt[N],ans;
void dfs(int v,int pid){
     u[v]=1;
     fup[v]=tin[v]=++t;
     int to,id;
     for(int i=0;i<g[v].size();++i){
         to=g[v][i].F;
         id=g[v][i].S;
	    if(id==pid)
	     continue;
	    if(u[to])
	     fup[v]=min(fup[v],tin[to]);
	    else{
	     dfs(to,id);
	     fup[v]=min(fup[v],fup[to]);
	     if(fup[to]>tin[v]) b[id]=1;
	    }
     }
}
void dfs1(int v){
	int to,id;
    for(int j=0;j<g[v].size();++j){
       id=g[v][j].S;
       to=g[v][j].F;
       if(b[id])
        ++cnt[s[v]];
       else if(!s[to]){
         s[to]=s[v];
         dfs1(to);
       }
    }
}
int main(){
	freopen(NAME"in","r",stdin);
	freopen(NAME"out","w",stdout);
		scanf("%d %d",&n,&m);

		for(int i=1;i<=m;++i){
		   scanf("%d %d",&x,&y);
		    g[x].push_back(mkp(y,i));
		    g[y].push_back(mkp(x,i));
		}
		dfs(1,0);
		for(int i=1;i<=n;++i){
		    if(!s[i]){
		     s[i]=++t1;
		     dfs1(i);
		    }
		}
		for(int i=1;i<=n;++i)
		  if(cnt[i]==1)
		   ++ans;
		 printf("%d",(ans/2 + (ans&1)));
return 0;}