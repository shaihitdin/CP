//en buyuk rakami 2 olan butun 3 basamakli sayilari yazdiralim 
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  int a[10];
  int i;  
  for(i=1;i<=4;i++)
      a[i]=0;
  do
  {
     a[1]++;        
     for(i=1;i<=3;i++)        
      if(a[i]>2)
      {
        a[i]=0; a[i+1]++;
      }          
     if((a[1]!=0)&(a[1]+a[2]+a[3]==5)) 
       cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<"\n";        
  }while(a[4]==0);
  
    system("PAUSE");
    return EXIT_SUCCESS;
}
