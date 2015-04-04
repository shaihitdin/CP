#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
long long a,b,n;
inline string F(long long a){
	string s;
	while(a>0){
		s+=char(a%10);
		a/=10;
	}
	s.reverse(s.begin(),s.end());
	return s
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%I64d",&n);
	for(i=1;i<=n;++i){
		scanf("%I64d%I64d",&a,&b);
		a_s=F(a);
		b_s=F(b);
		long long ansuuer=0;
		ansuuer=b_s.size()-a_s.size();			
		if(a_s.size()==1){
			ansuuer+=min(10-a,b-a);
		}
	}
	return 0;
}