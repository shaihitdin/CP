#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int ch[1001],st[10000001*2],d[10000001*2];
int head,tail;
int s,t,n,k,x,counter,before,change,j,a,b,i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	cin>>s>>t;
     cin>>k;
     while(k--){
        cin>>a>>b;
        ch[a]=b;
     }
	st[tail++]=s;
	d[s]=1;
	while(head!=tail){
	   x=st[head++];
	   before=0;
	   //cerr<<x<<" ";
	   for(i=1;i<n;++i){
	   change=pow(10,n-i-1);
	      j=x/(change)%100;
	     // cerr<<"["<<((x/(change*100))*100+ch[j])*(change)+(x%(change))<<";";
	     // cerr<<j<<"] ";
	      	  if(ch[j]!=0){
	      	   b=((x/(change*100))*100+ch[j])*(change)+(x%(change));
	      	    	if(d[b]==0){
	           	   d[b]=d[x]+1;
	          	    st[tail++]=b;
	          	 }
	      	  }
	   }
	   //cerr<<"\n";
	}
	cout<<d[t]-1;
return 0;}