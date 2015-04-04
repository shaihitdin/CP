#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
#define mkp make_pair
multimap<string,int>  mp;
string s,t[1000001];
int n,m,i,j,ans[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=m;++i){
		cin>>t[i];
	}
	for(i=0,j=1;i<n;i+=(n/m),++j){
		mp.insert(mkp(s.substr(i,(n/m)),j));
	}
	for(i=1;i<=m;++i){
		ans[mp.find(t[i])->second]=i;
		mp.erase(mp.find(t[i]));
	}
	for(i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}