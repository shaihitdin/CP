#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,j,k,a[2001],ans;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    cin>>n>>k;
    for(i=1;i<=n;++i){
    	cin>>a[i];
    }
	sort(a+1,a+n+1);
	for(i=n;i>=1;i-=k){
		ans+=((a[i]-1)*2);
	}
	cout<<ans;
	return 0;
}