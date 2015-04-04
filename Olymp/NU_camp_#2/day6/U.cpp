#include<iostream>
#include<string>
using namespace std;
string s;
void rec(string s){
		string t;
		char ld='0';
		cout<<s<<"\n";
       for(int i=0;i<s.size();++i){
       	if(s[i]=='w' && i+1<s.size()){
       	 t+=s[i+1];
       	 ld=s[i+1];
       	 ++i;
       	 }
       	 else if(s[i]=='r' && ld!='0'){
       	  t+=ld;
       	 }
       	 else
       	  return;
       }
       
       rec(t);
}
int main(){
         cin>>s;
         rec(s);
return 0;}