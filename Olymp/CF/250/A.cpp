#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int n=4;
string s[n+1];
int i,j,tmp_ans,ans;
int main(){
	#ifndef ONLINE_JUDGE
     freopen("in","r",stdin);
     freopen("out","w",stdout);
	#endif
	for(i=1;i<=n;++i){
	   getchar();
	   getchar();
	   cin>>s[i];
	   getchar();
	}
	for(i=1;i<=n;++i){
//		cerr<<s[i]<<"----";
		int tmp1=0,tmp2=0;
	   for(j=1;j<=n;++j){
	   	if(s[i].size()/2>=s[j].size())
	   	 ++tmp1;
	   	if(s[i].size()*2<=s[j].size())
	   	 ++tmp2;
	   }
	   if(tmp1==n-1 || tmp2==n-1){
	     ++ans;
		tmp_ans=i-1;
		
	   }
	   cerr<<tmp1<<" "<<tmp2<<"\n";
	}
	if(ans==1)
	 cout<<char(tmp_ans+'A');
    	else
    	 cout<<'C';
return 0;}