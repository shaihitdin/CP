#include<iostream>
#include<stdio.h>
using namespace std;
long long t,l,r,tmp,i;
inline bool bit(long long mask,long long pos){
	return (mask&((1ll<<pos)));
}
inline long long cnt(long long mask){
	long long res=0;
	for(i=0;(1ll<<i)<=mask;++i){
		if(bit(mask,i))	++res;
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>t;
	++t;
	while(--t){
		cin>>l>>r;		
		for(i=0;(l+(1ll<<i))<=r;++i){			
			if(bit(l,i)){
				continue;
				/*
				if((l+((1ll<<(i+1))))>r || cnt((l+((1ll<<(i+1)))))<=(cnt(l))){
					continue;
				}
				else{
					l+=(1ll<<(i+1));				
				}
				*/
			}
			else{
				l+=(1ll<<i);
			}
		}
		cout<<l<<"\n";
	}
	return 0;
}