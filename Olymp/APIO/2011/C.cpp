#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int N=1001;
string s[N];
int i,j,d[N][N],tmp[N],c,n,k;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>c;
	++c;
	while(--c){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>s[i];
		}
		memset(tmp,1,sizeof(tmp));
		for(i=1;i<=n;++i){
			for(j=i+1;j<=n;++j){
				if(s[i].size()!=s[j].size())
					continue;
			    int bx=0;
				for(k=0;k<s[i].size();++k)
					if(s[i][k]==s[j][k])	++bx;
				if(bx==s[i].size()-1)	++tmp[i];
			}
			if(tmp[i]-2==int(s[i].size())){
				cout<<"Yes\n";
				goto here;
			}
		}
		cout<<"No\n";
		here:;
	}
	return 0;
}