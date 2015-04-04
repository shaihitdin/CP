#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,i,j;
char a[102][102];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>n;	
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
		cin>>a[i][j];
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j){
		int tmp=0;
		if(a[i-1][j]=='o'){
			++tmp;
		}
		if(a[i+1][j]=='o'){
			++tmp;
		}
		if(a[i][j-1]=='o'){
			++tmp;
		}
		if(a[i][j+1]=='o'){
			++tmp;
		}
		if(tmp&1){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
return 0;
}