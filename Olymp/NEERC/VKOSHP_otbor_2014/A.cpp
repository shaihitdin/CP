#include<iostream>
#include<stdio.h>
using namespace std;
int t,x,y;
char a,b,c,d;
int main(){
	
	freopen("abcd.in","r",stdin);
	freopen("abcd.out","w",stdout);
	scanf("%d\n",&t);
	++t;
	while(--t){
		scanf("%c%c%c%c\n",&a,&b,&c,&d);
		x=(a-'0')*10+(b-'0');
		y=(c-'0')*10+(d-'0');
		if((x*x+y*y)%7==1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}