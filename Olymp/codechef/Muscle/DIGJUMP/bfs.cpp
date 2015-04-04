#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;
const int N=100010;
/*used*/bool u[N],u2[256];
/*it*/int i,n;
/*num*/int a[N];
/*distance*/int d[N];
/*queue*/int q[N*100],sq=0,eq=0;
vector<int> v[256];
char h[N];
inline int to_i(char x){
	return x-'0';
}
inline void insert(int g,int p_d){
	u[g]=1;
	d[g]=p_d+1;
	q[eq++]=g;
}
int main(){
	 scanf("%s",h);
	 n=strlen(h);
	 char m;
		for(i=1;i<=n;++i){
		  m=h[i-1];
		  a[i]=to_i(m);
	       v[to_i(m)].push_back(i);
		}
	 q[eq++]=1;
	 d[1]=0;
	 u[1]=1;
	 while(sq!=eq){
	     int x=q[sq++];
	     if(!u2[a[x]]){
	        for(i=0;i<v[a[x]].size();++i){
	          if(!u[v[a[x]][i]]){
	             insert(v[a[x]][i],d[x]);
	          }
	        }
	        u2[a[x]]=1;
	     }
	     if(x-1>=1 && !u[x-1])
	      insert(x-1,d[x]);
	     if(x+1<=n && !u[x+1])
 		 insert(x+1,d[x]);
	 }
	 printf("%d",d[n]);
return 0;}