#include<iostream>
#include<math.h>
#include<stdio.h>
#include <algorithm>
using namespace std;  
int n,m,ans;
int main(){              
      cin>>n>>m;
      while(n!=0 && m!=0){
          if(m>n)
          swap(n,m);
          ans+=(n/m);
          n=n%m;
	     m=m;
	           }
      cout<<ans;
	return 0;
}
