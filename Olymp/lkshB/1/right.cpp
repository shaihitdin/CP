#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=100001;
int n,m,x,i,a[N];
int main(){
     
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
	 while(m--){
	  
	    scanf("%d",&x);
	    i=(upper_bound(a+1,a+n+1,x)-a);
	    --i;
	    if(a[i]==x)
	     printf("%d\n",i);
	    else
	     printf("0\n");
	 }
return 0;}