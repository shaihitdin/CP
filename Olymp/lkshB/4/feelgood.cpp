#include<iostream>
#include<stdio.h>
using namespace std;
const int N=(1<<17)+1;
long long ans=-1,ansi,ansj;
long long a[N];
long long sum[N];
long long n,i,j;
long long st[N],stq;
long long l[N],r[N];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%I64d",&n);
	for(i=1;i<=n;++i)
	 scanf("%I64d",&a[i]);
	for(i=1;i<=n;++i)
	 sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;++i){
	  while(stq>0 && a[i]<=a[st[stq]]) --stq;
	  if(stq==0) l[i]=1;
	  else l[i]=st[stq]+1;
	  ++stq;
	  st[stq]=i;
	}
	stq=0;
	for(i=n;i>=1;--i){
	  while(stq>0 && a[i]<=a[st[stq]]) --stq;
	  if(stq==0) r[i]=n;
	  else r[i]=st[stq]-1;
	  ++stq;
	  st[stq]=i;	
	}
	for(i=1;i<=n;++i)
	  if((sum[r[i]]-sum[l[i]-1])*a[i]>ans) 
	   ans=(sum[r[i]]-sum[l[i]-1])*a[i],ansi=l[i],ansj=r[i];
	
	printf("%I64d\n%I64d %I64d",ans,ansi,ansj);
return 0;}