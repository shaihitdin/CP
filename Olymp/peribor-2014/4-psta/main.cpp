//n pasta dilimi, k adama nasil dagitilir
//her adam minimum bir pasta dilimi almali
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  int a[10];
  int i,n,k,sum;
  cin>>n>>k;  
  for(i=1;i<=k;i++)
      a[i]=1;
  do
  {
     a[1]++;        
     for(i=1;i<=k;i++)        
      if(a[i]>n-k+1)
      {
        a[i]=1; a[i+1]++;
      }

     sum=0;
     for(i=1;i<=k;i++)
      sum=sum+a[i]; 
   
     if(sum==n) 
     {
        for(i=1;i<=k;i++)
           cout<<a[i]<<" ";
        cout<<"\n";        
     }
  }while(a[k+1]==0);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
