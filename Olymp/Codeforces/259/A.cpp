#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n;
	for(i=1;i<=n/2+1;++i){
		for(j=1;j<=n;++j){
			if(n/2+1-i+1<=j && j<=n/2+1+i-1){
				cout<<"D";
			}
			else{
				cout<<"*";
			}
		}
	}
	for(i=n/2+2;i<=n;++i){
		for(j=1;j<=n;++j){
			if(n/2+1-i+1<=j && j<=n/2+1+i-1){
				cout<<"D";
			}
			else{
				cout<<"*";
			}
		}
	}
	return 0;
}