#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N=(1<<21)+1;
long long t[N],dv[N],sub_sum[N][32],dv_l[N][33],dv_lsz[N],sz,n,i,m,q,l,r,p,d,j;
inline void mult(long long v,long long multi){
		dv_l[v][++dv_lsz[v]]=multi;
		dv[v]*=multi;
		sub_sum[v][++dv_lsz[v]]=sub_sum[v][dv_lsz[v]-1]*multi;	
}
inline void push(long long v){
	if(v<sz){
		for(int j=1;j<=dv_lsz[v] && dv[v*2]*dv_l[v][j]<=1000000000*1ll;++j){
			mult(v*2,dv_l[v][j]);
		}
		for(int j=1;j<=dv_lsz[v] && dv[v*2+1]*dv_l[v][j]<=1000000000*1ll;++j){
			mult(v*2+1,dv_l[v][j]);
		}
	}
	else{
		int l=0,r=dv_lsz[v]+1;
		while(r-l>1){
			int mid=(r+l)/2;
			if(t[v]%sub_sum[v][mid]==0)	l=mid;
			else	r=mid;
		}
		if(l!=0)
			t[v]/=sub_sum[v][l];
	}
	dv[v]=1;
	dv_lsz[v]=0;
	return;
}
inline void upd(long long v,long long l,long long r,long long Tl,long long Tr,long long upd1){
	if(Tl>r || Tr<l){
		return;
	}
	push(v);
	if(l<=Tl && Tr<=r){
		if(dv[v]*upd1<=1000000000*1ll){
			mult(v,upd1);
		}
		push(v);
		return;
	}
	long long mid=(Tr+Tl)/2;
	upd(v*2,l,r,Tl,mid,upd1);
	upd(v*2+1,l,r,mid+1,Tr,upd1);
	push(v);
	return;
}

inline void upd2(long long v,long long l,long long r,long long Tl,long long Tr,long long upd1){
	if(Tl>r || Tr<l){
		return;
	}
	push(v);
	if(l<=Tl && Tr<=r){
		t[v]=upd1;
		return;
	}
	long long mid=(Tr+Tl)/2;
	upd2(v*2,l,r,Tl,mid,upd1);
	upd2(v*2+1,l,r,mid+1,Tr,upd1);
	push(v);
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	sz=1<<19;
	cin>>n;
	memset(dv,1,sizeof(dv));
	memset(sub_sum,1,sizeof(sub_sum));
	for(i=0;i<n;++i){
		cin>>t[sz+i];
	}
	cin>>m;
	for(i=1;i<=m;++i){
		cin>>q;
		if(q==1){
			cin>>l>>r>>p;
			upd(1,l-1,r-1,0,sz-1,p);
		}
		else{
			cin>>l>>d;
			r=l;
			upd2(1,l-1,r-1,0,sz-1,d);
		}
	}
	for(i=1;i<sz+sz;++i){
		push(i);
	}
	for(i=sz;i<sz+n;++i){
		cout<<t[i]<<" ";
	}
	return 0;
}