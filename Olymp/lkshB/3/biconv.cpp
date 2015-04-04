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
bool point[N*10],u[N*10];
int l[N*10],sz;
int ans[N*10],clrsz;
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
		  if(p==-1 && tin[v]<fup[to])
		    point[a[v][i].S]=1;
		  else if((p!=-1 && tin[v]<fup[to])){
		    point[a[v][i].S]=1;
		  }

		  fup[v]=min(fup[v],fup[to]);
		}
	}
}
void color(int v,int c,int p=-1){
	u[v]=1;
/*
	for(int i=1;i<=m;++i)
	   cerr<<ans[i]<<" ";
	   cerr<<"\n";
*/
	for(int i=0;i<a[v].size();++i){
		int to=a[v][i].F;
		if(to==p)
		 continue;
	     if
	}
}
void topsort(int v){
	u[v]=1;
	for(int i=0;i<a[v].size();++i){
		if(!u[a[v][i].F])
		 dfs(a[v][i].F);
	}
	l[++sz]=v;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i){
		  scanf("%d %d",&x,&y);
		  a[x].push_back(mkp(y,i));
		  a[y].push_back(mkp(x,i));
	}
	for(i=1;i<=n;++i){
	   if(!u[i]) topsort(i);
	}
	for(i=n;i>=1;--i)
	   if(!tin[l[i]]) dfs(i);
	memset(u,0,sizeof(u));
	for(i=1;i<=n;++i){
	   if(!u[l[i]]){
	     color(l[i],++clrsz);
	   }
	}
	printf("%d\n",clrsz);
	for(i=1;i<=m;++i)
	  printf("%d ",ans[i]);
return 0;}