#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long a[200001],n,i,tmp1,tmp2;
int main(){
    /*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	scanf("%I64d", &n);
	for(i=1; i <= n; ++i)
		scanf("%I64d", &a[i]);
	sort (a + 1, a + n + 1);
	tmp1=1;
	while(a[tmp1] == a[1] && tmp1 <= n) {
		++tmp1;
	}	
	--tmp1;
	tmp2=n;
	while(a[tmp2] == a[n] && tmp1 >= 1) {
		--tmp2;
	}
	++tmp2;
	cerr<<tmp1<< " " << tmp2;
	printf("%I64d %I64d", (a[n]-a[1]), (tmp1*((n*1ll)-tmp2+1)));
	return 0;
}