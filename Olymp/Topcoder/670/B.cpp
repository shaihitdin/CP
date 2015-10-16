#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

#define N 51
#define end can

using namespace std;
class Drbalance {
	
	int check (string s) {
		int res = 0, balance = 0;
		for (auto it : s) {
			if (it == '+')
				++balance;
			else
				--balance;
			if (balance < 0)
				++res;
		}
		return res;
	}
	
	
	public:
    int lesscng(string s, int k) {
    	
    	int ans = 0;

    	while (check (s) > k) {
    		for (auto &it : s) {
    			if (it == '-') {
    				++ans;
					it = '+';
    				break;
    			}
    		}
    	}
    	
    	return ans;
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif