#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
const int N=101;
int i,j,k;
string s,new_s,tmp_s;
int main(){

	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	cin>>s;
	//cout<<"";
	scanf("%d",&k);
	while(k--){
	   new_s=s;
	   long long new_1;
	   new_1=atoi(new_s.c_str());
	   for(i=0;i<s.size()-1;++i){
	      	j=i+1;
	      	tmp_s=s;
	         //cerr<<tmp_s<<" ";
	         swap(tmp_s[i],tmp_s[j]);
	         long long tmp;
	         //cerr<<tmp_s<<"\n";
	         tmp=atoll(tmp_s.c_str());
	         //cerr<<tmp<<" "<<new_1<<" "<<(tmp>new_1)<<"\n";
	         if(tmp>new_1)
	         { 
	         //cerr<<" OK??";
	         	 //cerr<<new_s<<" "<<tmp_s<<":";
	         	 new_s=tmp_s;
	           new_1=atoll(new_s.c_str());
	           //cerr<<new_s<<" "<<tmp_s;
	 		}
	         //cerr<<"\n";
	   }
	   s=new_s;
	   //cerr<<s<<" ";
	}
	cout<<s;
return 0;}