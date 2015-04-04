#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
const int N=10000001;
unsigned int a[N],n,k;
inline void slowsort(int l,int r){
	if(l>=r){
	 return;
	}
  unsigned int pivot=a[l+((rand())%(r-l))];
  unsigned int i=l,j=r;
  do{
  	while(a[i]<pivot && i<r) ++i;
  	while(a[j]>pivot && j>l) --j;
  	if(i<=j)
  	swap(a[i],a[j]),++i,--j;
  }while(i<j);
  if(k<=j)
  slowsort(l,j);
  else 
  slowsort(i,r);
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	 srand(time(0));
		scanf("%u %u",&n,&k);
		for(int i=1;i<=n;++i){
		  a[i]=131*i*i*i+77*i*i+1345*i+1577;
		}
		slowsort(1,n);
		printf("%u",a[k]);
return 0;}