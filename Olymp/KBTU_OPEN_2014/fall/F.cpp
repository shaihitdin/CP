#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
#ifdef _WIN32
	#define I64d "%lld"
#else
	#define I64d "%I64d"
#endif
const int N=1000002;
long long n,m,i,l,r,added_time[N],t[N],tmp,ans,a[N],l_e,r_e;
multiset<long long> st;
int main(){
	freopen("justforfood.in","r",stdin);
	freopen("justforfood.out","w",stdout);
	scanf(I64d""I64d,&n,&m);
	for(i=1;i<=n;++i){
		scanf(I64d,a+i);
		st.insert(a[i]);
	}
	if(m==1){
		long long sum=0;
		for(i=1;i<=n;++i)
			sum+=a[i];
		printf(I64d,sum);
		return 0;
	}
	while(st.size()){
		tmp=0;
		r_e=*st.rbegin();
		st.erase(*st.rbegin());
		while(st.size() && r_e!=tmp){
			l_e=*st.rbegin();
			st.erase(*st.rbegin());
			if(l_e-(r_e-tmp)>0){
				l_e-=(r_e-tmp);
				tmp=r_e;
				st.insert(l_e);
			}
			else{
				tmp+=a[l];
			}
		}
		ans+=tmp;
	}
	printf(I64d,ans);
	return 0;
}