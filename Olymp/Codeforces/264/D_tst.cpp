#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,a[2001],i,j;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i) a[i]=i;
	do{
		for(i=1;i<=n;++i) cerr<<a[i]<<" ";
		cerr<<"\n";
	}while(next_permutation(a+1,a+n+1));
return 0;
}