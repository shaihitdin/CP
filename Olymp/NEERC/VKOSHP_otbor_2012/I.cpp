#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;
char ch[256];
long long a[11],b[11];
int cnt,n;
string t[11],s[11];
bool u[256];
inline long long to_num(const string &t){
	long long ret_val=0;
	for(int i=0;i<t.size();++i){
		ret_val=ret_val*10*1ll+t[i];
	}
	return	ret_val;
}
inline void rec(int lvl){
	if(lvl==10){
		for(int i='a';i<='j';++i){
			for(int j=i+1;j<='j';++j){
				if(ch[i]==ch[j]){
					return;
				}
			}
		}
		for(int i=1;i<=n;++i){
			t[i]=s[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<t[i].size();++j){
				t[i][j]=ch[t[i][j]];
			}
		}
		for(int i=1;i<=n;++i){
			a[i]=to_num(t[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i])
				return;
		}
		cout<<"Yes\n";
		for(int i='a';i<='j';++i){
			cout<<ch[i]<<" ";
		}
		exit(0);
	}
	for(int i='a';i<='j';++i){
		if(!u[i]){
			ch[i]=lvl;
			u[i]=1;
			rec(lvl+1);
			u[i]=0;
		}
	}
	return;
}
int main(){
	freopen("tiv.in","r",stdin);
	freopen("tiv.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	rec(0);
	cout<<"No";
	cerr<<cnt<<"\n";
	fprintf(stderr,"%.3lf",float(clock())/CLOCKS_PER_SEC);
	return 0;
}