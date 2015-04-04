#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
long long x;
map<long long,bool> mp;
int main(){
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	
	while(cin>>x){
		if(mp[x]==0){
			cout<<x<<"\n";
			mp[x]=1;
		}
	}
	return 0;
}