#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int d[50001],n,i,a[1001],j,tmp,tmp1,mult,p_ow,cnt=1;
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	while(1){
		scanf("%d",&n);
		if(n==0){
			return 0;
		}
		printf("Case #%d: ",cnt);
		++cnt;
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		memset(d,0,sizeof(d));
		sort(a+1,a+n+1);
		bool flag=0;
		for(i=0;i<=50000;++i){
			if(!d[i] && i!=0){
				printf("Cannot pay some amount\n");
				flag=1;
				break;
			}
			for(j=1;j<=n;++j){
				if(i+a[j]<=50000){
					if(d[i+a[j]])
						d[i+a[j]]=min(d[i+a[j]],d[i]+1);
					else
						d[i+a[j]]=d[i]+1;
				}
			}
		}
		if(flag)	continue;
		for(i=1;i<=50000;++i){
			tmp=0;
			tmp1=i;
			for(j=n;j>=1 && tmp1>0;){
				if(tmp1<a[j])	--j;
				else{
					tmp1-=a[j];
					++tmp;
				}
			}
			if(tmp1!=0 || d[i]!=tmp){
				flag=1;
//				cerr<<i<<" "<<tmp<<" "<<d[i]<<" "<<tmp1<<"\n";
				printf("Cannot use greedy algorithm\n");
				break;
			}
		}
		if(flag)	continue;
		printf("OK\n");
	}
	return 0;
}