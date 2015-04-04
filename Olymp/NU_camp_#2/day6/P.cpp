#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int maxn=100100;
int n,m,k; 
long long ans;
bool in(int l, int r, int x) {
	return l<=x&&x<=r;
}
int l[maxn],r[maxn],d[maxn];
int x;
int main() {
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1; i<=m; ++i) 
		scanf("%d %d %d",&l[i],&r[i],&d[i]);	
	for (int i=1; i<=k; ++i) {
		scanf("%d",&x);
		for (int j=1; j<=m; ++j) 
			if (in(l[j],r[j],x)) 
				ans+=x-l[j]+d[j]; 
	}	
	printf("%I64d",ans);
	return 0;
}
