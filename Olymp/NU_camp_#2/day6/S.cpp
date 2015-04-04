#include<iostream>
#include<math.h>
#include<stdio.h>
#include <algorithm>
using namespace std;  
int n,m,ans,i,j;
bool flag=1;
int main(){              
      cin>>n>>m;
      swap(n,m);
      for(j=n;j>=1;--j,flag=!flag){
      	if(flag){
      	 for(i=1;i<=m;++i)
      	   cout<<i<<" "<<j<<"\n";
      	   }
      	else
      	 for(i=m;i>=1;--i)
      	   cout<<i<<" "<<j<<"\n";
      }

return 0;
}
