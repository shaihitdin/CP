#include<iostream>
using namespace std;
int n,counter;
int main(){
	 cin>>n;
	 int k=1;
	 
	 while(k*k<=n){
	   
	   n-=(k*k);
	   counter++;
	   ++k;
	   }
	   cout<<counter;
return 0;}