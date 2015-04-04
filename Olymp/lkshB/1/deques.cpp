#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
const int N=150001;
int start[N],end[N],next[N],prev[N],num[N],a,b,sz,x,n,i;
char s[21];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	ios_base::sync_with_stdio(0);
		scanf("%d",&n);
		for(i=1;i<=n;++i){
		   scanf("%s",s);
		   if(s[0]=='p' && s[1]=='u' && s[2]=='s' && s[3]=='h')
		   	if(s[4]=='f' && s[5]=='r' && s[6]=='o' && s[7]=='n' && s[8]=='t'){
		   	  scanf("%d %d\n",&a,&b);
		   	   if(!start[a]){
		   	      start[a]=++sz;
		   	      end[a]=start[a];
		   	   }
		   	   else{
		   	      x=++sz;
		   	      next[x]=start[a];
		  	       prev[start[a]]=x;
		    	     start[a]=x;
		   	   }
		  	    num[start[a]]=b;
		 	  }
			  else {
			     scanf("%d %d\n",&a,&b);
			      if(!end[a]){
			         end[a]=++sz;
			         start[a]=end[a];
			      }
			      else{
			         x=++sz;
			         prev[x]=end[a];
			         next[end[a]]=x;
			         end[a]=x;
			      }
			      num[end[a]]=b;
			   }
		   
		   else
		  	 if(s[3]=='f' && s[4]=='r' && s[5]=='o' && s[6]=='n' && s[7]=='t'){
		  	 	scanf("%d\n",&a);
		 	  	printf("%d\n",num[start[a]]);
		   		start[a]=next[start[a]];
		   		prev[start[a]]=0;
		   		if(!start[a])
		   		 end[a]=0;
		  	 }
		  	 else{
		  	 	scanf("%d\n",&a);
		 	  	printf("%d\n",num[end[a]]);
		 	  	end[a]=prev[end[a]];
		   		next[end[a]]=0;
		   		if(!end[a])
		   		 start[a]=0; 
		   	 }	
		}
return 0;}