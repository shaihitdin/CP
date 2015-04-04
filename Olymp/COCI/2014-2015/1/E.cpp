#include<iostream>
#include<stdio.h>
using namespace std;
const int N=700;
const long long inf=10000000000000001;
long long n,m,k;
long long d[N][N];
long long sz[N],i,j,p,z,cnt[N],x;
inline long long get_sum(long long &x){
	return (x*(x+1))/2;
}
int main(){
/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);
*/
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=n;++i){
		scanf("%lld",&x);
		++cnt[x];
	}
	for(i=0;i<=m;++i)
		for(j=0;j<=k;++j)
			d[i][j]=inf;
	sz[0]=m;
	d[0][0]=0;
	for(i=1;i<=m;++i){
		d[i][0]=d[i-1][0]+get_sum(cnt[i]);
	}
	for(i=1;i<=m;++i){
		for(j=0;j<k;++j){
			for(p=1;p<=min(cnt[i],k-j);++p){
				long long tmp1=((cnt[i]+p)/(p+1)),mult=cnt[i]%(p+1),tmp2=tmp1-1,mult1=p+1-mult;
				long long check=d[i-1][j]+(get_sum(tmp1)*mult)+(get_sum(tmp2)*mult1); 
				d[i][j+p]=min(d[i][j+p],check);
			}
		}
	}
	printf("%lld",d[m][k]);
	return 0;
}