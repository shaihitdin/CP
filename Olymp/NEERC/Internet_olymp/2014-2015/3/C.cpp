#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
#define mkp make_pair
int n,i,j,d[301][301],k;
int ans[301][301],res,p1[301][301],p2[301][301];
int main(){
	freopen("joke.in","r",stdin);
	freopen("joke.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			scanf("%d",&d[i][j]);
			if(d[i][j]==-1)
				d[i][j]=1000001;
		}
	}
	for(i=1;i<=n;++i){
		ans[1][i]=1;
	}
	for(k=1;k<=n;++k){
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				if(d[i][j]>d[i][k]+d[k][j]){
					ans[i][j]=0;
					ans[i][k]+=1;
					ans[k][j]+=1;
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	/*
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	*/
	for(i=1;i<=n;++i){
		res=max(res,ans[1][i]);
	}
	printf("%d",res);
	return 0;
}