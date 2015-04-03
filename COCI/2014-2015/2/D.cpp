#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1001;
int d[N][N],a[N][N],tmp,k,i,j,n,m,ans,l,r,c[N][N];
int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i][j]==a[i][j-1])	d[i][j]=d[i][j-1]+1;
			else	d[i][j]=1;
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i][j]==a[i-1][j]){
				c[i][j]=min(d[i][j],c[i-1][j]);
			}
			else{
				c[i][j]=d[i][j];
			}
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			for(l=i,r=1;l<r;){
				 
			}
			for(tmp=d[i][j],k=i;k>=1 && a[k][j]==a[i][j];--k){
				tmp=min(d[k][j],tmp);
				ans+=tmp;
			}
		}
	}
	printf("%d",ans);
	return 0;
}