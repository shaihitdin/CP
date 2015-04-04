#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
#define ull unsigned long long
const int N=300001;
const ull PR=37;
string s;
int d1[N],d2[N],z[N],l,r,k,i,mxans,ans,j;
ull h_s[N],p_pow[N],cur_h,check;
int main(){
//	freopen("palindrome.in","r",stdin);
//	freopen("palindrome.out","w",stdout);
	//ios_base::sync_with_stdio(0);
	cin>>s;
		p_pow[0]=1;
	for(i=1;i<=300000;++i)
	 p_pow[i]=(p_pow[i-1]*PR);
	//odd
	cerr<<"ODD pal\n";
	for(i=0,r=-1,l=0;i<s.size();++i){
	  if(i>r)
	    k=0;
	  else
	    k=min(d1[l+r-i],r-i);
	    ++k;
	    while(i+k<s.size() && i-k>=0 && s[i+k]==s[i-k]) ++k;
	    d1[i]=k--;
	    if(i+k>r)
	     r=i+k,l=i-k;
	     cerr<<i<<":"<<d1[i]<<"\n";
	}
	//even
	cerr<<"EVEN pal\n";
	for(i=0,r=-1,l=0;i<s.size();++i){
	  if(i>r)
	    k=0;
	  else
	    k=min(d2[l+r-i+1],r-i);
	    ++k;
	    while(i+k-1<s.size() && i-k>=0 && s[i+k-1]==s[i-k]) ++k;
	    d2[i]=--k;
	    if(i+k-1>r)
	     r=i+k-1,l=i-k;
	     cerr<<i<<":"<<d2[i]<<"\n";
	}
	
	for(i=0;i<s.size();++i){
		h_s[i]=((s[i]-'a'+1)*p_pow[i]);
		if(i>0) h_s[i]=(h_s[i]+h_s[i-1]);
	}

	for(i=0;i<s.size();++i){
		ans=0;
		cerr<<i<<":";
	   if(d1[i]>0){
	     cur_h=h_s[i+d1[i]-1];
	     if(i-(d1[i]-1)>0) cur_h-=h_s[i-(d1[i]-1)-1];
	     for(j=d1[j];j<s.size();++j){
	        check=h_s[j+(d1[j]-1)];
	        if(j-(d1[j]-1)>0)
	         check-=h_s[j-(d1[j]-1)-1];
	         if(cur_h==check*p_pow[j-d1[j]]){
	          ++ans;
	          cerr<<j<<" ";
	         }
	     }
	   }
	   mxans=max(mxans,ans*((d1[i]-1)*2+1));
	   cerr<<"\n";
	}
	
return 0;}