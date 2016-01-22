#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;

class BagAndCards {
	
	void add (int &x, int y) {
		x += y;
		if (x >= bpr)
			x -= bpr;
		x += bpr;
		if (x >= bpr)
			x -= bpr;
	}
	
	public:
    int getHash(int n, int m, int x, int a, int b, int c, string isGood) {
    	int cnt[510][510], ans[510][510], t_ans[510][510], sum[510];
    	memset (cnt, 0, sizeof (cnt));
    	memset (ans, 0, sizeof (ans));
    	memset (t_ans, 0, sizeof (t_ans));
    	memset (sum, 0, sizeof (sum));
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			cnt[i][j] = x;
    			x = ((x * 1ll * a + b) ^ c) % bpr;
    		}
    	}
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < m; ++j)
    			add (sum[j], cnt[i][j]);
    	int res = 0;
    	for (int i = n - 1; i >= 0; --i) {
    		
    		for (int j = 0; j < m; ++j)
    			add (sum[j], -cnt[i][j]);
    		
    		for (int j = 0; j < m; ++j)
    			for (int k = i + 1; k < n; ++k)
    				add (t_ans[i][k], (cnt[i][j] * 1ll * ans[k][j]) % bpr);
    		
    		for (int j = i + 1; j < n; ++j)
    			res ^= t_ans[i][j];

    		for (int j = 0; j < m; ++j)
    			for (int k = 0; k < m; ++k)
    				if (isGood[j + k] == 'Y')
    					add (ans[i][k], cnt[i][j]);
    	}
    	return res;
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif