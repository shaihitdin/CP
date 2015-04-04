#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
const int N=100001;
using namespace std;
vector<int> in[N];
int l[N],r[N],ans[N];
int n,m,i,mx,j;
bool u[N];
int solve(int n, int m, int* l, int* r, int* ans) {
	for(i=1;i<n;++i){
		in[i].push_back(i-1);
	}
  in[n-1].push_back(0);
	for(i=0;i<m;++i){
	   in[r[i]].push_back(l[i]);
	}

	for(i=0;i<n;++i){
	     memset(u,0,sizeof(u));
	  for( j=0;j<in[i].size();++j){
	      u[ans[in[i][j]]]=1;
	  }
	  for(j=0;u[j];++j){}
	   ans[i]=j;
	}
	for(i=0;i<n;++i)
	   mx=max(mx,ans[i]+1);
return mx;}
int main(){
     freopen("in","r",stdin);
     freopen("out","w",stdout);
     scanf("%d %d",&n,&m);
     for(i=0;i<m;++i)
        scanf("%d %d",&l[i],&r[i]);
         printf("%d\n",solve(n,m,l,r,ans));
         for(i=0;i<n;++i)
          printf("%d ",ans[i]);
return 0;}
