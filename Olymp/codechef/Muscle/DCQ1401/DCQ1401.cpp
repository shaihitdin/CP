#include<iostream>
#include<stdio.h>
using namespace std;
char a[1001][1001],x;
int n,m,ans1,ans2,i,j;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			cin>>a[i][j];
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if((i&1)^(j&1)){
				x='1';
			}
			else{
				x='0';
			}
			if(x!=a[i][j])
				++ans1;
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if((i&1)^(j&1)){
				x='0';
			}
			else{
				x='1';
			}
			if(x!=a[i][j])
				++ans2;
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}