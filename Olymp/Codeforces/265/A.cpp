#include<stdio.h>
#include<iostream>
using namespace std;
int n,i;
char a[101];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	scanf("\n");
	for(i=1;i<=n;++i){
		scanf("%c",&a[i]);
	}    
	i=1;
	while(a[i]=='1' && i<=n) ++i;
	printf("%d",min(i,n));
return 0;
}