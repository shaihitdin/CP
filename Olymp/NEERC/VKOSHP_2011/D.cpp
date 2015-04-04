#include<iostream>
#include<stdio.h>
using namespace std;
int n,tmpans=1000001,tmp1,tmp2;
inline int gcd(int a,int b){
	return ((b)? (gcd(b,a%b)) : (a));
}
int main(){
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
	cin >> n;
	for (int x = 0; x <= n; ++x) {
		if ((n - (x * 2)) % 3 != 0)	continue;
		int y = (n - (x * 2)) / 3;
		if (x + y < tmpans) {
			tmpans = x + y;
			tmp1 = x;
			tmp2 = y;
		} 
	}
	cout << tmp1 << " " << tmp2;
	return 0;
}