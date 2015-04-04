#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	freopen("in","w",stdout);
	unsigned n=100000000;
	srand(time(0));
	printf("%u\n",n);
	for(unsigned i=1;i<=n;++i){
		printf("%u ",(rand()<<16)^rand());
	}
	return 0;
}