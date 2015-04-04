#include<iostream>
#include<stdlib.h> 	
using namespace std;
int gl,gr,bl,br;
void D(){
  cout<<"YES";
  exit(0);
}
int main(){
       cin>>gl>>gr>>bl>>br;
        if(gl>br){
            if(gl-br<=1)
             D();        
           }
        else{
           if((gl+1)*2>=br){
             D();
            }
        }
       swap(gl,gr);
       swap(bl,br);
        if(gl>br){
            if(gl-1==br)
             D();        
          }
        else{
           if((gl+1)*2>=br)
             D();
        }
        cout<<"NO";
return 0;}