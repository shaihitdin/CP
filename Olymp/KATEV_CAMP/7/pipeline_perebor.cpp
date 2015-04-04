#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define mkp make_pair
#define F first
#define S second
bool u[20001],d[100001];
vector<pair<int, int> > g[2001];
vector<int> ans;
int n, m, k, x, y, cnt[2001], i, mx, mxn, j;
int main(){
	freopen("pipeline.in","r",stdin);
	freopen("pipeline.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(mkp(y,i));
		g[y].push_back(mkp(x,i));
		++cnt[x];
		++cnt[y];

	}
	for(i=1;i<=k;++i){
		mx=-1;
		mxn=0;
		for(j=1;j<=n;++j){
			if(mx<cnt[j] && !u[j]){
				mx=cnt[j];
				mxn=j;
			}
		}
		
		u[mxn]=1;
		for(j=0;j<g[mxn].size();++j){
			if(!d[g[mxn][j].S]){
				--cnt[mxn];
				--cnt[g[mxn][j].F];
				d[g[mxn][j].S]=1;
			}
		}
		if(mxn!=0){
			ans.push_back(mxn);
		}
		else{
			ans.push_back(1);
		}
	}
	for(i=1;i<=n;++i){
		if(cnt[i]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(i=0;i<ans.size();++i){
		printf("%d ",ans[i]);
	}
	return 0;
}