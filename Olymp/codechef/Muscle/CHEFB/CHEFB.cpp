#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N=1000001;
int i,j,lp[N],pr[N],pr_sz,x,t,n,ans,v[N],v_sz,u[N],cnt[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
	ios_base::sync_with_stdio(0);
	lp[1]=1; 
	for (i=2;i<N;++i){
		if (!lp[i])
			lp[i]=i,pr[++pr_sz]=i;
		for (j=1;j<=pr_sz && pr[j]<=lp[i] && i*pr[j]<N; ++j)
			lp[i*pr[j]]=pr[j];
	}
	cin>>t;
	++t;
	while(--t){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>x;
			for(;x!=1;x=x/lp[x])	++cnt[lp[x]],v[++v_sz]=lp[x];
			for(j=1;j<=v_sz;++j)	u[v[j]]=max(u[v[j]],cnt[v[j]]);
			for(j=1;j<=v_sz;++j)	cnt[v[j]]=0;
			v_sz=0;
		}
		for(i=2;i<N;++i){
			ans+=u[i];
		}
		cout<<ans<<"\n";
		ans=0;
		memset(u,0,sizeof(u));
	}
	return 0;
}