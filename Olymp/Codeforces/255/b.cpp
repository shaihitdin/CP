#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int k,i,w[30],sum,mx;
string s;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>s;
	cin>>k;
	for(i=0;i<26;++i){
	   cin>>w[i];
	   mx=max(mx,w[i]);
	}
	for(i=0;i<s.size();++i){
	  sum+=(w[s[i]-'a']*(i+1));
	}
	for(i=1;i<=k;++i){
		sum+=(mx*(s.size()+i));
	}
	cout<<sum;
return 0;}