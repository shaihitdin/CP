#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int tmp,n,x[5],y[5],a[5],b[5],chx[5],chy[5],tmp1[5];
inline void rec(int lvl){
	if(lvl==5){
		for(int i=1;i<=4;++i){
			tmpx[i]=a[i]+chx[i];
			tmpy[i]=b[i]+chy[i];	
		}
		for(int i=1;i<=4;++i){
			if(tmpx)
		}
	}
	for(int i=0;i<=4;++i){
		if(i!=4){
			tmp1[lvl]=i;
			rec(lvl+1);
		}
		swap(chx[lvl],chy[lvl]);
		chx[lvl]=-chx[lvl];
	}
	return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	++n;
	while(--n){
		for(i=1;i<=4;++i){
			scanf("%d%d%d%d",&x[i],&y[i],&a[i],&b[i]);
			chx[i]=x[i]-a[i];
			chy[i]=y[i]-b[i];
		}
		rec(1);
	}
	return 0;
}