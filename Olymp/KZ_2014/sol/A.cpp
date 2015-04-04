#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#ifdef _WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif
long long ans[8],n,i,j,x;
bool flag,flag1;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf(I64,&n);
	if(n<14){
		printf("-1");
		return 0;
	}
	n-=4*2;
	x=2+(n&1);
	n-=x;
	for(i=n-2;i>=1;--i){
		flag=0;
		flag1=0;
		for(j=2;j*j<=i;++j){
			if(!(i%j)){	
				flag=1;
				break;
			}
		}
		if(flag!=1){
			for(j=2;j*j<=n-i;++j){
				if(!((n-i)%j)){
					flag1=1;
					break;
				}		
			}
			if(flag1!=1){
				printf("2 2 2 2 "I64" "I64" "I64,x,i,n-i);
				exit(0);
			}		
		}
	}
	return 0;
}