#include<iostream>
#include<stdio.h>
using namespace std;
int ansa,ansb,n,a,b,p,tot,lose;
bool u[11];
inline void dfs(int v){
	if(v==n){
		++ansa;
		return;
	}
	if(v==0){
		++ansb;
		return;
	}
	u[v]=1;
	if(!u[v+1])
		for(int i=1;i<=p;++i)	dfs(v+1);
	if(!u[v-1])
		for(int i=p+1;i<=100;++i)	dfs(v-1);
	u[v]=0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>a>>b>>p;
	n=a+b;
	dfs(a);
	tot=ansa+ansb;
	lose=ansb;
	for(int i=2;i*i<=min(tot,lose);++i){
		if(!(tot%i) && !(lose%i)){
			tot/=i;
			lose/=i;
			i=1;
		}
		if((i+1)*(i+1)>min(tot,lose)){
			if(!(tot%lose)){
				tot/=lose;
				lose/=lose;
				i=1;			
			}
		}
	}
	cout<<lose<<"/"<<tot;
	return 0;
}