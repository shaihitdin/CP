#include<iostream>
#include<stdio.h>
using namespace std;
int d[2000001],n,k,x,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	d[0]=k;
	++n;
	for(i=0;i<=2000000;++i){       
		while(d[i]){
			scanf("%d",&x);
			if(i+x<=2000000)
				++d[i+x];
		    --d[i];
		    --n;
		    if(!n){
				break;
			}
		}                             
		
		if(!n){
			break;
		}
		/*
		if (i)
			d[i] += d[i - 1];
		if (d[i]) {
			--n;
			scanf("%d", &x);
			--d[i + 1];
			++d[i + x];
		}
		*/
	}
	printf("%d",i);
	return 0;
}