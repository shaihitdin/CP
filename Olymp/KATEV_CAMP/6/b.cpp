#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<assert.h>
using namespace std;
const int inf=1000000001;
#define mkp make_pair
#define F first
#define S second
int d[5001],n,cost,m,s1,s2,i,x,y,j,k,f1,f2,v1,to1,p[5001],cnt,fi,fj,si,sj,s,f;
vector<pair<int,int> > v[5001];
set<pair<int,int > > st;
vector<int> ans;
map<pair<int,int>, int> mp;
pair<int,int> e[5001];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d%d%d%d%d",&n,&m,&s1,&s2,&f1,&f2);
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		mp[mkp(x,y)]=++cnt;
		mp[mkp(y,x)]=++cnt;
		e[cnt-1]=mkp(x,y);
		e[cnt]=mkp(y,x);		
	}
	for(i=1;i<=cnt;++i){
		for(j=1;j<=cnt;++j){
			if(i==j)	continue;
			if(((i&1)) && (i+1==j))	continue;
			if((!(i&1)) && (i-1==j))	continue;
			fi=e[i].F;
			si=e[i].S;
			fj=e[j].F;
			sj=e[j].S;
			if((fi==fj && mp[mkp(si,sj)]) || (si==sj && mp[mkp(fi,fj)]))
				v[i].push_back(mkp(1,j));			
			if(fi==sj || si==fj)
				v[i].push_back(mkp(2,j));
			if((mp[mkp(fi,fj)] && mp[mkp(si,sj)]))
				v[mp[mkp(fi,fj)]].push_back(mkp(2,mp[mkp(si,sj)]));
		}
	}
	for(i=1;i<=cnt;++i)
		d[i]=1000000000;
	for(i=1;i<=cnt;++i){
		if(e[i]==mkp(s1,s2))
			s=i;
	}
	d[s]=0;
	st.insert(mkp(0,s));
	while(st.size()){
		v1=(*st.begin()).S;
		st.erase(st.begin());
		for(i=0;i<v[v1].size();++i){
			to1=v[v1][i].S;
			cost=v[v1][i].F;
			if(d[to1]>d[v1]+cost){
				st.erase(mkp(d[to1],to1));
				d[to1]=d[v1]+cost;
				p[to1]=v1;
				st.insert(mkp(d[to1],to1));
			}
		}
	}
	for(i=1;i<=cnt;++i){
		if(e[i]==mkp(f1,f2))
			f=i;
	}
	v1=f;
	/*
	for(i=1;i<=cnt;++i){
		cerr<<i<<" "<<p[i]<<"\n";
	}
	*/
	for(; v1!=s; v1=p[v1]){
//		cerr<<v1<<" "<<p[v1]<<" ";
		ans.push_back(v1);
	}	
	ans.push_back(s);
	reverse(ans.begin(),ans.end());
	printf("%d %d\n",d[f],ans.size());
	for(i=0;i<ans.size();++i){
		printf("%d %d\n",e[ans[i]].F,e[ans[i]].S);
	}
	return 0;
}