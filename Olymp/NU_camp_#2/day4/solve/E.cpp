#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
#define mkp make_pair
#define NAME "rect."
const int N=3001;
int d1[N][N],d2[N][N],ans,d3[N][N],d4[N][N],n,m,i,j;
set <int> li,lj;
char a[N][N];
int main(){
	freopen(NAME"in","r",stdin);
	freopen(NAME"out","w",stdout);
	    cin>>n>>m;
	    for(i=1;i<=n;++i)
	    for(j=1;j<=m;++j)
	    	cin>>a[i][j];
	 li.insert(-1);
	 lj.insert(-1);
	    for(i=1;i<=n;++i)
	    for(j=1;j<=m;++j)
	      if(a[i][j]=='W'){
	          d3[i][j]=i-(*li.lower_bound(i-1));
	          d4[i][j]=j-(*lj.lower_bound(j-1));
	          cerr<<*li.lower_bound(i-1)<<" "<<*lj.lower_bound(j-1)<<"\n";	          
	      }
	      else{
	          li.insert(i-1);
	          lj.insert(j-1);
	      }

	      for(i=1;i<=n;++i){
	      for(j=1;j<=m;++j)
	        printf("%d ",d3[i][j]);
	        printf("\n");
		 }
		 printf("\n");
		 for(i=1;i<=n;++i){
	      for(j=1;j<=m;++j)
	        printf("%d ",d4[i][j]);
	        printf("\n");
		 }
return 0;}