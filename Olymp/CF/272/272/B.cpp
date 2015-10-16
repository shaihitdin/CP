#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
double tmp,tmp1,tmp3,ans,divisor;
string s,s1;
inline void rec(double pos, double now){
	if(pos>=tmp3+1){
		if(fabs(tmp1-tmp)==now){
			++ans;
		}
		++divisor;
		return;
	}
	rec(pos+1, now+1);
	rec(pos+1, now-1);
} 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>s>>s1;
	for(int i=0;i<s.size();++i){
		if(s[i]=='+')
			++tmp;
		else
			--tmp;
	}
	for(int i=0;i<s1.size();++i){
		if(s1[i]=='+')
			++tmp1;
		else if(s1[i]=='-')
			--tmp1;
		else	++tmp3;
	}
	rec(1,0);

	printf("%.9lf",(ans/divisor));
	return 0;
}