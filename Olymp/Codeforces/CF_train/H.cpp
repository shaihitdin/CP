#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int n,i,x; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	//x=sqrt(n);
	for(i=2;i*i<=n;++i){
		if(!(n%i)){
			printf("%d",(n-n/i));
			return 0;
		}
	}
	printf("%d",n-1);
	return 0;
}