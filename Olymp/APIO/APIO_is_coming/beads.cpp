#include<iostream>
#include<stdio.h>
using namespace std;
int n,x[201],y[201],cost[201],col[201],pairr[201],step,i,j,ans,tmp;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n;
	for(i=1;i<n;++i){
		cin>>x[i]>>y[i]>>cost[i];
	}
	for(step=1;step<n;++step)
	for(i=1;i<n;++i)
	for(j=1;j<n;++j){
	  if(i==j)
	   continue;
	   if(x[i]==x[j] || x[i]==y[j] || y[i]==x[j] || y[i]==y[j]){
	     if(pairr[i] || pairr[j]){
	     	tmp=0;
	     		if(pairr[i])
	     		 tmp+=cost[i]+cost[pairr[i]];
	     		if(pairr[j])
	     		 tmp+=cost[j]+cost[pairr[j]];
	     	if(tmp<cost[i]+cost[j]){
	     	  	 ans-=cost[pairr[i]],ans-=cost[pairr[j]];
	        		 ans+=cost[i]+cost[j];
	        		 pairr[i]=j,pairr[j]=i;
	        	}
		}
	     else{
	      ans+=cost[i]+cost[j];
		 pairr[i]=j;
		 pairr[j]=i;
	     }
	   }
	}
	cout<<ans;
return 0;}