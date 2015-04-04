#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
const int N=301;
bool u[N];
long long x[N],y[N],ans=10000000000.0,sum,mn;
long long n,i,last,step,mnpos,j;
int main(){
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);
	scanf("%I64d",&n);
	for(i=1;i<=n;++i){
		scanf("%I64d%I64d",&x[i],&y[i]);
		x[i]+=300;
		y[i]+=300;
	}
	for(i=1;i<=n;++i){
		last=i;
		sum=0;
		for(step=1;step<n;++step){
			u[last]=1;
			mn=10000000000;
			mnpos=0;
			for(j=1;j<=n;++j){
				if(!u[j]){
					if((((x[last]-x[j])*(x[last]-x[j]))+((y[last]-y[j])*(y[last]-y[j])))<mn){
					    mn=((x[last]-x[j])*(x[last]-x[j])+(y[last]-y[j])*(y[last]-y[j]));
						mnpos=j;
					}
				}
			}
			sum+=mn;
			u[mnpos]=1;
			last=mnpos;
		}
		memset(u,0,sizeof(u));
		ans=min(ans,sum);
	}
	printf("%I64d",ans);
return 0;
}