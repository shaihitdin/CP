#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int N=100001;

struct segtree{
	int top,n;
	vector<int> ind,t;
	void build(){
	     n=ind.size();
	     t.resize(n*2);
	}
	void change(int i){
	 --i;

	}
	int get(int l,int r){
	  --l;
	  --r;
	  int tmp=0;
	  for(l+=n,r+=n; l<=r;l/=2,r/=2){
	     if(l&1) tmp=max(tmp,t[l++]);
	     if(!(r&1)) tmp=max(tmp,t[r--]);
	  }
	  return tmp;
	}
};
segtree t[N],*ti[N];
vector<int> g[N];
int sz[N],dep[N],p[N];
int n,i,t_counter,timer;
void dfs1(int v,int pr,int d){
	dep[v]=d;
	sz[v]=1;
	for(int j=0;j<g[v].size();++j){
	    if(g[v][j]!=pr)
	     dfs1(g[v][j],v,d+1); sz[v]+=sz[g[v][j]];
	}
return ;}

void dfs2(int v,int pr,int t_id){
     p[v]=pr;
	if(t_id==-1){
	   t_id=++t_counter; t[t_counter].top=v;
	}
	ti[v]=&t[t_id];
	t[t_id].ind.pb(v);
	int mxsz=0,mxid;	
	for(int j=0;j<g[v].size();++j){
		if(g[v][j]!=pr && mxsz<sz[g[v][j]])
		    mxsz=g[v][j],mxid=j;
	}
	if(!mxsz){
	///end
	 return ;
	}
	for(int j=0;j<g[v].size();++j)
	   if(j!=mxid && g[v][j]!=pr)
	      dfs2(g[v][j],v,-1);
	dfs2(g[v][mxid],v,t_id);
}
int main(){
     freopen("in","r",stdin);
     freopen("out","w",stdout);
        scanf("%d",&n);
        while(--n){
            scanf("%d %d",&x,&y);
             g[x].push_back(y);
             g[y].push_back(x);
        }
        dfs1(1,0,1);
        dfs2(1,0,-1);
        while(tn--)
         t[tn].build();
        scanf("%d",&m);
        while(m--){
          char q;
             scanf("\n%c %d",&q,&x);
             if(q=='I'){
             }
             else{
                scanf("%d",&y);
             }
        }
return 0;}