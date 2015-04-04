#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int a,b,i;
char a1[10],b1[10];
int main(){
     for(i=10000;i<100000;++i){
         a=i;
         b=i*4;
         itoa(a,a1,10);
         itoa(b,b1,10);
         swap(b1[0],b1[4]);
         swap(b1[1],b1[3]);
         if(!strcmp(a1,b1)){
          cout<<i<<"\n";
         }
     }
     return 0;
}