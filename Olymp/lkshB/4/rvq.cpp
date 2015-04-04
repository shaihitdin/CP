#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100001;
int k,x,y;
int sz=1,i;
long long a[N];
long long t1[N*4],t2[N*4];
inline long long get(int x,int y){
	long long ans1=N,ans2=-N;
	while(x<=y){
	 if(x&1) ans1=min(ans1,t1[x]),ans2=max(ans2,t2[x]),++x;
	 if(!(y&1)) ans1=min(ans1,t1[y]),ans2=max(ans2,t2[y]),--y;
	  x>>=1;
	  y>>=1;
	}
	return ans2-ans1;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(long long j=1;j<N;++j){
	  a[j]=(((j*j)%12345)+((j*j*j)%23456));
	}
	
	  while(sz<=N)
	  sz<<=1;
	  int j;
	for(i=sz,j=1;i<(N-1+sz);++i,++j)
	 t2[i]=t1[i]=a[j];
	for(i=N-1+sz;i<sz*2;++i)
	 t2[i]=-N,t1[i]=N;
	for(i=sz-1;i>0;--i){
	  t1[i]=min(t1[i*2],t1[i*2+1]);
	  t2[i]=max(t2[i*2],t2[i*2+1]);
	}
	scanf("%d",&k);
	for(i=1;i<=k;++i){
		scanf("%d %d",&x,&y);
		if(x>0){
		//max-min
		  x+=(sz-1),y+=(sz-1);
		  printf("%d\n",(get(x,y)));
		}
		else{
		//a[x]=y
		 x*=(-1);
		 x+=(sz-1);
		 t1[x]=y;
		 t2[x]=y;
		 x>>=1;
		 for(;x>0 ;t1[x]=min(t1[x*2],t1[x*2+1]),t2[x]=max(t2[x*2],t2[x*2+1]),x>>=1);
		}
	}
return 0;}
