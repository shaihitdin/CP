#include<stdio.h>
#include "grader.h"
#include<iostream>
#include<algorithm>
using namespace std;

int n,t,a[100001],x,ans=1000000009,i,palms[100001],lvl,pos1,tmp;
int solve(int n,int t,int* palms){         
	if(n<t)
	 return -1;
		for(i=0;i<n;++i)
		    a[i]=i+1;
		    do{
		    		tmp=0;
		    		for(i=0;a[i]!=1;++i);
		    		 lvl=1;
		    		 pos1=i;
		        while(lvl<t){
		        	for(i=pos1;i>=0;--i)
		           if(a[i]==lvl+1)
		             goto assd;
		           for(i=pos1;i<n;++i)
		           if(a[i]==lvl+1)
		             goto assd;
		             assd:;
					tmp=max(tmp,abs(palms[pos1]-palms[i]));
		             pos1=i;
		            ++lvl;
		        }
		        if(tmp<ans){
		         ans=tmp;
		         }
		    }while(next_permutation(a,a+n));
          if(ans==1000000009)
            return -1;
          else
            return ans;
}

int main(){
     freopen("in","r",stdin);
     freopen("out","w",stdout);
       scanf("%d %d",&n,&t);
         for(i=0;i<n;++i)
         scanf("%d",&palms[i]);
           printf("%d",solve(n,t,palms));
return 0;}
