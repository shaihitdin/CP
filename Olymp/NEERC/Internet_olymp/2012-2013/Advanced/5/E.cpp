#include<iostream>
#include<stdio.h>
using namespace std;
bool d[6][1000001];
int n,t,m;
inline void	rec(int 
int main(){
	freopen("grievous.in","r",stdin);
	freopen("grievous.out","w",stdout);
	cin>>n>>t>>m;
	if(n==1){
		rec(m,0,0,0,0,t);
	}
	if(n==2){
		rec(m,m,0,0,0,t);	
	}
	if(n==3){
		rec(m,m,m,0,0,t);
	}
	if(n==4){
		rec(m,m,m,m,0,t);
	}
	if(n==5){
		rec(m,m,m,m,m,t);
	}
	return 0;
}