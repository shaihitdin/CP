#include<iostream>
#include<stdio.h>
using namespace std;
int ans,n,i,a[100001],lst_z;
int main(){
	scanf("%d",&n);	
	for(i=1;i<=n;++i){
	  scanf("%d",&a[i]);
	  if(a[i]==0){
	   ans=max(ans,i-1-lst_z);
	   lst_z=i;
	  }
	 }
	 ans=max(ans,(lst_z!=n? n : 0 )-lst_z);
	printf("%d",ans);
return 0;}