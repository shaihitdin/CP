#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
string n;
int d,i;
int main(){
	freopen("dragon.in","r",stdin);
	freopen("dragon.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>d>>n;
	if(n.size()>d){
		cout<<"No solution";
		return 0;
	}
	cout<<n;
	for(i=n.size()+1;i<=d;++i){
		cout<<0;
	}
	return 0;
}