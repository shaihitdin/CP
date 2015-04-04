#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
const int N=100001;
vector<int> a[N];
char u[N];
int sz,l[N],n,m,x,y,i;
inline void dfs(int v){
	u[v]=2;
	for(int i=0;i<a[v].size();++i){
		if(u[a[v][i]]==2){
		  printf("-1");
		  exit(0);
		}
		if(u[a[v][i]]==0)
		  dfs(a[v][i]);
	}
	u[v]=1;
	l[++sz]=v;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i){
	 scanf("%d %d",&x,&y);
	 a[x].push_back(y);
	}
	for(i=1;i<=n;++i){
		if(u[i]==0) dfs(i);
	}
	for(i=sz;i>=1;--i)
	  printf("%d ",l[i]);
return 0;}