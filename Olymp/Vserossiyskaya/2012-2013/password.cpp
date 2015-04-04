#include<iostream>
#include<stdio.h>
using namespace std;
const unsigned long long pr=11, N=100001;
unsigned long long h_s[N],h_t[N],p_pow[N];
inline unsigned long long to_pow(unsigned long long hash, unsigned long long pos){
	return hash*p_pow[N-i];
}
int main(){
	freopen("password.in","r",stdin);
	freopen("password.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>s;
	cin>>s1;
	p_pow[0]=1;
	for(i=1;i<N;++i)
		p_pow[i]=p_pow[i-1]*pr;
	for(i=0;i<s.size();++i){
		h_s[i]=(h_s[i]-'0'+1)*p_pow[i];
		if(i>0)	h_s[i]+=h_s[i-1];
	}
	for(i=0;i<s.size();++i){
		h_s[i]=(h_s[i]-'0'+1)*p_pow[i];
		if(i>0)	h_s[i]+=h_s[i-1];
	}
	return 0;
}