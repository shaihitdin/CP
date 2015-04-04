#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;
string s;
int n,i;
void win(int pos){
	if(pos&1){
		cout<<"First";
		exit(0);
	}
	else{
		cout<<"Second";
		exit(0);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>s;
	n=s.size();
	s="#"+s;
	for(i=1;i<=n;++i){
		if((i&1)==(n&1)){
				if(s[i]=='9'){
					continue;
				}
				else{
					win(i);
				}
		}
		else{
				if((i==1 && s[i]=='1') || (s[i]=='0')){
					continue;
				}
				else{
					win(i);
				}
		}
	}
	win(n);
	return 0;
}