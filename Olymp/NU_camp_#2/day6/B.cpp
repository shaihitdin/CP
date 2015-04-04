#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int n,b[1001],mn,mx,i;
char a[1001];
int main(){
       scanf("%d\n",&n);
       for(i=2;i<=n;++i)
        scanf("%c",&a[i]);

        for(i=2;i<=n;++i)
        if(a[i]=='L')
          b[i]=b[i-1]-1;
        else if(a[i]=='R')
          b[i]=b[i-1]+1;
          else
          b[i]=b[i-1];
         for(i=1;i<=n;++i)
            if(b[i]<mn)
              mn=b[i];
         for(i=1;i<=n;++i)
          cout<<1+(b[i]+abs(mn))<<" ";
return 0;}