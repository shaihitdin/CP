#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class LuckyCycle {
	
	public:
    vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
    	int n = edge1.size () + 1;
		int d[2][n + 1][n + 1];
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					d[i][j][k] = 1e8;
		for (int i = 0; i < edge1.size (); ++i) {
			if (weight[i] == 4) {
				d[0][edge1[i]][edge2[i]] = 1, d[0][edge2[i]][edge1[i]] = 1;
				d[1][edge1[i]][edge2[i]] = 0, d[1][edge2[i]][edge1[i]] = 0;
			}
			else {
				d[1][edge1[i]][edge2[i]] = 1, d[1][edge2[i]][edge1[i]] = 1;
				d[0][edge1[i]][edge2[i]] = 0, d[0][edge2[i]][edge1[i]] = 0;
	    	}
		}
		
		for (int i = 1; i <= n; ++i)
			d[0][i][i] = d[1][i][i] = 0;

		for (int l = 0; l < 2; ++l)
			for (int k = 1; k <= n; ++k)
				for (int i = 1; i <= n; ++i)
					for (int j = 1; j <= n; ++j)
						d[l][i][j] = min (d[l][i][j], d[l][i][k] + d[l][k][j]);

    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			if (d[0][i][j] + d[1][i][j] > 1 && abs (d[0][i][j] - d[1][i][j]) == 1) {
    				if (d[0][i][j] < d[1][i][j])
    					return {i, j, 4};
    				return {i, j, 7};
    			}
    		}
    	}
    	return {};
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif