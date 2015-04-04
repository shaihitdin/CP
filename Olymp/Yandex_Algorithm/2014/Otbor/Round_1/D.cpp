#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
const long long N=16384;
long long n,x,cnt[N],tmp[N],i,j;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	cnt[0]=1;
	for(i=1;i<=n;++i){
		cin>>x;
		memset(tmp,0,sizeof(tmp));
		for(j=0;j<N;++j){
			if((x^j)<N)	tmp[x^j]+=cnt[j];
		}
		for(j=0;j<N;++j)	cnt[j]+=tmp[j];
	}
	return 0;
}