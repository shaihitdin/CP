#include<iostream>
#include<stdio.h>

using namespace std;
const int N=5001;
long long ans[N][N],d[N],x,a[N],n,m,k,i,j;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m>>k;
	for(i=1;i<=n;++i){
		cin>>x;
		d[i]=d[i-1]+x;
	}
	for(j=1;j<=k;++j){
		for(i=m;i<=n;++i){
			ans[i][j]=max(ans[i-1][j],ans[i-m][j-1]+(d[i]-d[i-m]));
		}
	}
	cout<<ans[n][k];
return 0;
}