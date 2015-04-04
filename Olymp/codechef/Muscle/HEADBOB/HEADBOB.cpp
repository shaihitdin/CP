#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char x;
int t,n,i;
int cnt[256];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d\n",&t);
	++t;
	while(--t){
		scanf("%d\n",&n);
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;++i){
			scanf("%c",&x);
			++cnt[x];
		}
		scanf("\n");
		if(cnt['Y'] && cnt['I']){
			printf("NOT SURE\n");
			continue;
		}
		if(cnt['Y']){
			printf("NOT INDIAN\n");
			continue;
		}
		if(cnt['I']){
			printf("INDIAN\n");
			continue;
		}
		printf("NOT SURE\n");
	}
	return 0;
}