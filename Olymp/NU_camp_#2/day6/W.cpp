#include<iostream>
#include<string>
using namespace std;
long long a;
int ans;
int main() {
	cin >> a;
	for (int i=a; i; i=((i>>1)+(i&1))-1) ++ans;
	cout << ans << " " << (a>>1)+(a&1);                        
	return 0;
}
