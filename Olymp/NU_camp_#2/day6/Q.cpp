#include<iostream>
using namespace std;
int tp,td,t,f,c,counter,j,tmp;
bool flag;
int main(){
      cin>>tp>>td>>t>>f>>c;
      tmp+=(t*tp);
      while(tmp<c){
            
           for(j=1;td*j<tmp+tp*j && tmp+tp*j<c;++j){

           }           
           if(tmp+tp*j>=c)
            break;
            tmp+=tp*j;
            tmp+=((tmp/td)+f)*tp;
            
            ++counter;
      }
		cout<<counter;
return 0;}