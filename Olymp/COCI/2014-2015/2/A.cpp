#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string a[256],s;
char t[11];
int i,x;
int main(){
	for(i=1;i<10;++i){
		cin>>x;
		t[x]=((i)+'0');
	}
	a['a']+=t[2];

	a['b']+=t[2];
	a['b']+=t[2];
	
	a['c']+=t[2];
	a['c']+=t[2];
	a['c']+=t[2];
	
	a['d']+=t[3];
	
	a['e']+=t[3];
	a['e']+=t[3];
	
	a['f']+=t[3];
	a['f']+=t[3];
	a['f']+=t[3];

	a['g']+=t[4];

	a['h']+=t[4];
	a['h']+=t[4];
	
	a['i']+=t[4];
	a['i']+=t[4];
	a['i']+=t[4];
	
	a['j']+=t[5];

	a['k']+=t[5];
	a['k']+=t[5];

	a['l']+=t[5];
	a['l']+=t[5];
	a['l']+=t[5];

	a['m']+=t[6];
	
	a['n']+=t[6];
	a['n']+=t[6];

	a['o']+=t[6];
	a['o']+=t[6];
	a['o']+=t[6];

	a['p']+=t[7];

	a['q']+=t[7];
	a['q']+=t[7];

	a['r']+=t[7];
	a['r']+=t[7];
	a['r']+=t[7];

	a['s']+=t[7];
	a['s']+=t[7];
	a['s']+=t[7];
	a['s']+=t[7];
	
	a['t']+=t[8];
	
	a['u']+=t[8];
	a['u']+=t[8];
	
	a['v']+=t[8];
	a['v']+=t[8];
	a['v']+=t[8];
	
	a['w']+=t[9];
	
	a['x']+=t[9];
	a['x']+=t[9];

	a['y']+=t[9];
	a['y']+=t[9];
	a['y']+=t[9];
	
	a['z']+=t[9];
	a['z']+=t[9];
	a['z']+=t[9];
	a['Z']+=t[9];
	
	cin>>s;
	for(i=0;i<s.size();++i){
		if(i!=0){
			if(a[s[i-1]][0]==a[s[i]][0]){
				cout<<"#";
			}
		}
		cout<<a[s[i]];
	}
	return 0;
}