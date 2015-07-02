#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
bool u[1001];
long long a[1001][1001],n,j;
long long l=-1,r=1000000001,mid;
void dfs(int v){
   u[v]=1;
   for(int i=1;i<=n;++i)
     if(!u[i] && a[v][i]<=mid)
        dfs(i);
}
void dfs1(int v){
   u[v]=1;
    for(int i=1;i<=n;++i)
     if(!u[i] && a[i][v]<=mid)
        dfs1(i);
}
bool ok(){
   memset(u,0,sizeof(u));
   dfs(1);
   for(int i=1;i<=n;++i)
     if(!u[i])
      return 0;
   memset(u,0,sizeof(u));
   dfs1(1);
   for(int i=1;i<=n;++i)
     if(!u[i])
      return 0;

   return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d",&n);
	if(n==1){	printf("0\n");return 0;}
	for(int i=1;i<=n;++i)
	 for(j=1;j<=n;++j)
	  scanf("%I64d",&a[i][j]);
	 while(r-l>1){
	    mid=(r+l)>>1;
	    if(ok()){
	       r=mid;
	    }
	    else
	       l=mid;
	 }
	 printf("%I64d",r);
return 0;}