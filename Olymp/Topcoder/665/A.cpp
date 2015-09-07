#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class LuckyXor {
	
	public:
    int construct(int a) {
    	for (int b = 1; b <= 100; ++b) {
    		int x = a ^ b;
    		if (x == 0)
    			continue;
    		bool flag = 1;
    		while (x) {
    			if (x % 10 != 7 && x % 10 != 4)
    				flag = 0;
    			x /= 10;
    		}
    		if (flag)
    			return b;
    	}
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif