#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s,t;
int u1[1001],u2[1001];
bool ans1,ans2,ans3;
int l,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>s>>t;
	l=0;
		for(i=0;i<s.size() && l<t.size();++i){
			if(s[i]==t[l])
				++l;
		}
		if(l<t.size()-1)
		   ans2=1; //swap
	for(i=0;i<s.size();++i)
	 	++u1[int(s[i])];
	for(i=0;i<t.size();++i)
	 	++u2[int(t[i])];
	for(i=97;i<=122;++i){
	 	if(u1[i]>u2[i]){
	 		ans1=1;//del
	 	}
	 	if(u1[i]<u2[i]){
	 	 	ans3=1;//more
	 	}
	}
	if(ans3){
	 cout<<"need tree";
	}
	else if(ans2 && ans1){
	 cout<<"both";
	}
	else if(ans1){
	 cout<<"automaton";
	}
	else if(ans2){
	 cout<<"array";
	}
return 0;}