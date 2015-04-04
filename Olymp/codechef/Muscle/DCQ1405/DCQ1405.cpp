#include<iostream>
#include<stdio.h>
using namespace std;
#ifdef _WIN32
	#define I64d "%lld"
#else 
	#define I64d "%I64d"
#endif
const long long N=100001,mod=1000000007;
long long d[N][21],sum[N],i,j,k,t,n;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	ios_base::sync_with_stdio(0);
	for(i=1;i<10;++i)	d[1][i]=1;
	sum[1]=9;
	for(i=2;i<N;++i){
		for(j=0;j<10;++j){
			for(k=0;k<10;++k){
				if(k==j)	continue;
				d[i][j]=(d[i][j]+d[i-1][k])%mod;
			}			
			if(i>3 && j>=3){
				d[i][j]=(d[i][j]-d[i-3][j-3]+mod)%mod;
			}
			sum[i]=(sum[i]+d[i][j])%mod;
		}
	}
	scanf(I64d,&t);
	++t;
	while(--t){
		scanf(I64d,&n);
		printf(I64d"\n",sum[n]);
	}
	return 0;
}