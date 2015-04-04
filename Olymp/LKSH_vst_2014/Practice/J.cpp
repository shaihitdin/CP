#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s,t,f;
int i,j,p[1111111],l[1111111],sz;
int main(){
     freopen("template.in","r",stdin);
     freopen("template.out","w",stdout);
       cin>>s>>t;
       f=t;
       f+=char(32);
       f+=s;

       for(i=1;i<t.size();++i){
          j=p[i-1];
          while(j>0 && (f[i]!=f[j] )) j=p[j-1];
          if(f[i]==f[j]) ++j;
          p[i]=j;
       }
       for(i=t.size()+1;i<f.size();++i){
          j=p[i-1];
          while(j>0 && (f[i]!=f[j] )) j=p[j-1];
          if(f[i]==f[j] ) ++j;
          p[i]=j;
       }
       for(i=t.size()+1;i<f.size();++i){
       	if(p[i]==t.size())
       	 l[++sz]=i-t.size()-t.size()+1;
       }
       	 cout<<sz<<"\n";
       	 for(i=1;i<=sz;++i)
       	  cout<<l[i]<<" ";
return 0;}