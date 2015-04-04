#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define mkp make_pair
#define F first
#define S second
vector<pair<int,int> > v[200001];
long long t[200001],a[200001],x,y,priority[200001],total,q[200001],n,m,i,j,tt[200001];
pair<long long,long long> b[200001];
inline long long get(int r){
	long long ans=0;
	for(int i=r;i>=1;i=(i&(i+1))-1){
		ans+=t[i];		
	}
	return ans;
}
inline void upd(int pos,long long inc){
	for(int i=pos;i<=200000;i=i|(i+1)){
		t[i]+=inc;		
	}
	return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out1","w",stdout);
	#endif
	scanf("%I64d%I64d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	for(i=1;i<=n;++i){
		b[i].F=a[i];
		b[i].S=i;	
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;++i){
		priority[b[i].S]=priority[b[i-1].S];
		if(b[i].F!=b[i-1].F){
			++priority[b[i].S];
		}
	}
	for(i=1;i<=m;++i){
		scanf("%I64d%I64d",&x,&y);
		if(x>y) swap(x,y);
		//if(a[x]<a[y]) q[i]-=2;
		v[x].push_back(mkp(y,i));
		v[y].push_back(mkp(x,i));
	}
	for(i=1;i<=n;++i){
		long long tmp=(get(200000)-get(priority[i]));
		total+=tmp;
		upd(priority[i],1);
		for(j=0;j<v[i].size();++j){
			int pos=v[i][j].F,id=v[i][j].S;
			cerr<<q[id]<<" ";
			tt[id]+=tmp;
			cerr<<tt[id]<<" ";
			q[id]+=(get(200000)-get(priority[pos]));
			cerr<<q[id]<<"\n";
		}
	}
/*
	for(i=1;i<=200000;++i)
		t[i]=0;
	cerr<<"\n";
	for(i=1;i<=m;++i){
		cerr<<q[i]<<" ";
	}

	for(i=n;i>=1;--i){
		long long tmp=(get(priority[i]-1));
		for(j=0;j<v[i].size();++j){
			long long pos=v[i][j].F,id=v[i][j].S;
			q[id]-=tmp; q[id]+=(get(priority[pos]-1));
		}	
		upd(priority[i],1);
	}
*/
	for(i=1;i<=m;++i){
		printf("%I64d\n",q[i]+(total-tt[i]));
	}
	return 0;
}