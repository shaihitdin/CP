#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100002;
long long a[N],d[N][18],lg[N],i,j,u,v,tmpu,tmpv,n,m,x,y,ans;
inline long long getmin(long long x,long long y){
    if(x<y)
     return x;
     return y;
}
inline long long getmax(long long x,long long y){
    if(x<y)
     return y;
     return x;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>a[i];
		lg[0]=-1;
		lg[1]=0;
	for(i=2;i<=n+1;++i)
	 lg[i]=lg[i/2]+1;
	for(i=n;i>=1;--i){
	  d[i][0]=a[i];
	   for(j=1;(i+(1<<j))-1<=n;++j)
	    d[i][j]=getmin(d[i][j-1],d[i+(1<<(j-1))][j-1]);
	}
/*	for(i=1;i<=n;++i){
	   for(j=0;(i+(1<<j))-1<=n;++j)
	    cout<<d[i][j]<<" ";
	    cout<<"\n";
	}
*/
	cin>>m;
	for(i=1;i<=m;++i){
	 cin>>x>>y;
	 ans=getmin(d[x][lg[y-x+1]],d[y-(1<<lg[y-x+1])+1][lg[y-x+1]]);
	 cout<<ans<<" ";
	}
return 0;}