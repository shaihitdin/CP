#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
 
using namespace std;
#define mkp make_pair
#define F first
#define S second
 
const int N=200100;
long long n,m,a[N],t[N],i,ans,q[N],x[N],y[N];
pair<long long,long long> ss[N];
vector<pair<long long,long long> > v[N];
 
inline long long get(long long r){
	long long sum=0;
	for(long long i=r;i>=1;i=(i&(i+1))-1)
		sum+=t[i];
	return sum;
}
 
inline void upd(long long r,long long inc){
	for(long long i=r;i<N;i=(i|(i+1)))
		t[i]+=inc;
	return;
}
 
int main(){
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>a[i];
		ss[i]=mkp(a[i],i);
	}
	for(i=1;i<=m;++i){
		cin>>x[i]>>y[i];
		if(x[i]>y[i]) swap(x[i],y[i]);
		v[x[i]].push_back(mkp(y[i],i));
		v[y[i]].push_back(mkp(x[i],i));
	}
	sort(ss+1,ss+n+1);
	a[0]=1;
	for(i=1;i<=n;++i){
		a[ss[i].S]=a[ss[i-1].S];
		if(ss[i].F!=ss[i-1].F)	++a[ss[i].S];
	}
	//ans
	for(i=1;i<=n;++i){
		ans+=(get(N-1)-get(a[i]));
		upd(a[i],1);
	}
	memset(t,0,sizeof(t));
	//as a[j]
	for(i=1;i<=n;++i){
		long long tmp=(get(N-1)-get(a[i]));
		for(int j=0;j<v[i].size();++j){
			long long pos=v[i][j].F,id=v[i][j].S;
			q[id]-=tmp;
			if(pos<i){
				upd(a[i],1);
				upd(a[pos],-1);
			}
			q[id]+=(get(N-1)-get(a[pos]));
			if(pos<i){
				upd(a[i],-1);
				upd(a[pos],+1);
			}
		}
		upd(a[i],1);
	}
	memset(t,0,sizeof(t));
	//as a[i]
	for(i=n;i>=1;--i){
		long long tmp=get(a[i]-1);
		for(int j=0;j<v[i].size();++j){
			long long pos=v[i][j].F,id=v[i][j].S;
			q[id]-=tmp;
			if(pos>i){
				upd(a[i],1);
				upd(a[pos],-1);
			}
			q[id]+=(get(a[pos]-1));
			if(pos>i){
				upd(a[i],-1);
				upd(a[pos],1);
			}
		}
		upd(a[i],1);
	}
	for(i=1;i<=m;++i){
		if(a[x[i]]<a[y[i]]) --q[i];
		if(a[x[i]]>a[y[i]]) ++q[i];
		cout<<max(ans+q[i],0*1ll)<<"\n";
	}
	return 0;
}  