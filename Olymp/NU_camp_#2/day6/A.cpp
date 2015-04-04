#include<iostream>
#include<math.h>
#include<stdio.h>
#include <algorithm>
using namespace std;  
#define govno 999997LL
long long n,i;
int main(){              
      cin>>n;
      if(n==1 ){
      	
         cout<<1;
      }
      else if(n==2){
        cout<<2;
      }
      
      else {                 
        	long long mx=n*(n-1), mx2=n*(n-1);
       	for(i=n;i>=1;--i)
          	if (n*(n-1)*i/(__gcd(n*(n-1),i))>mx2) 
        			mx2=n*(n-1)*i/(__gcd(n*(n-1),i));    
        //	if (mx!=mx2)  cerr<<"FOUND: "<<n<<"\n";
          cout<<mx2<<"\n";        
     }                                  
	//cerr<<(__gcd(n,govno))<<" "<<(__gcd(n-1,govno))<<"\n";
	//for (int i=2; i*i<=999997; ++i) if (999997%i==0) cerr<<"naher idi "<<i<<"\n";
	return 0;
}
