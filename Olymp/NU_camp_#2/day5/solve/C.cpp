#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include"grader.h"
#include<map>
#include<vector>
#include<iostream>
using namespace std;
#define mkp make_pair
#define inf 1000000009
const int N=300001;
int a[N],b[N],c[N],i,j,answers[N],n,m,q,p[N],d[N];
vector<pair<int,int > > g[N];
map<pair<int,int> ,int > map1;
int find_set(int v){
   if(v==p[v])
   return v;
   return p[v]=find_set(p[v]);
}
void union_sets (int x, int y) {
	x = find_set (x);
	y = find_set (y);
	if(x==y)
	return ;
	if(rand()&1){
	  p[x]=p[y];
	}
	else
	  p[y]=p[x];

	  return ;
}
void solve(int n, int m, int q, int *a, int *b, int *c,int *answers){
		srand(time(0));
			d[m]=m;
			for(j=0;j<n;++j)
 			  p[j]=j;

		for(i=m-1;i>=0;--i){
 			 		if(find_set(a[i])==find_set(b[i])){
 			 		  d[i]=map1[mkp(find_set(a[i]),find_set(b[i]))];

 			 		  cerr<<find_set(a[i])<<" "<<find_set(b[i])<<"\n";
 			      	 }
 			      	 else{
 			      	    d[i]=d[i+1];
 			      	 }
 			 		  map1[mkp(find_set(a[i]),find_set(b[i]))]=i;
			 		  map1[mkp(find_set(b[i]),find_set(a[i]))]=i;

 			      	 union_sets(a[i],b[i]);
		
		}
 		for(i=0;i<m;++i){
 			answers[i]=d[c[i]];
 		} 

return ;}

int main(){
         freopen("in","r",stdin);
         freopen("out","w",stdout);
           cin>>n>>m>>q;
            for(i=0;i<m;++i)
             cin>>a[i]>>b[i];
             for(i=0;i<q;++i)
              cin>>c[i];
            solve(n,m,q,a,b,c,answers);
            for(i=0;i<q;++i)
             cout<<answers[i]<<" ";
           
return 0;}
