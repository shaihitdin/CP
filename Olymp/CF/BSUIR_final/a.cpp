#include<iostream>
#include<stdio.h>
using namespace std;
long long a,b;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>a>>b;
	if((a<0 && b<0) || (a>0 && b>0)){
		cout<<a-b;
	}
	else{
		cout<<a+b;
	}
	return 0;
}