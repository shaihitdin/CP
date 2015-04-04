#include<iostream>
#include<stdio.h>
using namespace std;
int j,i,ans;
int main(){
/*
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
*/
	for(j=10;j<=10000000;j*=10){
		ans=0;
		for(i=1;i<=j;++i){
			if(j%i==0)	++ans;
		}
		cerr<<ans<<"\n";
	}
	return 0;
}