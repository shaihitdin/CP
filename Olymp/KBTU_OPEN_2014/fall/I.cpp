#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s;
int mp[256];
int mx,mn=100000,i;
int main(){
	freopen("segredo.in","r",stdin);
	freopen("segredo.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();++i){
		++mp[s[i]];
	}
	for(i=0;i<256;++i){
		if(mp[i]>mx)	mx=mp[i];
		if(mp[i]<mn && mp[i]!=0)	mn=mp[i];
	}
	for(i=0;i<256;++i){
		if(mp[i]==mx)	cout<<char(i);
	}
	cout<<"\n";
	for(i=0;i<256;++i){
		if(mp[i]==mn)	cout<<char(i);
	}
	return 0;
}