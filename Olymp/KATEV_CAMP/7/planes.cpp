#include<iostream>
#include<stdio.h>
using namespace std;
int cnt[11],mx,ans[11],res,n,m,k,a[11],b[11],c[11];
int u[11];
inline void rec(int lvl){
	if(n<lvl){
		res=0;
		for(int i=1;i<=n;++i){
			if(u[i]!=0)	++res;
			if(u[i]==0 && c[i]==1)	return;
		}
		for(int i=1;i<=m;++i){
			if(k-cnt[i]<0){
				return;
			}
		}
		if(mx<res){
			mx=res;
			for(int i=1;i<=n;++i){
				ans[i]=u[i];
			}
		}
		return;
	}
	for(int i=a[lvl];i<=b[lvl];++i){
		if(k-cnt[i]>=0){
			++cnt[i];
			u[lvl]=i;
			rec(lvl+1);
			u[lvl]=0;
			--cnt[i];
		}
	}
	rec(lvl+1);
	return;
} 
int main(){
	freopen("planes.in","r",stdin);
	freopen("planes.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
	}
	rec(1);
	if(mx==0){
		cout<<"0";
		return 0;
	}
	cout<<mx<<"\n";
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}