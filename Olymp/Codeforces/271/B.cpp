#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int tmp,n,m,a[100001],b[100001],i,j,pos[1000001];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(j=1;j<=a[i];++j){
			pos[j+tmp]=i;
		}
		tmp+=a[i];
	}
	scanf("%d",&m);
	for(i=1;i<=m;++i){
		scanf("%d",&b[i]);
		printf("%d\n",pos[b[i]]);
	}


	return 0;
}