#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
map<int,int> lasts,lastp;
const int N=1000001;
long long n,a[N],l,r,i,suff[N],ans,pref[N],t[N];
inline long long get(long long r){
	long long ans=0;
	for(;r>=1;r=(r&(r+1))-1){
		ans+=t[r];
	}
	return ans;
}
inline void upd(long long r,long long inc){
	for(;r<=n;r=r|(r+1))
		t[r]+=inc;
	return;
}
int main(){
/*
	freopen("in","r",stdin);
	freopen("out","w",stdout);
*/
	scanf("%I64d",&n);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	for(i=1;i<=n;++i){
		++lastp[a[i]];
		pref[i]=lastp[a[i]];
	}
	for(i=n;i>=1;--i){
		++lasts[a[i]];
		suff[i]=lasts[a[i]];
	}
	for(i=n;i>=1;--i){
		ans+=get(pref[i]-1);
		upd(suff[i],1);
		/*
		cerr<<suff[i]<<" ";
		cerr<<ans<<"\n";
		*/
	}
	printf("%I64d",ans);
	return 0;
}