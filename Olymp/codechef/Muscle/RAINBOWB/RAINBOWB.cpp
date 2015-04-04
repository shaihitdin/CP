#include<iostream>
#include<stdio.h>
using namespace std;
int n,ans,v[11];
inline void rec(int n,int lvl){
	if(lvl==8){
		if(n==0)
			++ans;
			return;
		/*
		for(int i=1;i<=7;++i){
			cout<<v[i]<<" ";
		}                   
		cout<<"\n";
		*/
		return;	
	}
	if(lvl==7){
		for(int i=1;i<=n;++i){
			v[lvl]=i;
			rec(n-i,lvl+1);
		}
		return;	
	}
	for(int i=1;i*2<=n;++i){
		v[lvl]=i*2;
		rec(n-i*2,lvl+1);
	}
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n;
	rec(n,1);
	cout<<ans;
return 0;
}