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
		reverse(s.begin(),s.end());
		cout<<s<<"\n";
	}
	return 0;
}