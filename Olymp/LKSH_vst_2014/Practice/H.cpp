#include<iostream>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;  
const unsigned long long PR=31,mod=1000000009;
unsigned long long p_pow[11];
string s,t,x,y,tmp,tmp1;
int n,i,sz,j,m,counter;
map<unsigned long long,int> map1;
map<string,string> change;
char st[10000001][8];
int head,tail;
inline unsigned long long convert(string x){
	unsigned long long h_t=0;
 for(int j=0;j<x.size();++j)
 h_t=(h_t+(x[j]-'A'+1)*p_pow[j])%mod;
 return h_t;
}
int main(){
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     cin>>n;
     cin>>s>>t;
     cin>>m;
     p_pow[0]=1;
     for(i=1;i<=n;++i)
	p_pow[i]=(p_pow[i-1]*PR)%mod;

     for(i=1;i<=m;++i){
         cin>>x>>y;
         change[x]=y;
     }
     map1[convert(s)]=1;
     for(int j=0;j<s.size();++j){
     st[tail][j]=s[j];
     }
     ++tail;
     while(head!=tail){
        x.resize(strlen(st[head]));
        for(int j=0;j<x.size();++j){
         x[j]=st[head][j];
         }
         counter=map1[convert(x)];
        
         ++head;
         for(i=1;i<x.size();++i){
           y.resize(2);
           y[0]=x[i-1];
           y[1]=x[i];
              tmp1=change[y];
            if(tmp1.size()==2){
            	  y=tmp1;
                 tmp=x;
                 tmp[i-1]=y[0];
                 tmp[i]=y[1];
                 if(map1[convert(tmp)]==0){
                    map1[convert(tmp)]=counter+1;
                    for(int j=0;j<tmp.size();++j)
                       st[tail][j]=tmp[j];
                       ++tail;
                 }
            }
         } 
     }
     cout<<map1[convert(t)]-1;
return 0;}