#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    /*#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    */
    int a,b,v;
    cin>>a>>b>>v;
    v-=a;
    int tmp=v/(a-b);
    tmp+=(v%(a-b)!=0);
    ++tmp;
   	cout<<tmp;
	return 0;
}