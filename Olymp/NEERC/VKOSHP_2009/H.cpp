#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100001;
int i,a[N],n,pos;
int main(){
	freopen("next.in","r",stdin);
	freopen("next.out","w",stdout);
	scanf("%d",&n);
	scanf("=");
	while(cin>>a[i]){
		scanf("+");
		++i;
	}
	pos=i-1;
	if(pos==1){
		puts("No solution");
	}
	return 0;
}