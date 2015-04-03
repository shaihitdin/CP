#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N=10001;
int n,k,i,j,pos[N],a[N],shift;
pair<int,int> b[N];
int u[N];
int ans1,ans2;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=mkp(a[i],i);
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;++i)	pos[b[i].S]=((i-1)/k);
	for(i=1;i<=n;++i){
	    shift=0;
		for(j=1;j<=n;++j){
			if(u[j])
				if(j>i && u[j]<=i) --shift;
		}
		if(pos[i]>(i-1+shift)/k){
			for(j=1;j<=n;++j){
				if(((j-1)/k==pos[i]) && !u[j]){
					u[j]=i;
					++ans1;
					break;
				}
			}
		}
	}
	memset(u,0,sizeof(u));
	for(i=n;i>=1;--i){
	    shift=0;
		for(j=1;j<=n;++j){
			if(u[j])
				if(j<i && u[j]>=i) ++shift;
		}
		if(pos[i]<(i-1+shift)/k){
			for(j=n;j>=1;--j){
				if(((j-1)/k==pos[i]) && !u[j]){
					u[j]=i;
					++ans2;
					break;
				}
			}
		}
	}
	printf("%d",min(ans1,ans2));
	return 0;
}