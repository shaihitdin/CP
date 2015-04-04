#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
const int N=1000001;
int a[N],n;
inline void slowsort(int l,int r){
	if(l>=r)
	 return ;
  int pivot=a[l+((rand())%(r-l))];
  int i=l,j=r;
  do{
  	while(a[i]<pivot) ++i;
  	while(a[j]>pivot) --j;
  	if(i<=j)
  	swap(a[i],a[j]),++i,--j;
  }while(i<j);
  slowsort(l,j);
  slowsort(i,r);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 srand(time(0));
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
		  scanf("%d",&a[i]);
		}
		slowsort(1,n);
		for(int i=1;i<=n;++i)
		  printf("%d ",a[i]);
return 0;}