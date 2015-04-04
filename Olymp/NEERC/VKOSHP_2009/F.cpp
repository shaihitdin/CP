#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,a[101],sum,i;
int main(){
	freopen("invaders.in","r",stdin);
	freopen("invaders.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum+=min(abs(m-1)+abs(m-1)+abs(n-m),abs(n-m)+abs(n-m)+abs(m-1));
	printf("%d",sum);
	return 0;
}