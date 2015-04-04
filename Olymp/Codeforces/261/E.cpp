#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define F first
#define S second
#define mkp make_pair
const int N=300001;
int ptr[N],ans,n,m,x[N],y[N],z[N],i;
bool cmp(const int &lhs, const int &rhs){
	return z[lhs]<z[rhs];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		a[i]=i;
	}
	sort(a + 1, a + n + 1, cmp);

	printf("%I64d",ans);
	return 0;
}