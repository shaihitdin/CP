#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
int n,i,x;
string q;
bool u[100001],type[100001];
char active[100001];
vector<int> a[100001],ans;
inline void dfs(int v){
	u[v]=1;
	for(int i=0;i<a[v].size();++i){
		if(!u[a[v][i]]){
			dfs(a[v][i]);
			if(active[a[v][i]]==1)	active[v]=2;
		}
	}                    
	if(active[v]!=2){
		active[v]=1;
	}
}
int main(){
	freopen("bureau.in","r",stdin);
	freopen("bureau.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>q;
		if(q=="declare"){
			type[i]=1;
		}
		else{
			cin>>x;
			a[x].push_back(i);
		}
	}
	for(i=1;i<=n;++i){
		if(type[i])	dfs(i);
	}
	for(i=1;i<=n;++i){
		if(active[i]==1){
			ans.push_back(i);		
		}
	}
	cout<<ans.size()<<"\n";
	for(i=0;i<ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}