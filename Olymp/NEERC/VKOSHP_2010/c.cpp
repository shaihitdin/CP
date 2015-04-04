#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <set>
using namespace std;
#define file "differ."

typedef long long ll;

set <ll> st;
ll a, b;

int ans;

int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
	scanf("%I64d %I64d", &a, &b);
	st.insert(a + b);
	st.insert(a * b);
	st.insert(a - b); 
	st.insert(b - a);
	if (b) 
		st.insert(a / b);
	if (a) 
		st.insert(b / a);     
	///	
	ans += st.size();
	if (abs(a) > abs(b)) 
		swap(a, b);

	if (a == 0) {
		st.insert(1);
		ans = st.size();
	}
	if (a == 1) {
		if (b >= 0) st.insert(1);
		ans = st.size();
	}	
	if (a == -1) {
		if (b >= 0) 
			st.insert((b & 1) ? -1 : 1);
		ans = st.size();
	}
	if (a == 2) {
		st.insert(b * b);
		if (b >= 0) {
			if (b < 40) {
				st.insert((1 << b));
				ans = st.size();
			}	
			else
				++ans;
		}   
	}
	if (a == -2) {
		if (b >= 0) {
			if (b < 40) {
				st.insert((1 << b) * ((b & 1) ? -1 : 1));
				ans = st.size();	
			}	
			else 
				++ans;	
		}	
	}
	if (abs(a) == 3) {
		if (a > 0 && b > 0) 
			ans += 1 + (a != b);
		if ((a > 0) + (b > 0) == 1) 
			++ans;		
	}
	printf("%d", ans);
}
