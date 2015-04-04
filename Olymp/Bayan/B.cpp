#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int n;
string s;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout); 
	cin>>n;
	++n;
	while(--n){
		cin>>s;
		int cnt=0;
		for(int i=0;i<s.size();++i){
			s[i]=tolower(s[i]);
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
				++cnt;
		}
		if(cnt&1){
			cout<<"PESAR\n";
		}
		else{
			cout<<"DOKHTAR\n";
		}
	}
	return 0;
}