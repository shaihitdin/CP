#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
int d[12][12][12][12][12][12][12];
char st[10000001][10],s[10],t[10],x[10],a[10],b[10];
pair<char,char> ch[60][60];
int head,tail;
int n,k,counter,before,change,j,i;
char buff[257],buff1[257];
inline void add_to_st(char* y){
      for(j=0;j<n;++j)
       st[tail][j]=y[j];
      ++tail;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	cin>>s>>t;
     cin>>k;
     while(k--){
        cin>>a>>b;
        ch[a[0]][a[1]]=mkp(b[0],b[1]);
     }
	add_to_st(s);
	d[n>=1?s[0]-'0':10][n>=2?s[1]-'0':10][n>=3?s[2]-'0':10][n>=4?s[3]-'0':10][n>=5?s[4]-'0':10][n>=6?s[5]-'0':10][n>=7?s[6]-'0':10]=1;
	while(head!=tail){
		for(i=0;i<n;++i){
	   	  x[i]=st[head][i];
	   	}
	   ++head;
	   for(i=1;i<n;++i){
//	      cerr<<j<<" ";
	      	  if(ch[x[i-1]][x[i]].F!=0){
	      	     for(j=0;j<n;++j)
	      	       b[j]=x[j];
	      	       b[i-1]=ch[x[i-1]][x[i]].F;
	      	       b[i]=ch[x[i-1]][x[i]].S;
	      	     if(d[n>=1?b[0]-'0':10][n>=2?b[1]-'0':10][n>=3?b[2]-'0':10][n>=4?b[3]-'0':10][n>=5?b[4]-'0':10][n>=6?b[5]-'0':10][n>=7?b[6]-'0':10]==0){
	           	   d[n>=1?b[0]-'0':10][n>=2?b[1]-'0':10][n>=3?b[2]-'0':10][n>=4?b[3]-'0':10][n>=5?b[4]-'0':10][n>=6?b[5]-'0':10][n>=7?b[6]-'0':10]=d[n>=1?x[0]-'0':10][n>=2?x[1]-'0':10][n>=3?x[2]-'0':10][n>=4?x[3]-'0':10][n>=5?x[4]-'0':10][n>=6?x[5]-'0':10][n>=7?x[6]-'0':10]+1;
	           	   
	          	    add_to_st(b);
	          	 }
	      	  }
	   }
	}
	cout<<d[n>=1?t[0]-'0':10][n>=2?t[1]-'0':10][n>=3?t[2]-'0':10][n>=4?t[3]-'0':10][n>=5?t[4]-'0':10][n>=6?t[5]-'0':10][n>=7?t[6]-'0':10]-1;
return 0;}