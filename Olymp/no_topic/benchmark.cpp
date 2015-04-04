#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int N=100000001;
int n;
int z[N];
char s[N];
int main(){
	srand(time(0));
	for(i=0;i<N;++i)
	  s[i]='a'+(rand()%26);
	n=N;
	    for (int i = 1, l = 0, r = 1; i < n; ++i, r = i < r ? r : i)
        for (z[i] = min(r - i, z[i - l]); s[i + z[i]] == s[z[i]]; ++z[i], r = i + z[i], l = i);

	  printf("%f",(float(clock())/CLOCKS_PER_SEC));
return 0;}