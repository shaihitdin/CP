#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int M=11,N=1001,inf=1000000001;
#define F first
#define S second
#define mkp make_pair
int n,m,k,w;
char a[N][M][M];
vector<int> v[N];
vector<pair<int,pair<int,int> > > edge;
int p[N];
int get(int v){
   if(v==p[v])
    return p[v];
     return p[v]=get(p[v]);
}
int unite(int x,int y,int cost){
   if(
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
		cin>>n>>m>>k>>w;
		for(q=1;q<=k;++q){
			for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
			 cin>>a[q][i][j];
		}
		for(q=1;q<=k;++q){
		  for(e=1;e<=k;++e){
		  	diff=0;
			for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
			 if(a[q][i][j]!=a[w][i][j])
			   ++diff;
			edge.push_back(mkp(diff*w,q,e));
		  }
		  edge.push_back(mkp(n*m,0,q));
		}
		for(i=0;i<=n;++i)
		 p[i]=i;

			sort(edge.begin(),edge.end());
			for(i=0;i<edge.size();++i){
			     cost=edge.F;
			     from=edge.S.F;
			     to=edge.S.S;
			     if(p[from]!=p[to]){
			        
			     }
			}
return 0;}