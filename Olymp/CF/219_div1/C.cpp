#include<iostream>
#include<stdio.h>
using namespace std;
const int N=200002;
const long long inf=1000000000000000;
long long a[N],d[N][21],lg[N],i,j,u,v,tmpu,tmpv,n,m,x,y,ans=-inf,dyn[3][N],dist,b[N],t[N],k;
inline long long getmin(const long long &x,const long long &y){
    if(x<y)
     return x;
     return y;
}
inline long long getmax(const long long &x,const long long &y){
    if(x<y)
     return y;
     return x;
}
inline long long getans(const long long &x,const long long &y){
	return getmax(d[x][lg[y-x+1]],d[y-(1<<(lg[y-x+1]))+1][lg[y-x+1]]);
}
inline long long abs_val(const long long &x){
	if(x<0)	return -x;
	else	x;	
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d%I64d%I64d",&n,&m,&dist);
	lg[0]=-1;
	lg[1]=0;
	for(i=2;i<=n+1;++i)
	 lg[i]=lg[i/2]+1;
	for(i=1;i<=m;++i){
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&t[i]);
	}
	t[0]=1;
	for(j=1;j<=m;++j){		
		for(i=n;i>=1;--i){
			  d[i][0]=dyn[(j-1)&1][i];	
		   	for(k=1;(i+(1<<k))-1<=n;++k)
			    d[i][k]=getmax(d[i][k-1],d[i+(1<<(k-1))][k-1]);
		}
		for(i=1;i<=n;++i){
			dyn[j&1][i]=getans(getmax(1,i-(dist*(t[j]-t[j-1]))),getmin(n,i+(dist*(t[j]-t[j-1]))));
		}
		for(i=1;i<=n;++i){
			dyn[j&1][i]+=(b[j]-abs_val(a[j]-i));
//			cerr<<abs_val(b[j]-abs_val(a[j]-i))<<" ";
		}
		cerr<<"\n";
	}
	for(i=1;i<=n;++i){
		ans=getmax(ans,dyn[m&1][i]);
	}
	printf("%I64d",ans);
	return 0;
}
