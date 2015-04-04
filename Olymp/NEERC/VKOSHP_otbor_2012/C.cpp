#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int N=100001;
int u[N],pr[N],n,m,i,x,y;
long long ans=1;
vector<int> a[N];
inline void find_cycle(int v1,int v2){
	long long tmp_len=0;
	for(int i=v1;i!=v2;i=pr[i]){
//		cerr<<i<<" "<<v2<<" OK ";
		++tmp_len;
	}
	++tmp_len;
	ans=(ans*tmp_len)%1000000007;
	return;
}
inline void dfs(int v,int p){
	u[v]=2;
	pr[v]=p;
	for(int i=0;i<a[v].size();++i){
			if(a[v][i]==p){
				continue;
			}
			if(u[a[v][i]]==2){
				find_cycle(v,a[v][i]);
			}
			if(u[a[v][i]]==0){
				dfs(a[v][i],v);
			}
	}
	u[v]=1;
}
int main(){
	freopen("fortification.in","r",stdin);
	freopen("fortification.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(i=1;i<=n;++i){
		if(u[i]==0)
			dfs(i,0);
	}
	printf("%I64d",ans);
	return 0;
}