#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
long long n,k,a[100001],i,j,l,ans1=1000000001,ans2=1000000001,ans3;
map<long long,long long> m;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	if(n<=100){
		for(j=1;j<=n;++j){
			for(i=j+1;i<=n;++i){
				long long cnt=0,d=(a[j]-a[i])/(j-i);
				for(l=2;l<=n;++l){
					if(a[l]-a[l-1]!=d) ++cnt;
				}
				if(cnt<=k){
					if((ans1>(a[j]-(d*(j-1)))) || (ans1==(a[j]-(d*(j-1))) && (d<ans2))){
						ans1=(a[j]-(d*(j-1)));
						ans2=d;
					}
				}
			}
		}
		a[1]=ans1;
		for(i=2;i<=n;++i){
			a[i]=a[i-1]+ans2;
		}
		for(i=1;i<=n;++i){
			printf("%I64d ",a[i]);
		}
		return 0;
	}
	else{
		for(i=2;i<=n;++i){
			++m[a[i]-a[i-1]];
		}
		for(i=2;i<=n;++i){
			if(m[a[i]-a[i-1]]>ans3){
				ans3=m[a[i]-a[i-1]];
			}
		}
		for(i=2;i<n;++i){
			if(m[a[i]-a[i-1]]==ans3 && m[a[i+1]-a[i]]==ans3){
					if(ans1>(a[i]-((a[i]-a[i-1])*(i-1)))){
						ans1=(a[i]-((a[i]-a[i-1])*(i-1)));
						ans2=a[i]-a[i-1];
					}			
			}
		}
		a[1]=ans1;
		for(i=2;i<=n;++i){
			a[i]=a[i-1]+ans2;
		}
		for(i=1;i<=n;++i){
			printf("%I64d ",a[i]);
		}
		return 0;
	}
}