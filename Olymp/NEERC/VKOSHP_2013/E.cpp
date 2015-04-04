#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
#define mkp make_pair
int n,m;
map <pair<string, string>, bool> mp;
string c, x, s;
int i, j, k;
int main(){
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>c>>j;
		++j;
		while(--j){
			cin>>x;
			mp[mkp(c,x)]=1;
		}
	}
	cin>>m;
	for(k=1;k<=m;++k){
		cin>>s;
		bool flag=0;
		for(i=1;i<=3;++i){
			for(j=3;j<=5;++j){
				if(mp[mkp(s.substr(0,i),s.substr(i,j))]){
					if(s[i+j]=='0')
						continue;
					cout<<"+"<<s.substr(0,i)<<"("<<s.substr(i,j)<<")";
					flag=1;
					if(11-i-j==7){
						cout<<s.substr(i+j,3)<<"-"<<s.substr(i+j+3,2)<<"-"<<s.substr(i+j+5);
					}
					if(11-i-j==6){
						cout<<s.substr(i+j,2)<<"-"<<s.substr(i+j+2,2)<<"-"<<s.substr(i+j+4);
					}
					if(11-i-j==5){
						cout<<s.substr(i+j,3)<<"-"<<s.substr(i+j+3);
					}
					if(11-i-j==4){
						cout<<s.substr(i+j,2)<<"-"<<s.substr(i+j+2);
					}
					if(11-i-j==3){
						cout<<s.substr(i+j);
					}
					cout<<"\n";
				}
			}
		}
		if(!flag){
			cout<<"Incorrect\n";
		}
	}
	return 0;
}