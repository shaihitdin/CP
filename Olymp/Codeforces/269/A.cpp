#include<iostream>
#include<stdio.h>
using namespace std;
int i,x,flag1,flag,a[11];
int main(){
	#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    for(i=1;i<=6;++i){
    	cin>>x;
    	++a[x];
    }
    for(i=1;i<=9;++i)	if(a[i]>=4) a[i]-=4,flag=1;
    for(i=1;i<=9;++i)	if(a[i]==2) flag1=1;
    if(flag){
    	if(flag1){
    		cout<<"Elephant";
    	}
    	else{
    		cout<<"Bear";
    	}
    }
    else{
    	cout<<"Alien";
    }
	return 0;
}