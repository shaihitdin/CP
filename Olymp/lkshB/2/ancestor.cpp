#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int N=100001;
int tin[N],tout[N],timer,n,i,m,x,y;
vector<int> v[N];
void dfs(int x){
  tin[x]=++timer;
  for(int i=0;i<v[x].size();++i){
  	dfs(v[x][i]);
  }
  tout[x]=++timer;
}
bool ans(int x,int y){
  return ((tin[x]<tin[y]) & (tout[x]>tout[y]));
}
int main(){
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		v[x].push_back(i);
	}
	dfs(0);
	scanf("%d",&m);
	for(i=1;i<=m;++i){
	  scanf("%d %d",&x,&y);
       if(ans(x,y))
        printf("1\n");
       else
        printf("0\n");
	}
return 0;}