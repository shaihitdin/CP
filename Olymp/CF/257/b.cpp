#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const long long N=1000000007;
long long x,n,y;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>x>>y;
	cin>>n;
	if(n%3==0){
	  
	}
	if(n%9==1){
	 cout<<(x+N)%N;
	}
	if(n%9==2){
	 cout<<(y+N)%N;
	}
	if(n%9==3){
	 cout<<(y-x+N)%N;
	}
	if(n%9==4){
	 cout<<(-x+N)%N;
	}
	if(n%9==5){
	 cout<<(-y+N)%N;
	}
	if(n%9==6){
	 cout<<(-x-y+N)%N;
	}
	if(n%9==7){
	 cout<<(-x+N)%N;
	}
	if(n%9==8){
	 cout<<(y+N)%N;
	}
	if(n%9==0){
	 cout<<(y+x+N)%N;
	}
return 0;}