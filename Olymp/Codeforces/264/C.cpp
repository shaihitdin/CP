#include<iostream>
#include<stdio.h>
using namespace std;
long long n,a[2001][2001],pos1,pos2,pos3,pos4,ans1=-1,ans2=-1,i,j;
long long d1[2001*2],d2[2001*2]; //d1 from left to right, d2 from right to left
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d",&n);
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			scanf("%I64d",&a[i][j]);
			d1[i+n-j]+=a[i][j];
			d2[i+j-1]+=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(((i&1)+(j&1))%2==0){
				if(d1[i+n-j]+d2[i+j-1]-a[i][j]>ans1){
					ans1=d1[i+n-j]+d2[i+j-1]-a[i][j];
					pos1=i;
					pos2=j;
				}
			}
			else{
				if(d1[i+n-j]+d2[i+j-1]-a[i][j]>ans2){
					ans2=d1[i+n-j]+d2[i+j-1]-a[i][j];
					pos3=i;
					pos4=j;
				}			
			}
		}
	}
	printf("%I64d\n%I64d %I64d %I64d %I64d",ans1+ans2,pos1,pos2,pos3,pos4);
return 0;
}