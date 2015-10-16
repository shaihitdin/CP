#include<stdio.h>
#include<iostream>
using namespace std;
int n,i,ans,j;
char a[1001];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
	}    
	for(i=1;i<=n;++i){
		if(a[i]=='1') break;
	}
	cerr<<i<<"\n";
	for(;i<=n;){
		cerr<<i<<" ";
		++ans;
		for(j=i+1;j<=n;++j) if(a[j]=='1') break;
		
		if(j!=i+1 && j<=n) ++ans;

		i=j;
		cerr<<"next :"<<j<<"\n";
	}
	cout<<ans;
return 0;
}