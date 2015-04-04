#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,i,d[100001],a[100001];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1); 
	a[0]=-1000000001;
	for(i=1;i<=n;++i){	
		d[i]=d[i-1]+(a[i]-a[i-1]);
		if(i-2>=0){
			d[i]=min(d[i-2]+(a[i]-a[i-1]),d[i]);
		}
		cerr<<d[i]<<" ";
	}
	printf("%d",d[n]);
	return 0;
}