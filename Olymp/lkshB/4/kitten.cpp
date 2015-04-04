#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1<<21+1;
int q,a,b;
int t[N],c[N];
int sum(int x){
	int ans=0;
	for(;x>=1;x=(x&(x+1))-1)
	  ans+=t[x];
	return ans;
}
void change(int x){
	int diff;
	if(c[x]==1)
	 diff=0;
	else
	 diff=1;
	 c[x]=1;
	 for(;x<N;x=(x|(x+1)))
	  t[x]+=diff;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	while(scanf("%c",&q)){
		if(feof(stdin)) return 0;
		if(q=='0'){
		  scanf("%d %d",&a,&b);
		  if(a>b)
		  swap(a,b);
		  printf("%d\n",(sum(b+N/2)-sum(a-1+N/2)));
		}
		else{
		  scanf("%d",&a);
		  change(a+N/2);
		}
		scanf("\n");
	}
return 0;}