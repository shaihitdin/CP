#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int w, h, l, k;

int main () {

	freopen ("painting.in", "r", stdin);
	freopen ("painting.out", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);  

	cin >> w >> h >> l >> k;
	if (w > h) swap(w, h);
	if (h > l) swap(h, l);
	if (w > h) swap(w, h);

	if (k == 6) {          
		printf("%d\n", (l == 1 ? 1 : 0));
	}
	if (k == 5) {
		if (w == 1 && h == 1) 
			printf("%d\n", (l == 1 ? 1 : 2));
		else
			printf("0\n");                                              
	}
	if (k == 4) {
		if (w == 1 && h == 1)
			printf("%d\n", max(0, l - 2));
		else
			printf("0\n");
	}
	if (k == 0) {
		printf("0\n");
	}
	if (k == 1) {
		if (w >= 2) {
			int wh = (w - 2) * (h - 2);
			int wl = (w - 2) * (l - 2);
			int hl = (h - 2) * (l - 2);
			printf("%d\n", wh + wl + hl);
		}	
		else {
			printf("0\n");
		}
	}
	if (k == 2) {
		int ans = (w - 2) * 3 + (h - 2) * 3 + (l - 2) * 3;
		printf("%d\n", ans);
	}
	if (k == 3) {
		if (w >= 2)
			printf("8\n");
		else
			printf();	
	}
	
	return 0;
}