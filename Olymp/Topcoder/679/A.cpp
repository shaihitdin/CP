#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;

class FiringEmployees {
	
	public:
    int fire(vector <int> manager, vector <int> salary, vector <int> productivity) {
    	manager.insert (manager.begin (), 0);
    	salary.insert (salary.begin (), 0);
    	productivity.insert (productivity.begin (), 0);
    	int n = manager.size () - 1;
		vector <int> g[n + 1];
    	for (int i = 1; i <= n; ++i)
    		g[manager[i]].emplace_back (i);
		int sum[n + 1];
		memset (sum, 0, sizeof (sum));
		for (int i = n; i >= 0; --i) {
			sum[i] = productivity[i] - salary[i];
			for (auto to : g[i])
				sum[i] += max (0, sum[to]);
		}
		return sum[0];
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif