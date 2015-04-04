#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
vector<int> v[10001],ans;
bool a[10001][256],u[10001];
int x,n,m,k,from,to,i;
char y;
string s;
inline void dfs(int x,char color){
	u[x]=1;
	for(int i=0;i<v[x].size();++i){
		int to=v[x][i];
		if(a[to][color] && !u[to]){
			dfs(to,color);
		}
	}
}
int main(){
	freopen("kripke.in","r",stdin);
	freopen("kripke.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;++i){
		cin>>x;
		++x;
		while(--x){
			cin>>y;
			a[i][y]=1;
		}
	}
	for(i=1;i<=m;++i){
		cin>>from>>to;
		v[to].push_back(from);
	}
	cin>>s;
	char x1=s[2],x2=s[7];
	for(i=1;i<=n;++i){
		if(a[i][x1] && a[i][x2]){
			dfs(i,x1);
			dfs(i,x2);
			break;
		}
	}
	for(i=1;i<=n;++i){
		if(u[i] || u[i]){
			ans.push_back(i);
		}
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}