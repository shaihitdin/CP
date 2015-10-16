#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100001;
int n,x,y,d[N],i,tmp;
int main(){
	#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(i=1;i<=n;++i){
    	cin>>x>>y;
    	d[x]=max(d[x],y);
    }
    for(i=1;i<=n;++i){
    		if(d[i]<tmp){
    			puts("Happy Alex");
    			return 0;
    		}
    		tmp=max(tmp,d[i]);
    }
    puts("Poor Alex");
	return 0;
}