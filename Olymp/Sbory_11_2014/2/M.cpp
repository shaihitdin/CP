#include<iostream>
#include<stdio.h>
using namespace std;
int b[301],d[301];
int ruck[300001];
int main () {
	freopen("balls.in","r",stdin);
	freopen("balls.out","w",stdout);

	for(int i=1;i<=300;++i){
		b[i]=b[i-1]+i;
	}
	for(int i=1;i<=300;++i){
		d[i]=d[i-1]+b[i];
	}
	for(int i=1;i<=300000;++i){
		ruck[i]=1000000001;
	}
	ruck[0]=0;
	for(int i=0;i<=300000;++i){
		for(int j=1;j<=300;++j){
			if(i+d[j]<=300000)
				ruck[i+d[j]]=min(ruck[i+d[j]],ruck[i]+1);
		}
	}
	int t,x;
	scanf("%d",&t);
	++t;
	while(--t){
		scanf("%d",&x);
		printf("%d\n",ruck[x]);
	}
	return 0;
}