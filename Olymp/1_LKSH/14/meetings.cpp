#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int d[(1<<20) + 1],from[(1<<20) + 1];
bool u[(1<<20) + 1];
int n,k,ans,l[21],r[21],c[21],nn,i,ansmask;
vector<int> ansv;
inline bool bit(int mask,int pos){
	return (mask&(1<<pos));
}
int main(){
	freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);
	cin>>n>>k;
	d[0]=k;
	u[0]=1;
	for(i=1;i<=n;++i){
		cin>>l[i]>>r[i]>>c[i];
	}
	nn=(1<<n);
	for(i=0;i<nn;++i){
		if(!u[i]) continue;
		int tmp = 0;
		for(int j=0;j<n;++j){
			if(bit(i,j)){
				++tmp;
			}
			if(!bit(i,j) && d[i]>=l[j+1] && d[i]<=r[j+1]){
				d[i|(1<<j)]=d[i]+c[j+1];
				u[i|(1<<j)]=1;
				from[i|(1<<j)]=i;
			}
		}
		if(ans<tmp){
			ans=tmp;
			ansmask=i;
		}
	}
	cout<<ans<<"\n";
	i=ansmask;
	while(i!=0){
		k=i^from[i];
		for(int j=0;j<n;++j)
			if((1<<j)==(k))
				ansv.push_back(j+1);
		i=from[i];
	}
	for(i=int(ansv.size())-1;i>=0;--i){
		cout<<ansv[i]<<" ";
	}
return 0;}