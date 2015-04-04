#include<iostream>
#include<stdio.h>
using namespace std;
long long n,i,tmp=2,ans;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n;
	for(i=1;i<=1000000;++i){
		if((n-(i*(i*3+1)/2))>=0 && (n-(i*(i*3+1)/2))%3==0)	++ans;
	}
	cout<<ans;
	return 0;
}