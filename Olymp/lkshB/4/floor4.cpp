#include<iostream>
#include<stdio.h>
using namespace std;
const int N=(1<<20)+1,inf=1000000009;
int t[N],i,j,n,x,sz;
inline int getmin(int x,int y){
	if(x<y)
	return x;
	return y;
}
inline void change(int x,int y){
	x+=(sz-1);
	t[x]=y;
	for(x>>=1;x>0;t[x]=getmin(t[x*2],t[x*2+1]),x>>=1);
	return;
}
inline int get(int x){
	int l,r;
	x+=(sz-1);
	l=x;
	r=sz*2-1;
	int ans=inf;
	while(l<=r){
	  if(l&1) ans=getmin(ans,t[l]),++l;
	  if(!(r&1)) ans=getmin(ans,t[r]),--r;
	  l>>=1;
	  r>>=1;
	}
	return ans;
}
int main(){
	for(sz=1;sz<=100000*2;sz<<=1);
	for(i=sz,j=1;i<sz*2;++j,++i)
	  t[i]=j;
	for(i=sz-1;i>0;--i)
	  t[i]=getmin(t[i*2],t[i*2+1]);
	 scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(x>0){
		  int res=get(x);
		  printf("%d\n",res);
		  change(res,inf);
		}
		else{
			x*=(-1);
		  change(x,x);
		}
	}

return 0;}