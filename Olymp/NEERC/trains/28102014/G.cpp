#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int N=300001;
long long mnans=1000000000000000,old_a,mnl,tmp,sum_seg[N],res,a[N],n,k,i,mn,prev=-mnans,ans,ms[N],tms,j;
int main(){
/*
	freopen("in","r",stdin);
	freopen("out","w",stdout);
*/
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
		sum_seg[i]=sum_seg[i-1]+a[i];
	}
	for(i=1;i<=n;++i)	mn=min(mn,a[i]);
/*		
		if(res>=0){
			ans+=min(a[i]-mn,res+1);
			old_a=a[i];
			a[i]-=min(a[i]-mn,res+1);
			res-=min(old_a-mn,res+1);
		}
*/
	for(i=k;i<=n;++i){
		res=(sum_seg[i]-sum_seg[i-k])-tms;
		for(j=i;res>=0;--j){
		    ans+=min(a[j]-mn,res+1);
			old_a=a[j];
			ms[j]+=min(a[j]-mn,res+1);
			tms+=min(a[j]-mn,res+1);
			a[j]-=min(a[j]-mn,res+1);
			res-=min(old_a-mn,res+1);
		}
		tms-=ms[i-k+1];		
	}
	printf("%I64d\n",ans);
	for(i=1;i<=n;++i){
		printf("%I64d ",a[i]);
	}
	return 0;
}