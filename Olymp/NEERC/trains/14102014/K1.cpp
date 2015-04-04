#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
vector<int> v[10001];
bool a[10001][256],u[10001][256];
int x,n,m,k,from,to,i;
char y;
string s;
int main(){
	freopen("kripke.in","r",stdin);
	freopen("kripke.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;++i){
		cin>>x;
		++x;
		while(--x){
			cin>>y;
			a[i][y]=1;
		}
	}
	for(i=1;i<=m;++i){
		cin>>from>>to;
		v[from].push_back(to);
	}
	cin>>s;
	char x1=s[2],x2=s[7];
	for(i=1;i<=n;++i){
		if(a[i][int(x1)] && a[i][int(x2)]){
			printf("1\n%d",i);
			return 0;
		}
	}
	printf("0");
	return 0;
}