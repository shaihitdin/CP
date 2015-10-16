#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const long long N=100001,inf=1000000009*1ll*100001;
vector<pair<long long,long long> > a[N];
set<pair<long long,long long> > st;
long long x,n,m,i,y,z,ans,k,to;
long long d[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d %I64d %I64d",&n,&m,&k);
	for(i=1;i<=m;++i){
		scanf("%I64d %I64d %I64d",&x,&y,&z);
		a[x].push_back(mkp(y,z));
		a[y].push_back(mkp(x,z));
	}
	for(i=2;i<=n;++i)
		d[i]=inf;
	st.insert(mkp(d[1],1*1ll));
	while(!st.empty()){
		x=st.begin()->second;
		st.erase(st.begin());
		for(i=0;i<a[x].size();++i){
			to=a[x][i].F*1ll;
			if(d[to]>(d[x]*1ll)+(a[x][i].S*1ll)){
				st.erase(mkp(d[to],to));
				d[to]=(d[x]*1ll)+(a[x][i].S*1ll);
				st.insert(mkp(d[to],to));
			}
		}
	}
	for(i=1;i<=k;++i){
		scanf("%I64d %I64d",&x,&y);
		if(d[x]<=y){
			++ans;
		}
	}
	printf("%I64d",ans);
return 0;}