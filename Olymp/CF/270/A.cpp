#include<iostream>
#include<stdio.h>
using namespace std;
int n,i,j;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    cin>>n;
    for(i=n-4;i>=1;--i){
    	bool flag=0;
    	for(j=2;j*j<=i;++j){
    		if(i%j==0){
    			flag=1;
    			break;
    		}
    	}
    	if(!flag)	continue;
    	for(j=2;j*j<=n-i;++j){
    		if((n-i)%j==0){
    			cout<<i<<" "<<n-i<<"\n";
    			return 0;
    		}
    	}
    }
	return 0;
}