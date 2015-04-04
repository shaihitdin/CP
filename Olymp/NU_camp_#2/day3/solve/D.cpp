#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[5001],n,i,j;
double b[5001];
void solve(int n,int *a){
		for(i=1;i<=n;++i)
		 b[i]=a[i];
		for(i=-10;i<=10;++i){
			double tmp=0;
		  for(j=1;j<=n;++j)
		    tmp+=fabs(double(double(b[j])-double(i*j)));
		    printf("%lf ",tmp);
		}   
}
int main(){
         freopen("in","r",stdin);
         freopen("out","w",stdout);
         scanf("%d",&n);
         for(i=1;i<=n;++i)
          scanf("%d",&a[i]);
          solve(n,a);

return 0;}