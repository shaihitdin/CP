#include<stdio.h>
#include<algorithm>
using namespace std;
int t,r,g,b,m,tmp1,tmp2,tmp3,i,x,tmp;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&t);
	++t;
	while(--t){
		scanf("%d%d%d%d",&r,&g,&b,&m);
		tmp1=tmp2=tmp3=0;
		for(i=1;i<=r;++i){
			scanf("%d",&x);
			tmp1=max(tmp1,x);
		}
		for(i=1;i<=g;++i){
		    scanf("%d",&x);
			tmp2=max(tmp2,x);
		}
		for(i=1;i<=b;++i){
			scanf("%d",&x);
			tmp3=max(tmp3,x);
		}
		for(i=1;i<=m;++i){
			tmp=max(tmp1,max(tmp2,tmp3));
			if(tmp==tmp1){
				tmp1/=2;
				continue;
			}
			if(tmp==tmp2){
				tmp2/=2;
				continue;
			}
			if(tmp==tmp3){
				tmp3/=2;
				continue;
			}
		}
		tmp=max(tmp1,max(tmp2,tmp3));
		printf("%d\n",tmp);
	}
	return 0;
}