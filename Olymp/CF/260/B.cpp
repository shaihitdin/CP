#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int N=100001;
int n,x,y,d[N],i,tmp;
string s;
int main(){
	#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin>>s;
    if(s.size()>1){
   		x=s[s.size()-2]-'0';
   		y=s[s.size()-1]-'0';
   		if((x==y && x==0) || (x*10+y)%4==0){
   			puts("4");
   		}
   		else{
   			puts("0");
   		}
   	}
   	else{
   		if(s=="4" || s=="0" || s=="8"){
   			puts("4");
   		}
   		else{
   			puts("0");
   		}
   	}
    return 0;
}