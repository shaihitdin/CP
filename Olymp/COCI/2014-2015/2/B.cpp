#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
map<string,int> mp;
string t[100001],s;
int n,i;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>t[i];
		mp[t[i]]++;
	}
	for(i=1;i<n;++i){
		cin>>s;
		--mp[s];
	}
	for(i=1;i<=n;++i){
		if(mp[t[i]]==1){
			cout<<t[i];
			return 0;
		}
	}
	return 0;
}