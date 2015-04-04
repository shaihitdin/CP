#include<stdio.h>
#include<math.h>
#include"grader.h"
using namespace std;
int i,j,n;
double b[200001];
double calc1(double x){
	double tmp=0;
		for(j=0;j<n;++j)
		    tmp+=fabs(b[j]-x*j);
		    return tmp;
}
float solve(int n,int* a){
   for(i=0;i<n;++i)
     b[i]=a[i];
     double l=-1000000001,r=1000000001;
     while(r-l>0.000001){
      double m1=l+(r-l)/3,
             m2=r-(r-l)/3;
		if(calc1(m1)<calc1(m2))
		  r=m2;
		else
		  l=m1;
     }
     return r;
}
/*
int main(){
         freopen("in","r",stdin);
         freopen("out","w",stdout);
         scanf("%d",&n);
         for(i=1;i<=n;++i)
          scanf("%d",&a[i]);
          printf("%lf",solve(n,a));

return 0;}
*/