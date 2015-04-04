#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int N=1000001,inf=1000000009;
int n,a[N],ans;
int x[N],y[N],z[N];
void split_sort(int l,int r){
//	cerr<<l<<" "<<r<<"\n";
	if(l==r)
	 return;
	int mid=(l+r-1)>>1;
	split_sort(l,mid);
	split_sort(mid+1,r);
	//x-left, y-right, z-res
	int dist1=mid-l+1,dist2=r-mid;
//	 fprintf(stderr,"%d %d",l,r);
//	 fprintf(stderr,"on the left hand ");
	for(int i=1;i<=dist1;++i)
 	  x[i]=a[l+i-1]/*,fprintf(stderr,"%d ",x[i])*/;
//	 fprintf(stderr,"^^^ on the right hand ");
	for(int i=1;i<=dist2;++i)
	  y[i]=a[mid+i]/*,fprintf(stderr,"%d ",y[i])*/;
	 //fprintf(stderr,"^^^");

	  int i=1,j=1,k=0;
	  while(i<=dist1 || j<=dist2){
	         if(i>dist1)
	         for(;j<=dist2;z[++k]=y[j],++j);
	         if(j>dist2)
	         for(;i<=dist1;z[++k]=x[i],++i);

	         for(;i<=dist1 && (x[i]<=y[j]) && j<=dist2;z[++k]=x[i],++i);
		    for(;j<=dist2 && (x[i]>y[j]) && i<=dist1 ;ans+=dist1-i+1,z[++k]=y[j],++j)/* fprintf(stderr,"%d > (%d ... %d)\n",l+i-1,mid+j,mid+dist2)*/;
	  }
	for(i=1;i<=r-l+1;++i)
	  a[l+i-1]=z[i]/*,fprintf(stderr,"%d ",z[i])*/;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	    scanf("%d",&n);
	    for(int i=1;i<=n;++i)
	     scanf("%d",&a[i]);
	     split_sort(1,n);
	     printf("%d",ans);
	     /*
	    for(int i=1;i<=n;++i)
	     printf("%d ",a[i]);
	     */
return 0;}