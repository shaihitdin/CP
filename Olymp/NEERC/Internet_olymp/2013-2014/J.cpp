#include<iostream>
#include<stdio.h>
using namespace std;
bool u[21];
int main(){
	freopen("cave.in","r",stdin);
	freopen("cave.out","w",stdout);
	scanf("%d",&n);
	for(i=n;i>=1;--i){
		u[1]=1;
		ans.push_back(1);
		for(j=2;j<=i;++j){
			if(j!=2){
				ans.push_back(j-2);
			}
			else{
				ans.push_back(j);
			}
		}
	}
	return 0;
}