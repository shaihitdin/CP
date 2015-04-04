#include <iostream>
#include <vector>
#include <string.h>
#include <string>


using namespace std;

typedef long long ll;
typedef unsigned int ui;
const int N = 101;

bool u[N];
vector <string> graph1;

class Fragile2 {
	
	public:
	void dfs (int v) {
		if (u[v])
			return;
		u[v] = 1;
		for (int i = 0; i < graph1[v].size(); ++i)
			if (graph1[v][i] == 'Y')
				dfs (i);
	}

    public:
    int countPairs (vector <string> graph) {
        memset (u, 0, sizeof (u));
        graph1 = graph;
        int n_c = 0, ans = 0;
    	for (int i = 0; i < graph1.size(); ++i) {
    		if (!u[i]) {
    			dfs (i);
    			++n_c;
    		}
    	}
    	for (int i = 0; i < graph1.size(); ++i) {
    		for (int j = i + 1; j < graph1.size(); ++j) {
    			memset (u, 0, sizeof (u));
    			u[i] = 1;
    			u[j] = 1;
    			int c_n = 0;
    			for (int k = 0; k < graph1.size(); ++k) {
    				if (!u[i]) {
    					dfs (i);
    					++c_n;
    				}
    			}
    			if (c_n > n_c)
    				++ans;
    		}
    	}
    	return ans;
    }

};
