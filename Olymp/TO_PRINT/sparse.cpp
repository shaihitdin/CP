#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100002;
int a[N],d[N][18],lg[N],i,j,u,v,tmpu,tmpv,ans;
int n,m;
inline int getmin(int x,int y){
    if(x<y)
     return x;
     return y;
}
inline int getmax(int x,int y){
    if(x<y)
     return y;
     return x;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	ios_base::sync_with_stdio(0);
	scanf("%d %d %d",&n,&m,a+1);
	for(i=2;i<=n;++i)
	 a[i]=(23*a[i-1]+21563)%16714589;
		lg[0]=-1;
		lg[1]=0;
	for(i=2;i<=n+1;++i)
	 lg[i]=lg[i/2]+1;
	for(i=n;i>=1;--i){
	  d[i][0]=a[i];
	   for(j=1;(i+(1<<j))-1<=n;++j)
	    d[i][j]=getmin(d[i][j-1],d[i+(1<<(j-1))][j-1]);
	}
	scanf("%d %d",&u,&v);
	for(i=1;i<=m;++i){
		tmpu=getmin(u,v);
		tmpv=getmax(u,v);
		ans=getmin(d[tmpu][lg[tmpv-tmpu+1]],d[tmpv-(1<<(lg[tmpv-tmpu+1]))+1][lg[tmpv-tmpu+1]]);
		if(i<m){
		u=((17*u)+751+ans+(2*i))%n+1;
		v=((13*v)+593+ans+(5*i))%n+1;
		}
	}
	printf("%d %d %d",u,v,ans);
return 0;}