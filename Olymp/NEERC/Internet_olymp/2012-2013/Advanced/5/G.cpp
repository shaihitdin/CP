#include<iostream>
#include<vector>
#include<stdio.h>
#include<set>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int inf=100000001;
vector <pair <int, pair<int,int> > > v[501][501];
char a[501][501];
int a[501][501];
set<pair<int, pair<int,int> > > st;
int main(){
	freopen("icy.in","r",stdin);
	freopen("icy.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s1>>s2;
	cin>>f1>>f2;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			cin>>c[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(i>1){
				if(a[i][j]=='I'){
					if(a[i][j]=='I' && c[i-1][j]==c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));					
					}
					if(a[i][j]=='I' && c[i-1][j]<c[i][j]){
						k=i-1;
						while(k>=1 && a[k][j]=='I')	--k;
						if(a[k][j]=='B'){
							continue;
						}
						++k;
						v[i][j].push_back(mkp(i-k,mkp(k,j)));
					}
					if(a[i-1][j]=='S' && c[i-1][j]<=c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}					
				}
				if(a[i][j]=='S'){
					if(a[i-1][j]=='B'){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}
					if(a[i-1][j]=='S' && c[i-1][j]<=c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}					
					if(a[i-1][j]=='I' && c[i-1][j]<=c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}					
				}
				if(a[i][j]=='B'){
					if(a[i-1][j]=='B'){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}
					if(a[i-1][j]=='S'){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}
				}
			}
			if(j>1){
				if(a[i][j]=='I'){
					if(a[i][j-1]=='I' && c[i][j-1]==c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i,j-1)));					
					}
					if(a[i][j-1]=='I' && c[i][j-1]<c[i][j]){
						k=j-1;
						while(k>=1 && a[i][k]=='I')	--k;
						if(a[i][k]=='B'){
							continue;
						}
						++k;
						v[i][j].push_back(mkp(j-k,mkp(i,k)));
					}
					if(a[i][j-1]=='S' && c[i][j-1]<=c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}					
				}
				if(a[i][j]=='S'){
					if(a[i-1][j]=='B'){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}
					if(a[i-1][j]=='S' && c[i-1][j]<=c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}					
					if(a[i-1][j]=='I' && c[i-1][j]<=c[i][j]){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}					
				}
				if(a[i][j]=='B'){
					if(a[i-1][j]=='B'){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}
					if(a[i-1][j]=='S'){
						v[i][j].push_back(mkp(1,mkp(i-1,j)));
					}
				}			
			}
			if(i<n){
			
			}
			if(j<n){
			
			}
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			d[i][j]=inf;
		}
	}
	d[s1][s2]=0;
	st.insert(mkp(0,mkp(s1,s2)));
	while(st.size()){
		int v1=st.begin()->S->F,v2=st.begin()->S->S;
		st.erase(st.begin());
		for(int i=0;i<v[v1][v2].size();++i){
			int cost=v[v1][v2].F,to1=v[v1][v2].S.F,to2=v[v1][v2].S.S;
			if(d[to1][to2]>d[v1][v2]+cost){
				st.erase(mkp(d[to1][to2],mkp(to1,to2)));
				d[to1][to2]=d[v1][v2]+cost;
				st.insert(mkp(d[to1][to2],mkp(to1,to2)));
			}
		}
	}
	if(d[f1][f2]==inf){
		cout<<-1;
	}
	cout<<d[f1][f2];
	return 0;
}