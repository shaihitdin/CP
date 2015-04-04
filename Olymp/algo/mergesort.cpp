#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int N=1000001,inf=1000000009;
int n,a[N],ans;
int x[N],y[N],z[N];
void split_sort(int l,int r){
    if(l==r)
     return;
    int mid=(l+r)>>1;
    split_sort(l,mid);
    split_sort(mid+1,r);
    //x-left, y-right, z-res
    int dist1=mid-l+1,dist2=r-mid;
    for(int i=1;i<=dist1;++i)
      x[i]=a[l+i-1];
    for(int i=1;i<=dist2;++i)
      y[i]=a[mid+i];
      int i=1,j=1,k=0;
    while(i<=dist1 || j<=dist2){
             for(;i<=dist1 && (x[i]<=y[j]|| j>dist2);++i) z[++k]=x[i];
            for(;j<=dist2 && (x[i]>y[j] || i>dist1);++j,++ans) z[++k]=y[j];
    }
    for(i=1;i<=r-l+1;++i)
      a[l+i-1]=z[i];
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
         split_sort(1,n);
        for(int i=1;i<=n;++i)
         printf("%d ",a[i]);
return 0;}