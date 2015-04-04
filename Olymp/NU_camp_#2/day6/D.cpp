#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int maxn=101;
int a[maxn],n,nulls;
char c;
int swapped;
int k;                       
int main() {
	for (n=1;;++n) {
		c=getchar();
		if (c==' ') break;
		a[n]=int(c-'0');
		if (!a[n]) ++nulls;
	}	       
	--n;          
	scanf("%d",&k);
	if ((nulls==n-1 && n==2) || (n==1)) {
		printf("-1");
		return 0;
	}	
	for (int i=1; i<=n-1 && i<=k; ++i) {
		int mx=-1, mx_id=1;
		for (int j=i; j<=n; ++j) 
			if (a[j]>mx) mx=a[j], mx_id=j;
		if (mx_id!=i) ++swapped;	
	}
	for (int i=swapped+1; i<=k; ++i) swap(a[n],a[n-1]);
	for (int i=1; i<=n-1 && i<=k; ++i) {
		int mx=-1, mx_id=1;
		for (int j=i; j<=n; ++j) 
			if (a[j]>mx) mx=a[j], mx_id=j;
		if (mx_id!=i) swap(a[mx_id],a[i]);	
	}
	for (int i=1; i<=n; ++i) cout<<a[i];
}