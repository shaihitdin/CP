#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
  int h,i,k,x;
  int b[9];
  for(i=1;i<=8;i++) b[i]=1;
  b[9]=0;
  
  // starting pribor
  do
  {
    h=0;
    b[1]++;
    for(i=1;i<=8;i++)
    if(b[i]>8) { b[i]=1;b[i+1]++;} //burasi pribor
    //*********************************************
    //burada her varyant ta vezirlerin birbirini alip almamasi kontrol edilmis oluyor.      
    for(i=1;i<=8;i++)
      for(k=1;k<=8;k++)
      if(i!=k) 
      {
        if ((b[i]==b[k])||(abs(i-k)==abs(b[i]-b[k])))  h++;
      }  
    //**********************************************)      
    if(h==0)
    { x++; //bu varyantta vezirler birbirini tehtid etmediyse
                 //h=0 kaliyor. ve x artiyor
      //dogru varyant yaziliyor   
        cout<<x<<"==>";
        for(i=1;i<=8;i++)
         cout<<b[i]<<" ";
         cout<<"\n";
      //varyant yazilmasi bitiyor
    }             
  }while(b[9]==0);//Pribor bitiyor
  
cout<<x;
    system("PAUSE");
    return EXIT_SUCCESS;
}
