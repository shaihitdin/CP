#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
const int N=3000000;
map<long long,long long> mpx,mpy;
long long n,x[N],y[N],ans,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		++mpx[x[i]];
		++mpy[y[i]];
	}	
	for(i=1;i<=n;++i){
		ans+=((mpx[x[i]]-1)*(mpy[y[i]]-1));
	}	
	printf("%d",ans);
	return 0;
}