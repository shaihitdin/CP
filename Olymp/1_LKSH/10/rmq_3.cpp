#include<iostream>
#include<stdio.h>                                                                                                                                 
using namespace std;
const int N = 530;
struct tree{
	int Min;
	bool flag;
	int change;
};
tree t[530][530][530];
int pos1,pos2,pos3;
inline void upd3(int v1,int v2,int v3,int tzl, int tzr,int x, int sz){
	if(tzl > sz || tzr < sz){
		return;
	}
	if(tzl == tzr && tzl == sz){
		t[v1][v2][v3] = x;
		pos1=v1;
		pos2=v2;
		pos3=v3;
		return ;
	}
	int mid=(tzl+tzr)/2;
	upd3(v1,v2,v3*2,tzl,mid,x,sz);
	upd3(v1,v2,v3*2+1,mid+1,tzr,x,sz);
	t[v1][v2][v3]=t[v1][v2][v3*2]+t[v1][v2][v3*2+1];
}
inline void upd2(int v1,int v2,int tyl, int tyr,int x, int sy){
	if(tyl > sy || tyr < sy){
		return;
	}
	if(tyl == tyr && tyl == sy){
		upd3(v1,v2,1,0,sz-1,x,sz);
	}
}

inline void upd1(int v1,int txl, int txr,int x, int sx){
	if(txl > sx || txr < sx){
		return;
	}
	if(txl == txr && txl == sx){
		upd2(v1,1,0,sz-1);
	}
	int mid = (txl+txr)/2;

}
int main() {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	while(sz<=n) sz<<=1;
	while(scanf("%d",&q)){
		if(q==3){
			return 0;
		}
		if(q==2){
			scanf("%d%d%d%d",&sx,&sy,&sz,&fx,&fy,&fz);

		}
		if(q==1){
			scanf("%d%d%d%d",&sx,&sy,&sz,&x);
			upd1(1,0,sz-1,x,sx);
		}
	}
return 0;}