#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int a,b,cnt;
int main () {
	for(a=1;a<=100000000;++a){
		int b=sqrt(100000000-(a*a));
		if(b*b==100000000-(a*a)) 	++cnt;
	}
	cout <<cnt;
	return 0;
}