#include<iostream>
#include<stdio.h>
using namespace std;
int n,x,cnt[10],i,ans;
int main(){
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>x;
		++cnt[x];
	}
	ans+=cnt[4];
	ans+=(cnt[3]);
	cnt[1]-=min(cnt[1],cnt[3]);
	ans+=(cnt[2]/2);
	cnt[2]=cnt[2]%2;
	if(cnt[2]==1){
		cnt[1]-=min(2,cnt[1]);
		++ans;
	}
	ans+=(cnt[1]/4)+((cnt[1]%4)!=0);
	cout<<ans;
	return 0;
}