#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
using namespace std;
const long long N=100007;
map<long long,long long> t_mp[N];
long long t[N],mxlen,mxcnt,n,i,d[N],a[N],x,ans[N];
long long u[N];
void upd(long long r,long long inc){      
	for(;r<N;r=(r|(r+1))){
		t[r]=max(t[r],inc);
	}
	return;
}
long long get(long long r){
	long long res=0;
	for(;r>=1;r=(r&(r+1))-1){
		res=max(t[r],res);
	}
	return res;
}
void upd_mp(long long r, long long inc,long long pos){
	for(;r<N;r=(r|(r+1))){
		t_mp[pos][r]+=inc;
	}
	return;
}
long long get_mp(long long r,long long pos){
	long long res=0;
	for(;r>=1;r=(r&(r+1))-1){
		res+=t_mp[pos][r];
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d",&n);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	for(i=1;i<=n;++i){
		d[i]=get(a[i]-1)+1;
		upd(a[i],d[i]);
		mxlen=max(mxlen,d[i]);
	}
	for(i=n;i>=1;--i){
		x=(get_mp(N-1,d[i]+1)-get_mp(a[i],d[i]+1));
		if(d[i]==mxlen){
			x=1;
		}
		if(!x){
			ans[i]=1;
		}
		else{
			ans[i]=2;
			++u[d[i]];
		}
		upd_mp(a[i],x,d[i]);
	}
	for(i=1;i<=n;++i){
		if(ans[i]!=1){
			if(u[d[i]]==1){
				ans[i]=3;
			}
			else{
				ans[i]=2;
			}
		}
	}
	for(i=1;i<=n;++i){
		printf("%I64d",ans[i]);
	}
	return 0;
}