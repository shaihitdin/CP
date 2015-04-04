#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#ifdef _WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif
unsigned n, m, a[100000001];
inline int readUInt()
{
  int c = getchar();
  int x = 0;
  while (c <= 32)
    c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return x;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	n=readUInt();
	for(int i=1;i<=n;++i){
		a[i]=readUInt();
	}
	fprintf(stderr, "%f", 1.0 * clock()/CLOCKS_PER_SEC);
	return 0;
}