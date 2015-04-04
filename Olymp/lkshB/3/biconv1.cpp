#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define mkp make_pair
#define S second
#define F first
const int N=20001;
int tin[N],fup[N],timer;
int n,m,i,x,y;
vector<pair<int,int> > a[N];
bool point[N*10],u[N];
int ans[N*10],clrsz;
int xpos[N*10],ypos[N*10];
void dfs(int v,int p=-1){
	tin[v]=++timer;
	fup[v]=timer;
	int children=0;
	for(int i=0;i<a[v].size();++i){
		int to=a[v][i].F;
		if(p==to)
		 continue;
		if(tin[to]) fup[v]=min(fup[v],tin[to]);
		else{
		  dfs(to,v);
		  ++children;
		  if(tin[v]<=fup[to]){
		    point[v]=1;
		  }
		  fup[v]=min(fup[v],fup[to]);
		}
	}
	if(p==-1 && children>1)
	  point[v]=1;
	else if(p==-1)
	  point[v]=0;
}

void color (int v, int c, int p) {
	u[v] = 1;
	for (int i = 0; i < a[v].size(); ++i) {
		int to = a[v][i].F;
	    if (!u[to]) {
	    	if (fup[to] >= tin[v]) {
	     		ans[a[v][i].S] = ++clrsz, color (to, clrsz, v);
	     	}
	        else {
		    	ans[a[v][i].S] = c, color (to, c, v);
		    }
		}
		else
			if (tin[to] <= tin[v] || ans[a[v][i].S]==0) ans[a[v][i].S]=c;
	}
}

int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i){
		  scanf("%d %d",&x,&y);
		  a[x].push_back(mkp(y,i));
		  a[y].push_back(mkp(x,i));
		  xpos[i]=x;
		  ypos[i]=y;
	}
	for(i=1;i<=n;++i)
	   if(!tin[i]) dfs(i);

	memset(u,0,sizeof(u));

	for(i=1;i<=n;++i){
	   if(!u[i]){
	     color(i,0,-1);
	   }
	}
	printf ("%d\n", clrsz);
	for (i = 1; i <= m; ++i)
		printf ("%d ", ans[i]);
	return 0;
}