#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<string.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
const int N=2001,inf=1000000001;
int n,i,j,a[N][N],x,k,cnt,p,pmn,d[N];
pair<int,pair<int,int> > l_e[N*N];
vector<int> e[N];
int sz;
int u[N];
inline void dfs(int v){
	u[v]=1;
	for(int i=0;i<e[v].size();++i){
		if(!u[e[v][i]]){
			d[e[v][i]]=d[v]+a[v][e[v][i]];
			dfs(e[v][i]);
		}
	}
}
/*
inline void check(){
	for(int v=1;v<=n;++v){
		memset(u,0,sizeof(u));
		memset(d,0,sizeof(d));
		dfs(v);
		for(j=1;j<=n;++j){
			if(d[j]!=a[v][j]){
//				cerr<<d[j]<<" "<<a[v][j]<<"\n";
				cout<<"NO";
				return;
			}
		}
	}
	cout<<"YES";
	return;
}
*/
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(i=1;i<=n;++i)
    	for(j=1;j<=n;++j){
    		cin>>a[i][j];
    		l_e[++sz]=mkp(a[i][j],mkp(i,j));
    		if((i==j && a[i][j]!=0) || (i!=j && a[i][j]==0)){
    			cout<<"NO";
    			return 0;
    		}
    	}
    for(i=1;i<=n;++i){
    	for(j=1;j<=n;++j){
    		if(a[i][j]!=a[j][i]){
    			cout<<"NO";
    			return 0;
    		}
    	}
    }
    sort(l_e+1,l_e+sz+1);
    for(i=sz;i>=1;--i){
    	x=l_e[i].S.F;
    	if(u[x])	continue;
    	if(n-1==cnt){
    		break;
    	}
    	pmn=inf;
    	for(j=1;j<=n;++j){
    		if(u[j] || x==j)	continue;
    		if(pmn>a[x][j]){
    			pmn=a[x][j];
    			p=j;
    		}
    	}
    	bool flag=1;
    	for(k=1;k<=n;++k){
    		if(u[k])	continue;
    		if(k==x)	continue;
    		if(a[x][k]!=a[x][p]+a[p][k]){
    			flag=0;
    		}
    	}
    	if(flag==1){
    		u[x]=1;
			e[x].push_back(p);
			e[p].push_back(x);    		
    	}
    	if(!u[x]){
    		cout<<"NO";
    		return 0;
    	}
    	++cnt;
    }
    cout<<"YES";
    //check();
  	return 0;
}