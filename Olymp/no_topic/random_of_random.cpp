#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int N=(1<<16)+1;
int u[N],i,x;
int main(){
	srand(time(0));
	 while(++i){
	   x=rand();
	   if(u[x]==1)
	      break;
	   else
	     ++u[x];
	 }
	 cout<<i;
return 0;}