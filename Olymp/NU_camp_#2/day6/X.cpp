#include<iostream>
#include<string>
using namespace std;
string a;
int main(){
       	cin>>a;
       	if((a<="127" || a.size()<3) && a.size()<=3)
       	 cout<<"byte";
       	else if((a<="32767" || a.size()<5) && a.size()<=5)
		 cout<<"short";
       	else if((a.size()<10 || a<="2147483647") && a.size()<=10) 
       	 cout<<"int";
       	else if((a<="9223372036854775807" || a.size()<19) && a.size()<=19)
		 cout<<"long";
       	else
       	 cout<<"BigInteger";

return 0;}