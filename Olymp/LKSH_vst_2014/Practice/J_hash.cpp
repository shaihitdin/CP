#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<string.h>
using namespace std;
#define ull unsigned long long
const ull PR=53,mod=10000000000009;
string s,t;
ull h_s[500001],h_t[12],p_pow[500001],cur_h;
int i,sz,sz1,lq[12],li[500001];
int main(){
       freopen("template.in","r",stdin);
       freopen("template.out","w",stdout);
       	ios_base::sync_with_stdio(0);
cin>>s>>t;
p_pow[0]=1;
for(i=1;i<500000;++i)
p_pow[i]=(p_pow[i-1]*PR)%mod;

for(i=0;i<s.size();++i){
h_s[i]=((s[i]-'a'+1)*p_pow[i])%mod;
if(i>0) h_s[i]=(h_s[i]+h_s[i-1])%mod;
}
lq[0]=0;
for(i=0;i<t.size();++i){
	if(t[i]!='?')
 	   h_t[sz]=(h_t[sz]+(t[i]-'a'+1)*p_pow[i])%mod;
 	else{
 	 lq[++sz]=i;
 	 }
}
lq[++sz]=t.size();
for(i=0;i+t.length()-1<s.length();++i){
		bool flag=0;
	for(int j=1;j<=sz;++j){
		 cur_h=h_s[i+lq[j]];
		if(i>0) cur_h-=h_s[i+lq[j-1]-1];
		if(cur_h != h_t[j-1]*p_pow[i+lq[j-1]+1])
		 	flag=1;
		 	cerr<<cur_h<<" "<<h_t[j-1]*p_pow[i+lq[j-1]+1]<<"\n";
	}
	if(!flag)
	li[++sz1]=i+1;
}
cout<<sz1;
for(i=1;i<=sz1;++i)
  cout<<li[sz1]<<" ";
return 0;}