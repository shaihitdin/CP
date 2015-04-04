#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[1001],sum,i;
int main(){
	freopen("rings.in","r",stdin);
	freopen("rings.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	printf("%d",sum-a[n]);
	return 0;
}