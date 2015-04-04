#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define minus 0
#define plus 1
#define mult 2
long long i;
int main(){
	ios_base::sync_with_stdio(0);
	for(i=0;i<=100000000;i=i+1){
		//cerr<<sqrt(i*10.0)<<" "<<cbrt(i*6.0)<<"\n";
		if((sqrt(i*10.0))==(int(sqrt(i*10.0)))*1.0 && (cbrt(i*6.0))==(int(cbrt(i*6.0)))*1.0){
			cout<<i<<"\n";		
		}
		
	}
	return 0;
}