#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,j,k;
double a[101],d[101][101],oos,ooh,nos,mx;
bool u[101];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%lf",&a[i]);
	}
	sort(a+1,a+n+1);
	mx=a[n];
	u[n]=1;
	for(i=n-1;i>=1;--i){
			
	}
	printf("%.9lf",mx);
	return 0;
} 