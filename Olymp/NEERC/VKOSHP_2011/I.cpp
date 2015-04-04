#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const long long N=501,M=1000001,inf=1000000009;
struct edge{
	long long y,cap,cost,flow;
};
edge e[M];
long long sz;
vector<long long> v[N];
long long ans_arr[N],p_e[N],p[N],x; 
inline void add_edge(long long x,long long y,long long cap,long long cost){
	edge e1={y,cap,cost,0};
	edge e2={x,0,-cost,0};
	v[x].push_back(sz);
	e[sz++]=e1;
	v[y].push_back(sz);
	e[sz++]=e2;
}
set< pair<long long,long long> > st;
long long d[N],phi[N];
long long s,f,n;
inline bool dijkstra(){
	for(long long i=1;i<=n+n+2;++i){
		d[i]=inf;
	}	
	d[s]=0;
	st.insert(mkp(0,s));
	while(st.size()){
		long long from=st.begin()->S;
		st.erase(st.begin());
		for(long long i=0;i<v[from].size();++i){
			long long id=v[from][i],to=e[id].y;
			if(e[id].cap > e[id].flow && d[to]>d[from]+e[id].cost+phi[from]-phi[to]){
				p_e[to]=id;
				p[to]=from;
				st.erase(mkp(d[to],to));
				d[to]=d[from]+e[id].cost+phi[from]-phi[to];
				st.insert(mkp(d[to],to));
			}
		}
	}
	for(long long i=1;i<=n+n+2;++i){
		phi[i]=min(inf,phi[i]+d[i]);
	}
	return d[f]!=inf;
}
inline long long MCMF(){
	long long ans=0;
	while(dijkstra()){
		long long flow=inf;
		for(long long v=f;v!=s;flow=min(flow,e[p_e[v]].cap-e[p_e[v]].flow),v=p[v]);
		for(long long v=f;v!=s;e[p_e[v]].flow+=flow,e[p_e[v]^1].flow-=flow,ans+=(e[p_e[v]].cost*flow),v=p[v]);
	}
	return ans;
}
long long pos[N][3],dist[N][N];
int main(){
	freopen("teams.in","r",stdin);
	freopen("teams.out","w",stdout);
	scanf("%I64d",&n);
	for(long long i=1;i<=n+n;++i){
		scanf("%I64d",&x);
		if(pos[x][1]!=0)
			pos[x][2]=i;
		else
			pos[x][1]=i;
	}
	for(long long i=1;i<=n;++i){
		for(long long j=1;j<=n;++j){
			dist[i][j]=min(abs(pos[j][1]-i)+abs(pos[j][2]-(n+i)), abs(pos[j][2]-i)+abs(pos[j][1]-(n+i)));
		}
	}
	s=n+n+1;
	f=n+n+2;
	for(long long i=1;i<=n;++i)	add_edge(s,i,1,0);
	for(long long i=1;i<=n;++i)	add_edge(n+i,f,1,0);
	for(long long i=1;i<=n;++i){
		for(long long j=1;j<=n;++j){
			add_edge(i,j+n,1,dist[j][i]);
		}
	}
	MCMF();
	for(long long i=1;i<=n;++i){
		for(long long j=0;j<v[i].size();++j){
			long long id=v[i][j];
			if(e[id].flow==1){
				ans_arr[e[id].y-n]=i;
			}
		}
	}
	for(long long i=1;i<=n;++i){
		printf("%I64d ",ans_arr[i]);
	}
	for(long long i=1;i<=n;++i){
		printf("%I64d ",ans_arr[i]);
	}

	return 0;
}