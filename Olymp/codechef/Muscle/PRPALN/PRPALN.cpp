#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s;
int i,tmp,t;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>t;
	++t;
	while(--t){
		cin>>s;
		int cnt1=0,cnt2=0;
		for(i=0;i<s.size()/2;++i){
			while(s.size()-i-1-cnt1>=0 && cnt1<=1 && s[i]!=s[s.size()-i-1-cnt1]) ++cnt1;
			if(cnt1>1)	break;
		}
		for(i=0;i<s.size()/2;++i){
			while(s.size()-i-1>=0 && cnt2<=1 && s[i+cnt2]!=s[s.size()-i-1]) ++cnt2;
			if(cnt2>1)	break;
		}
		tmp=min(cnt1,cnt2);
		if(tmp==0 || tmp==1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}