#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N=20001;
int tin[N],fup[N],timer;
vector<pair<int,int> > v[N];
vector<int> ans;
int n,m,x,y,i;
void dfs(int a,int pe=-1){
	
	tin[a]=++timer;
	fup[a]=tin[a];
	for(int i=0;i<v[a].size();++i){
		if(pe==v[a][i].S)
		 continue;
		int to=v[a][i].F;
		 if(tin[to]){
		   fup[a]=min(fup[a],tin[to]);
		 }
		 else{
		   dfs(to,v[a][i].S);
		   if(tin[a]<fup[to])
		   	ans.push_back(v[a][i].S);
		   fup[a]=min(fup[a],fup[to]);		   
		 }
	}
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i){
		scanf("%d %d",&x,&y);
		v[y].push_back(mkp(x,i));
		v[x].push_back(mkp(y,i));
	}
	for(i=1;i<=n;++i){
	  dfs(i);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();++i)
	 printf("%d ",ans[i]);
return 0;}