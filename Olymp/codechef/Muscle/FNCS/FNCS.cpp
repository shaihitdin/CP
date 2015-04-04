#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const int N=104857;
long long sum[351],a[N],l[N],r[N];
long long counter[351][N];
long long v[351][N],t[N],b[N],block_sz;
long long q,q_type,n,i,j,tmp,block,x,y;
unsigned long long ans;
inline void upd(int pos, long long diff) {
	for(int i=pos;i<N;i=(i|(i+1))) {
		t[i]+=diff;
	}
	return;
}
inline long long get(int pos) {
	long long res=0;
	for(int i=pos;i>=0;i=(i&(i+1))-1) {
		res+=t[i];
	}
	return res;
}
inline long long get(int x,int y){
	return get(y)-get(x-1);
} 
int main() { 
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>n;
	block=int(sqrt(n));
	for(i=1;i<=n;++i)
		b[i]=i/block;
	block_sz=n/block;
	for(i=1;i<=n;++i){
		cin>>a[i];
		upd(i,a[i]);
	}
	for(i=1;i<=n;++i)
		cin>>l[i]>>r[i];
	for(i=1;i<=n;++i) {
		++v[b[i]][l[i]];
		--v[b[i]][r[i]+1];
	}
	for(i=0;i<=block_sz;++i) {
		long long tmp=0;
		for(j=1;j<=n;++j) {
			tmp+=v[i][j];
			sum[i]+=(a[j]*tmp);
			counter[i][j] = tmp;
		}
	}
	cin>>q;
	++q;
	while(--q) {
		cin>>q_type>>x>>y;
		if(q_type==1) {
			for(i=0;i<=block_sz;++i) {
				sum[i]-=(counter[i][x]*a[x]);
				sum[i]+=(counter[i][x]*y);
			}
			upd(x,-a[x]);
			upd(x,y);
			a[x]=y;
		}
		else {
			ans=0;
			if(b[x]==b[y]) {
				for(i=x;i<=y;++i)
					ans+=get(l[i],r[i]);
			}
			else {
				for(i=x;b[i]==b[x];++i)
					ans+=get(l[i],r[i]);
				for(;b[i]!=b[y];i+=block)
					ans+=sum[b[i]];
				for(;i<=y;++i)
					ans+=get(l[i],r[i]);
			}
			cout<<ans<<"\n";
		}
	}	
	return 0;
} 