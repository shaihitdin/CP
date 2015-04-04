#include<iostream>
#include<stdio.h>
using namespace std;
int n,d,a[1001];
inline int gcd(int a,int b){
	return ((b)? (gcd(b,a%b)) : (a));
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin >> n >> d;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (gcd (a[i], a[j]) == d) {
				cout << 2 << "\n" << a[i] << " " << a[j];
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}