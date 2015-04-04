#include<iostream>
#include<stdio.h>
using namespace std;
#ifdef _WIN32
#define ll "%I64d"
#else
#define ll "%lld"
#endif 
long long t;
double x,dv;
long long k,kc,tmp,prev;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>t;
	cout.precision(20);
	++t;
	while(--t){
		cin>>x>>k;
		tmp=1;
		dv=x/2.0;
		while(k>tmp){
			k-=tmp;
			tmp*=2;
			dv/=2.0;
		}
		cout<<dv+((dv*2.0)*(k-1))<<"\n";
	}
	return 0;
}