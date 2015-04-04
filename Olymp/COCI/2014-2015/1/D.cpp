#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int N=500001;
int n,ans,i,x,v1,v2,ans1,ans2,e[N];
vector<int> r_e[N];
bool banned[N],u[N];
inline void dfs(int v,int p){
	u[v]=1;
	int banned_num=0;
	for(int i=0;i<r_e[v].size();++i){
		int to=r_e[v][i];
		if(to==p){
			v1=v;
			v2=to;
			continue;
		}
		if(!u[to])
			dfs(to,p);
		if(banned[to])
			++banned_num;
	}	
	if(r_e[v].size()-banned_num!=0)
		banned[v]=1;
	return;
}
inline void dfs1(int v,int p){
	u[v]=1;
	int banned_num=0;
	for(int i=0;i<r_e[v].size();++i){
		int to=r_e[v][i];
		if(!u[to])
			dfs(to,p);
		if(banned[to])
			++banned_num;
	}	
	if(r_e[v].size()-banned_num!=0)
		banned[v]=1;
	return;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		r_e[x].push_back(i);
		e[i]=x;
	}
	for(i=1;i<=n;++i){
		if(e[e[i]]==i){
			v1=i;
			v2=e[i];
		}
	}
	if(v1!=0){
		//ban 1
		memset(banned,0,sizeof(banned));
		memset(u,0,sizeof(u));
		banned[v1]=1;
		u[v1]=1;
		for(i=1;i<=n;++i){
			if(v1!=i && !u[i])
				dfs1(i,0);	
		}
		for(i=1;i<=n;++i){
			if(!banned[i]){
				++ans1;
			}
		}
		//ban 2
		memset(banned,0,sizeof(banned));
		memset(u,0,sizeof(u));
		banned[v2]=1;
		u[v2]=1;
		for(i=1;i<=n;++i){
			if(v2!=i && !u[i])
				dfs1(i,0);	
		}
		for(i=1;i<=n;++i){
			if(!banned[i]){
				++ans2;
			}
		}
		ans=max(ans1,ans2);
		printf("%d",ans);
		return 0;
	}

	for(i=1;i<=n;++i){
		if(!u[i])
			dfs(i,0);	
	}
	for(i=1;i<=n;++i){
		if(!banned[i]){
			++ans;
		}
	}
	printf("%d",ans);
	return 0;
}