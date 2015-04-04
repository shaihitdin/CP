#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const long long N=100001;
long long t[N];
long long n,i,ans,a[N],j;
vector<long long> l;
inline void upd(long long pos,long long inc){
	for(;pos<=n;pos=(pos|(pos+1)))	t[pos]+=inc;
}
inline long long get(long long r){
	long long sum=0;
	for(;r>=1;r=(r&(r+1))-1)	sum+=t[r];
	return sum;
}

int main(){
	freopen("gazmyas.in","r",stdin);
	freopen("gazmyas.out","w",stdout);
	scanf("%I64d",&n);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	for(i=2;i<=n;i+=2){
		upd(i,1);
	}
	for(i=1;i<=n;++i){
		while(i<=n && !(a[i]&1)){
			l.push_back(a[i]);
			upd(a[i],-1);
			++i;
		}
		for(j=0;j<l.size();++j){
			ans+=get(a[i]);
		}
		l.clear();
	}
	printf("%I64d",ans);
	return 0;
}