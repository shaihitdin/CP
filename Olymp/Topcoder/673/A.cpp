#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;

class BearCavalry {
	
	public:
    int countAssignments(vector <int> warriors, vector <int> horses) {
    	int n = warriors.size ();
    	sort (warriors.begin () + 1, warriors.end ());
    	sort (horses.begin (), horses.end ());
    	reverse (warriors.begin () + 1, warriors.end ());
    	int ans = 0;
    	for (int i = 0; i < n; ++i) {
    		int now = warriors[0] * horses[i];
    		int lsl = horses[i];
    		horses.erase (horses.begin () + i);
			int tmp = 1;
			for (int j = 1; j < n; ++j) {
				int till_ok = n - 1;
				for (int k = 0; k < n - 1; ++k) {
					if (warriors[j] * horses[k] >= now) {
						till_ok = k;
						break;
					}
				}
				tmp = (tmp * 1ll * (till_ok - j + 1)) % bpr;
			}
			ans = (ans + tmp) % bpr;
    		horses.insert (horses.begin () + i, lsl);
    	}
    	return ans;
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif