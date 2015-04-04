#include<iostream>
#include<stdio.h>
using namespace std;
char a[2001][2001];
int n,m,i,j;
int main(){
	freopen("tic-tac-toe.in","r",stdin);
	freopen("tic-tac-toe.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(
			(a[i][j]=='O' && a[i][j+1]=='O' && a[i][j+2]=='O' && a[i][j+3]=='O' && a[i][j+4]=='O') 
			|| 
			(a[i][j]=='O' && a[i+1][j]=='O' && a[i+2][j]=='O' && a[i+3][j]=='O' && a[i+4][j]=='O') 
			|| 
			(a[i][j]=='O' && a[i+1][j+1]=='O' && a[i+2][j+2]=='O' && a[i+3][j+3]=='O' && a[i+4][j+4]=='O')
			||
			(j>=5 && (a[i][j]=='O' && a[i+1][j-1]=='O' && a[i+2][j-2]=='O' && a[i+3][j-3]=='O' && a[i+4][j-4]=='O'))) {
				cout<<"Yes";
				return 0;
			}
			if(
			(a[i][j]=='X' && a[i][j+1]=='X' && a[i][j+2]=='X' && a[i][j+3]=='X' && a[i][j+4]=='X') 
			|| 
			(a[i][j]=='X' && a[i+1][j]=='X' && a[i+2][j]=='X' && a[i+3][j]=='X' && a[i+4][j]=='X') 
			|| 
			(a[i][j]=='X' && a[i+1][j+1]=='X' && a[i+2][j+2]=='X' && a[i+3][j+3]=='X' && a[i+4][j+4]=='X')
			||
			(j>=5 && (a[i][j]=='X' && a[i+1][j-1]=='X' && a[i+2][j-2]=='X' && a[i+3][j-3]=='X' && a[i+4][j-4]=='X'))) {
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
return 0;
}