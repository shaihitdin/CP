#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<string.h>
#include <assert.h>
using namespace std;
const int N=1001;
vector<int> v[N],ans;
int u[N],av[N],num;
string s[N];
int ch[N],j,i,n;
inline void dfs(int a){
	if(u[a]==1){
		return;
	}
	if(u[a]==2){
		cout<<"No";
		exit(0);
	}
	u[a]=2;
	for(int i=0;i<v[a].size();++i){
		dfs(v[a][i]);
	}
	u[a]=1;
	ans.push_back(a);
}
int main(){
	freopen("tiv.in","r",stdin);
	freopen("tiv.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>s[i];
	}
	for(i=0;i<=n;++i){
		string t="";
		assert(s[i].size()<=10);
		for(j=0;s[i].size()+j<=10;++j){
			t+='k';
		}
		s[i]=t+s[i];
	}
	for(i=1;i<=n;++i){
		for(j=0;j<s[i].size() && s[i][j]==s[i-1][j]; ++j);
		if(j==s[i].size()){ 
			cout<<"No";
			return 0;
		}
		v[s[i][j]].push_back(s[i-1][j]);		
	}
	for(i='a';i<='k';++i){
		dfs(i);
	}
	for(i=0;i<=ans.size()-1;++i){
		if(ans[i]=='k')	continue;
		ch[ans[i]]=num++;	
	}
	/*
	if(num>10){
		cout<<"No";
		return 0;
	}
	*/
	cout<<"Yes\n";
	for(i='a';i<='j';++i){
		if(ch[i]>9){
			cout<<"No";
			return 0;
		}
		cout<<ch[i]<<" ";
	}
	return 0;
}