#include<iostream>
#include<stdio.h>
using namespace std;
#define minus 0
#define plus 1
#define mult 2
#define F
long long tmp,now=0,len,last_op,tmp1,tmp2;
inline pair<int,int> rec(int pos,int lstop){
	int i=pos;
	while(s[i]>='0' && s[i]<='9')	++i;
	if(s[i]=='*'){
		rec(pos+1)
	}	
	if(s[i]=='+'){
	
	}
	if(s[i]=='-'){
	
	}
	if(pos==0){
	
	}
	else{
		
	}
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	ios_base::sync_with_stdio(0)
	cin>>s;
	cin>>x;
	cin>>y;
	ans=rec(0,-1);
	return 0;
}