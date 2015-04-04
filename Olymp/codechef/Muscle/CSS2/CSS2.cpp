#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
#define mkp make_pair
#define F first
#define S second
map<pair<int,int>,pair<int,int> > mp; /// 1-id, 2-attr, 3-val, 4-priority
int tmp_val,n,i,m,tmp_priority,priority,val,attr,id;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d%d%d%d",&id,&attr,&val,&priority);
		tmp_val=mp[mkp(id,attr)].F;
		tmp_priority=mp[mkp(id,attr)].S;
		if(tmp_priority==priority){
			mp[mkp(id,attr)].F=val;
		}
		if(tmp_priority<priority){
			mp[mkp(id,attr)]=mkp(val,priority);
		}
	}
	for(i=1;i<=m;++i){
		scanf("%d%d",&id,&attr);
		printf("%d\n",mp[mkp(id,attr)].F);
	}
	return 0;
}