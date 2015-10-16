#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
const int N=2002;
char a[N][N];
int n,m,k,i,j;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	     scanf("%d %d %d",&n,&m,&k);

	     for(i=1;i<=n;++i){
	       for(j=1;j<=m;++j)
	         cin>>a[i][j];
	     }
	     
	        for(i=1;i<=m;++i){
	     	int ans=0;
	     	cerr<<i<<":";
	        for(j=1;j<=n;++j){
	        		int step=j-1;

	            if(i-step>=1 && a[j][i-step]=='R')
	               ++ans;
	            if(i+step<=m && a[j][i+step]=='L')
	               ++ans;
			  if(j-step>=1 && a[j-step][i]=='D')
			     ++ans;
			  if(j+step<=n && a[j+step][i]=='U')
			     ++ans;
	        }
	        cerr<<"\n";
	        printf("%d ",ans);
	     }
return 0;}