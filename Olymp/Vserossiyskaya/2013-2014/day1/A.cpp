#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int N=100001,inf=1000000009;
unsigned int n,i,l[N],lw[N],r[N],rw[N],whre,ans;
unsigned int dfs(int v){
	if(v==whre)
	 return 1;
	 int tmp=inf;
	 if(l[v]!=0)
	      tmp=dfs(l[v]);
	 cerr<<l[v]<<" "<<tmp<<"\n";
	 if(tmp<=lw[v]){
	 	int tmp2=0;
	   if(rw[v]>lw[v])
	   	  rw[v]-=rw[v]-lw[v];
	   else
	     tmp2+=lw[v]-rw[v];
		  if(tmp2<tmp){
		       
		  }
		   if(0==rw[v])

	   return tmp+tmp1;
	 }
	 tmp=inf;
	 if(r[v]!=0)
	 	 tmp=dfs(r[v]);
	 cerr<<r[v]<<" "<<tmp<<"\n";
	 if(tmp<=rw[v]){
	 	int tmp2=0;
	 	if(lw[v]<=rw[v])
	 	  lw[v]-=lw[v]-rw[v]+1;
	 	else
	   	tmp2+=rw[v]-lw[v];
	      if(tmp2<tmp){
	      	
	      }
	       if(0==lw[v])

	     return tmp+tmp1;
	 }
	 
	 return inf;
}
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	 scanf("%d",&n);
	 for(i=1;i<=n;++i)
	 	scanf("%d %d %d %d",l+i,lw+i,r+i,rw+i);
	 scanf("%d",&whre);
	 ans=dfs(1);
	 if(ans==inf)
	  printf("-1");
	 else
 	  printf("%d",ans);
return 0;}