#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int a[301][301];
int cnt[1000001],n,m,i,j;
vector<char> v1;
vector<int> v2;
int main(){
	freopen("supreme.in","r",stdin);
	freopen("supreme.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(i=n;i>=1;--i){
		int to_col=0;
		for(j=1;j<=m;++j){ 
			if(++cnt[a[i][j]]>m/2)	to_col=a[i][j];
		}
		for(j=1;j<=m;++j){
			cnt[a[i][j]]=0;
		}
		if(to_col==0)	continue;
		for(j=1;j<=m;++j)	a[i][j]=to_col;
	}
	for(i=m;i>=1;--i){
		int to_col=0;
		for(j=1;j<=n;++j){ 
			if(++cnt[a[j][i]]>m/2)	to_col=a[j][i];
		}
		for(j=1;j<=n;++j){
			cnt[a[j][i]]=0;
		}
		if(to_col==0)	continue;
		for(j=1;j<=n;++j)	a[j][i]=to_col;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i][j]!=a[1][1]){
				cout<<"Poor Kazimir";
				return 0;
			}
		}
	}
	cout<<n+m<<"\n";
	for(i=1;i<=n;++i){
		cout<<"R "<<i<<"\n";
	}
	for(i=1;i<=m;++i){
		cout<<"C "<<i<<"\n";
	}
	return 0;
}