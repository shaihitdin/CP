#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int n,i;
string s;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n;
	while(n--){
		cin>>s;
		long long pos=1;
		for(i=0;i<s.size();++i){
			if(!(i&1))
				if(s[i]=='l'){
					pos=(pos*2)%1000000007;
				}
				else{
				    pos=(pos*2+2)%1000000007;
				}
		    else
		    	if(s[i]=='l'){
					pos=(pos*2-1)%1000000007;
				}
				else{
				    pos=(pos*2+1)%1000000007;
				}
		}
		cout<<pos<<"\n";
	}
return 0;
}