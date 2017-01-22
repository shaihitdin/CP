#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

int cnt[20][10];
int pw10[20];

class ReplacingDigit {

    inline void addc (int x) {
    	for (int i = 0; i <= 7 && x; ++i) {
    		int s = x % 10;
    		++cnt[i][s];
    		x /= 10;
    	}
    }
    
	public:
    int getMaximumStockWorth(vector <int> A, vector <int> D) {
    	int ans = 0;
    	for (int it : A) {
    		addc (it);
    		ans += it;
    	}
    	pw10[0] = 1;
    	for (int i = 1; i <= 7; ++i)
    		pw10[i] = pw10[i - 1] * 10;
    	for (int nw = 8; nw >= 0; --nw) {
    		for (int i = 19; i >= 0; --i) {
    			for (int j = 0; j <= nw; ++j) {
    				int can = min (D[nw], cnt[i][j]);
    				if (!can)
    					continue;
    				ans += (nw + 1 - j) * (pw10[i]) * can;
    				D[nw] -= can;
    				cnt[i][j] -= can;
    			}
    		}
    	}
    	return ans;
    }

};

#ifdef LOCAL
int main() {


}
#endif