#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100001;
int a[N],n,k,odd_pos,even_pos,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&k);

	a[1]=1;
	odd_pos=2;
	even_pos=n;
	for(i=2;i<=n;++i){
		if(k==1)	break;
		if(i&1){
			a[i]=odd_pos;
			++odd_pos;
			--k;
		}
		else{
			a[i]=even_pos;
			--even_pos;
			--k;
		}
	}	
	if(i&1){
		for(;i<=n;++i){
			a[i]=even_pos;
			--even_pos;
		}
	}
	else{
		for(;i<=n;++i){
			a[i]=odd_pos;
			++odd_pos;
		}	
	}
	for(i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	return 0;
}