#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[100001],n,i,t,ans;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>t;
	++t;
	while(--t){
		ans=0;
		cin>>n;
		for(i=1;i<=n;++i)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(i=n;i>=1;i-=2)
			ans+=a[i];		
		cout<<ans<<"\n";
	}
	return 0;
}