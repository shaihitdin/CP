#include<stdio.h>
#include<math.h>
using namespace std;
#define mkp make_pair
#define NAME "round."
const int N=5001;
bool u[N];
double sum,sum1;
int i,n,m,b[N];
double a[N];
int main(){
	freopen(NAME"in","r",stdin);
	freopen(NAME"out","w",stdout);
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i){
		  scanf("%lf",&a[i]);
			sum+=a[i];
		 }
		 for(i=1;i<=n;++i){
		    if(trunc(((a[i]/sum))*m)<((a[i])/sum)*m){
		      u[i]=1;
		    }
		    a[i]=trunc(((a[i]/sum))*m);
		    sum1+=a[i];
		 }
		    for(i=n;i>=1;--i){
		    	if(sum1==m)
		    	 break;
		    		if(u[i]){
		    		  ++a[i];
		    		  ++sum1;
		    		  u[i]=0;
		    		 }
		    }
		       for(i=1;i<=n;++i)
		         b[i]=a[i];
		 for(i=1;i<=n;++i)
		  printf("%d ",b[i]);
return 0;}
