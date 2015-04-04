#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
long long p[2001];
string s,t;
char ch;
long long k,i,tmp,d[2001][2001],j,ans;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>t>>s;
	for(i=1;i<t.size();++i){
		for(k=p[i-1];k>0 && t[i]!=t[k];k=p[k-1]);
		if(t[i]==t[k])	++k;
		p[i]=k;
	}
	d[0][0]=1;
	for(i=0;i<s.size();++i){
		for(j=0;j<t.size();++j){
			if(d[i][j]==0)	continue;
			if(s[i]=='?'){
				for(ch='a';ch<='z';++ch){
					k=j;
					while(k>0 && ch!=t[k])	k=p[k-1];
					if(ch==t[k])	++k;
					d[i+1][k]=(d[i+1][k]+d[i][j])%1000000007;				
				}
			}
			else{
				k=j;
				while(k>0 && s[i]!=t[k])	k=p[k-1];
				if(s[i]==t[k])	++k;
				d[i+1][k]=(d[i+1][k]+d[i][j])%1000000007;
			}
		}
	}
	for(i=0;i<=s.size();++i){
		for(j=0;j<=t.size();++j){
			cerr<<d[i][j]<<" ";
		}                            
		cerr<<"\n";
	}
	for(i=0;i<=s.size();++i){
		tmp=1;
		for(j=i;j<s.size();++j){
			if(s[j]=='?')
				tmp=(tmp*26)%1000000007;
		}
		ans=(ans+(d[i][t.size()]*tmp))%1000000007;
	}
	cout<<ans;
	return 0;
}