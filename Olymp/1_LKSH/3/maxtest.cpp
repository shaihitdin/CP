#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int N = 1000001;
char s[N];
int cnt[N];
int p[N], c[N], cn[N], pn[N], i;
int main() {
	freopen("cyclic.in", "w", stdout);
	srand(time(0));
	for(i = 1; i <= 1000000; ++i) {
		printf("%c", char('a' + (rand() % 25) ) );
		
	}
return 0;}