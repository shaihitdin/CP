#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

#define N 51
#define end can

using namespace std;
class WalkOverATree {
	
	public:
    int maxMascots(vector <int> a) {
    	sort (a.begin (), a.end ());
    	int ans = 0;
    	while (a.size () > 1) {
    		int x = a[a.size () - 1];
    		int y = a[a.size () - 2];
			ans += x * y;
			a[a.size () - 2] += x;
    		a.pop_back ();
    	}
    	return ans;
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif