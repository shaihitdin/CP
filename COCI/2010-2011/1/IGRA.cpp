#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
int n,i,j;
string s,tmp1,tmp;
vector<int> v[26];
int sz[26];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	cin>>s;
	s='#'+s;
	for(i=n;i>=1;--i){
		s[i]-='a';
		v[s[i]].push_back(i);
	}
	int r=n;
	for(i=1;i<=n/2;++i){
		while(sz[s[r]]==v[s[r]].size() || (v[s[r]][sz[s[r]]]!=r)) --r;
		tmp+=s[r];
		++sz[s[r]];
		for(j=0;j<26;++j){
			if(sz[j]!=v[j].size()){
				tmp1+=j;
				++sz[j];
				break;
			}
		}
	}
	for(i=0;i<tmp.size();++i)	tmp[i]+='a';
	for(i=0;i<tmp1.size();++i)	tmp1[i]+='a';
	if(tmp<=tmp1){
		cout<<"NE\n";
	}
	else{
		cout<<"DA\n";
	}
	cout<<tmp1;
return 0;
}