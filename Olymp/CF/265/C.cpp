#include<stdio.h>
#include<iostream>
using namespace std;
int n,i,ans,p;
char a[1001],or_a[1001];
bool check(){
	if((i>=1 && i+1<=n && a[i]==a[i+1]) || (i>=2 && i<=n && a[i-1]==a[i])){
		return 0;	
	}
	if((i>=1 && i+2<=n && a[i]==a[i+2]) || (i>=2 && i+1<=n && a[i-1]==a[i+1]) || (i>=3 && i<=n && a[i-2]==a[i])){
		return 0;
	}
	return 1;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>p;
	for(i=1;i<=n;++i){
		cin>>a[i];
	}
	for(i=1;i<=n;++i)
		or_a[i]=a[i];
	for(i=n;i>=1;--i){
		for(char j=a[i]+1;j<char('a'+p);++j){
			a[i]=j;
			if(check()){
				for(i=1;i<=n;++i){
					cout<<a[i];
				}
				return 0;
			}
			a[i]=or_a[i];
		}
		for(	
	}
	cout<<"NO";
return 0;
}