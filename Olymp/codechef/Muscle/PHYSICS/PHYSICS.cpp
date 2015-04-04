#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
#ifdef _WIN32
	#define I64d "%lld"
#else
	#define I64d "%I64d"
#endif
char x;
int t,n,i;
const double eps=0.0000001;
double f,f_pow[42],a[10001];
int sz,ans,j;
map<int,int> mp;
inline bool equal(const double &lhs, const double &rhs){
	if(lhs>rhs){
		return ((lhs-rhs)<eps);
	}
	else{
		return ((rhs-lhs)<eps);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf(I64d,&t);
	++t;
	while(--t){
		scanf("%d%lf",&n,&f);
		sz=0;
		f_pow[0]=1;
		ans=0;
		while(f_pow[sz]<=1e9){
			f_pow[++sz]=f_pow[sz-1]*f;
		}
		for(i=1;i<=n;++i){
			scanf("%lf",&a[i]);
		}
		for(i=1;i<=n;++i){
			++mp[int(a[i])];
		}
		for(i=1;i<=n;++i){
			for(j=1;(a[i]/f_pow[j])>double(0.9);++j){
				if(!equal(a[i]/f_pow[j],double(int(a[i]/f_pow[j]))))	continue;
				ans+=(mp[int(a[i]/f_pow[j])]);
			}
		}
		for(i=1;i<=n;++i){
			ans+=(mp[a[i]]-1);
			mp[a[i]]--;
		}
		printf("%d\n",ans);
	}
	return 0;
}