#include<iostream>
#include<stdio.h>
using namespace std;
const int INF=100000001;
inline bool bit(int mask,int pos){
	return	(mask&(1<<pos));
}
int d[(1<<21)],a[21];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	d[0]=0;
	for(i=1;i<(1<<21);++i){
		d[i]=INF;
	}
	for(i=0;i<(1<<21);++i){
		
	}
	return 0;
}