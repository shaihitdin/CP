#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s,q,t;
int i;
int main(){	
	cin>>s>>q>>t;
	if(q=="*"){
		cout<<1;
		for(i=1;i<=s.size()+t.size()-2;++i){
			cout<<0;
		}
	}
	else{
		if(s.size()==t.size()){
			cout<<2;
			for(i=1;i<=s.size()-1;++i){
				cout<<0;
			}
		}
		else{
			cout<<1;
			if(t.size()>s.size())	swap(s,t);
			for(i=1;i<s.size()-t.size();++i){
				cout<<0;
			}
			cout<<1;
			for(i=1;i<t.size();++i){
				cout<<0;
			}
		}
	}
return 0;
}