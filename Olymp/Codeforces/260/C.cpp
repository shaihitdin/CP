#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100005;
long long n,x,y,d[N],i,tmp,flag[N],ans;
int main(){
	#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(i=1;i<=n;++i){
    	cin>>x;
    	++d[x];
    }
    for(i=1;i<=n;++i){
    	if(d[i]*i>d[i-1]*(i-1)+d[i+1]*(i+1)){
    		flag[i]=1;
    		flag[i-1]=0;
    		flag[i-2]=1;		
    	}	
    }
    for(i=1;i<=n;++i){
    	if(flag[i]){
    		--d[i];
    		ans+=i;
    		d[i-1]=0;
    		d[i+1]=0;
    	}
    }
    for(i=1;i<=n;++i){
    	ans+=(d[i]*i);
    }
    cout<<ans;
	return 0;
}