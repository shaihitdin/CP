#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
long long d[21],i,j,t;
string r,l;
inline long long calc(string s){
	s="9"+s;
	memset(d,0,sizeof(d));
	d[0]=1;
	for(i=0;i<s.size()-1;++i){
		for(j=1;j<=9;++j){
			if(j==1 || j==4 || j==9){
				d[i+1]+=d[i];
			}
			if(j==2 || j==4 || j==6 || j==8){
				d[i+4]+=d[i];
				d[i+4]+=d[i];
			}
			if(j==8){
				d[i+6]+=d[i];
			}
			d[i+2]+=d[i];
		}
	}
	long long sum=0;
	for(i=1;i<s.size()-1;++i){
		sum+=d[i];
	}
	memset(d,0,sizeof(d));
	d[0]=1;
	for(i=0;i<s.size();++i){
		s[i]-='0';		
		for(j=1;j<=s[i];++j){
			if(j==1 || j==4 || j==9){
				d[i+1]+=d[i];
			}
			if(j==2 || j==4 || j==6 || j==8){
				d[i+4]+=d[i];
				d[i+4]+=d[i];
			}
			if(j==8){
				d[i+6]+=d[i];
			}
			d[i+2]+=d[i];
		}
	}
	return (d[s.size()]);
}
int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	cin>>t;
	++t;
	while(--t){
		cin>>l>>r;
		cout<<(calc(r)-calc(l))<<"\n";
	}
	return 0;
}