#include<iostream>
#include<stdio.h>
using namespace std;
int i;
int main(){
		#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
		#endif
		for(i=1;i<=1000000000;++i){
		   if((i%(max(i/2-1,1)))==0)
		    printf("%d\n",&i);		
		}
return 0;}