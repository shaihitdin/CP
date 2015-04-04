#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,k,a[100001],l,r,i,mid,last;
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+n+1);
	l = 0;
	r = a[1]+1;
	while(r-l>1){
		mid=(r+l)/2;
		i=1;
		last=0;
		while(i<=n && last<=k){
			last=max(last+mid,a[i]);
			++i;
//			cerr<<last<<" "<<i<<"\n";
		}
		if(last<=k){
			l=mid;
		}
		else{
			r=mid;
		}
//		cerr<<"\n\n\n";
	}
	printf("%d",l);
	return 0;
}