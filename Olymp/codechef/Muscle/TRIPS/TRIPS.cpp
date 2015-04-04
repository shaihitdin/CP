#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
const int N=100001;
vector<int> a[N];
int lvl[N],x,y,z,i,p,m,n;
inline void dfs(int v,int p){
	lvl[v]=lvl[p]+1;
	for(int i=0;i<a[v].size();++i){
		if(a[v][i]!=p)	dfs(a[v][i],v);
	}
	return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	scanf("%d",&m);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&p);
		printf("%d\n",abs(lvl[x]-lvl[y]));
	}
	return 0;
}