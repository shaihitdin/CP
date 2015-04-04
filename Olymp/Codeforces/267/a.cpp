#include<iostream>
#include<stdio.h>
using namespace std;
int ans,i,n,x,y;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>x>>y;
		if(y-2>=x){
			++ans;
		}
	}
	cout<<ans;
return 0;
}