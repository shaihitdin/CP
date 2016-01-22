#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
    int n, a[11], u[11];
	cin >> n;

	for (int i = 1; i <= n; ++i)
		a[i] = 1;
    a[n + 1] = 0;
	while (1) {
		bool valid = 1;
		for (int i = 1; i <= n; ++i) {
            u[i] = 0;
		}
        for (int i = 1; i <= n; ++i) {
            if (u[a[i]] == 1) {
                valid = 0;
            }
            u[a[i]] = 1;
        }
        if (valid == 0) {
	        ++a[1];
	        for (int i = 1; i <= n; ++i)
	            if (a[i] == n + 1)
	                a[i] = 0, a[i + 1]++;
	        if (a[n + 1] == 1)
	                break;
        	continue;
        }
        for (int i = 1; i <= n; ++i) {
            int posx = i + 1, posy = a[i] + 1;
            for (; posx >= 1 && posx <= n && 1 <= posy && posy <= n; ++posx, ++posy) {
                if (a[posx] == posy)
                    valid = 0;
            }
            posx = i + 1, posy = a[i] - 1;
            for (; posx >= 1 && posx <= n && 1 <= posy && posy <= n; ++posx, --posy) {
                if (a[posx] == posy)
                    valid = 0;
            }
            posx = i - 1, posy = a[i] + 1;
            for (; posx >= 1 && posx <= n && 1 <= posy && posy <= n; --posx, ++posy) {
                if (a[posx] == posy)
                    valid = 0;
            }
            posx = i - 1, posy = a[i] - 1;
            for (; posx >= 1 && posx <= n && 1 <= posy && posy <= n; --posx, --posy) {
                if (a[posx] == posy)
                    valid = 0;
            }
        }
        if (valid == 1) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (j == a[i]) {
                        cout << "1";
                    } else {
                        cout << "0";
                    }
                }
                cout << "\n";
            }
            cout << "\n";
        }
        ++a[1];
        for (int i = 1; i <= n; ++i)
            if (a[i] == n + 1)
                a[i] = 0, a[i + 1]++;
        if (a[n + 1] == 1)
                break;
	}

	return 0;
}
