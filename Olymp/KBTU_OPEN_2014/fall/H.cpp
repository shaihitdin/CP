#include<iostream>
#include<stdio.h>
using namespace std;
int n,a,b,c,d[1000001][5],i;
int main(){
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d%d",&a,&b,&c);
		d[i][1]=min(d[i-1][2],d[i-1][3])+a;
		d[i][2]=min(d[i-1][1],d[i-1][3])+b;
		d[i][3]=min(d[i-1][2],d[i-1][1])+c;
	}
	printf("%d",min(d[n][1],min(d[n][2],d[n][3])));
	return 0;
}