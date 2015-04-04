#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int N=100001;
int i,n,a[N],d[N],ans,now;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
    	for(i=1;i<=n;++i){
    		if(a[i]>a[i-1])
    		  d[i]=d[i-1]+1;
    		else
    		  d[i]=1;
    	}
    	a[0]=-1000000009;
    	for(i=2;i<n;++i){
    		if(d[i]==1 ){
    			now=d[i-1]+1;
    			a[i]=a[i-1]+1;
			++i;
    		    	  while(i<=n && a[i]>a[i-1]){
    		    	    ++now;
    		    	    ++i;
    		    	  }
    		    	  --i;
    		    	  ans=max(ans,now);
    		}
    		
    	}
    	for(i=1;i<=n;++i)
    	  ans=max(ans,d[i]);
    	printf("%d",ans);
return 0;}