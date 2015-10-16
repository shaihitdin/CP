#include<iostream>
#include<stdio.h>
using namespace std;
const int INF=1000000009;
int n,m,i,x,mx,s,sum,ans=-INF,mn,mnpos,mxpos,a[201],b[201],ori[201],azaza,num,j,k,v;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>num;
	for(i=1;i<=n;++i)
	 cin>>a[i],ori[i]=a[i];
	for(i=1;i<=n;++i){
		for(j=i;j<=n;++j){
		sum=0;
				for(k=1;k<=n;++k)
					 a[i]=ori[i];
			for(k=i,v=1;k<=j;++k,++v)
				b[v]=a[k],sum+=b[k];
			for(azaza=1;azaza<=num;++azaza){
				mn=INF;
				mnpos=0;
				for(k=i,v=1;k<=j;++k,++v){
				   	if(b[v]<mn)
					 mn=b[v],mnpos=v;
					 //sum+=b[v];
				}
				mx=-INF;
				mxpos=0;
				for(k=1;k<=n;++k){
					if(i<=k && k<=j)
					  continue;
					if(a[k]>mx)
					mx=a[k],mxpos=k;
				}
				if(mn>mx)
				break;
				sum+=(mx-mn);
				swap(b[mnpos],a[mxpos]);
			}
			for(k=1;k<=j-i+1;++k)
			  cerr<<b[k]<<" ";
			  cerr<<":sum="<<sum<<"\n";
			ans=max(ans,sum);
		}
	}
	cout<<ans;
return 0;}