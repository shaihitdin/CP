#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;
const int N = 210;

class RedAndBluePoints {
	
	public:
    int find(vector <int> blueX, vector <int> blueY, vector <int> redX, vector <int> redY) {
    	int b_cnt = blueX.size (), r_cnt = redX.size ();
    	bool valid[N][N][N];
    	int dp[2][N][N][N];
    	int cnt[N][N][N];
    	memset (cnt, 0, sizeof (cnt));
    	memset (dp, 0, sizeof (dp));
    	memset (valid, 1, sizeof (valid));
    	for (int i = 0; i < b_cnt; ++i)
    		cc.emplace_back (blueX[i]), cc.emplace_back (blueY[i]);
    	for (int i = 0; i < r_cnt; ++i)
    		cc.emplace_back (redX[i]), cc.emplace_back (redY[i]);
    	sort (cc.begin (), cc.end ());
    	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
    	for (int i = 0; i < b_cnt; ++i)
    		blueX[i] = lower_bound (cc.begin (), cc.end (), blueX[i]) + 1, blueY[i] = lower_bound (cc.begin (), cc.end (), blueY[i]) + 1;
    	for (int i = 0; i < r_cnt; ++i)
    		redX[i] = lower_bound (cc.begin (), cc.end (), redX[i]) + 1, redY[i] = lower_bound (cc.begin (), cc.end (), redY[i]) + 1;
    	for (int i = 0; i < r_cnt; ++i)
    		valid[redX[i]][redY[i]][redY[i]] = 0;
    	for (int i = 0; i < b_cnt; ++i)
    		++cnt[blueX[i]][blueY[i]][blueY[i]];
    	for (int i = 0; i < N; ++i)
    		for (int j = 0; j < N; ++j)
    			for (int k = j + 1; k < N; ++k)
    				valid[i][j][k] = valid[i][j][k - 1] & valid[i][k][k], cnt[i][j][k] = cnt[i][j][k - 1] + cnt[i][k][k];
    	for (int i = 0; i < N; ++i) {
    		for (int j = 0; j < N; ++j) {
    			for (int k = 0; k < N; ++k) {
    				if (valid[i][j][k])
    					dp[i][j][k] = max (dp[i - 1][j][k]);
    			}
    		}
    	}
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif