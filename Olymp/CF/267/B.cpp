#include<iostream>
#include<stdio.h>
using namespace std;
int ans,i,n,x,y,m,k,j,a[10001],tmp;
inline bool bit(int mask,int pos){
	return (mask&(1<<pos));
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m>>k;
	for(i=1;i<=m;++i){
		cin>>a[i];
	}
	cin>>x;
	for(i=1;i<=m;++i){
		tmp=0;
		for(j=n;j>=0;--j){
			if(bit(x,j)^bit(a[i],j)==1){
				++tmp;
			}	
		}
		if(tmp<=k){
			++ans;
		}
	}
	cout<<ans;
return 0;
}