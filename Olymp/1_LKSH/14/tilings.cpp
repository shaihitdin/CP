#include<iostream>
#include<stdio.h>
using namespace std;
inline bool bit(int mask,int pos){
	return (mask&(1<<pos));
}
long long d[31][1<<16],n,m,nn,i,j,k;

inline long long check(int mask1,int mask2){
	for(int i=1;i<n;++i){
		if(bit(mask1,i) == bit(mask2,i) && bit(mask1,i-1) == bit(mask2,i-1) && bit(mask1,i) == bit(mask1,i-1))
			return 0;
	}
	return 1;
}
int main(){
	freopen("tilings.in","r",stdin);
	freopen("tilings.out","w",stdout);
	cin>>n>>m;
	if(n>m)
	swap(n,m); 
	nn=(1<<n);
	for(i=0;i<nn;++i) d[0][i]=1;
	for(i=1;i<m;++i){
		for(j=0;j<nn;++j){
			for(k=0;k<nn;++k){
				d[i][j] += d[i-1][k]*check(j,k);
			}
		}
	}
	long long res=0;
	for(i=0;i<nn;++i)	res+=d[m-1][i];
	cout<<res;
return 0;
}