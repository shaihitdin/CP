/*
ID: shaihit1
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
string ss[5001];
char s[5001];
bool u[5001],u1[5001],u2[5001];
int i,j,n,k;
string ac[10]={"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
string f;
int main(){
	FILE * dict = fopen("dict.txt","r");
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	for(i=1;i<=4617;++i){
		fscanf(dict,"%s",s);
		n=strlen(s);
		for(j=0;j<n;++j){
			ss[i]+=s[j];
		}
		memset(s,0,sizeof(s));
	}
	cin>>f;
	memset(u,1,sizeof(u));
	for(i=0;i<f.size();++i){
		int x=f[i]-'0';
		for(k=0;k<ac[x].size();++k){
			for(j=1;j<=4617;++j){
				if(ac[x][k]==ss[j][i]){
					u1[j]=1;
				}
			}
		}
		for(j=1;j<=4617;++j){
			u2[j]=(u[j]&u1[j]);
		}
		memcpy(u,u2,sizeof(u2));
		memset(u1,0,sizeof(u1));
	}
	int cnt=0;
	for(i=1;i<=4617;++i){
		if(u[i] && f.size()==ss[i].size()){
			cout<<ss[i]<<"\n";
			++cnt;
		}
	}
	if(!cnt){
		cout<<"NONE\n";
	}
	return 0;
}