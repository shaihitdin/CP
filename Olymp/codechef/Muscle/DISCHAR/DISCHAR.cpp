#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
bool u[100001];
string s;
int n,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>n;
	++n;
	while(--n){
		cin>>s;
		int cnt=0;
		memset(u,0,sizeof(u));
		for(i=0;i<s.size();++i)
			u[s[i]]=1;
		for(i=0;i<256;++i)
			if(u[i])	++cnt;
		cout<<cnt<<"\n";
	}
	return 0;
}