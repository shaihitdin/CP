#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class BearPlays {
	
	map <int, int> mp;
	
	public:
    int pileSize(int a, int b, int k) {
    	if (a > b)
    		swap (a, b);
    	mp[a] = 0;
    	int cnt = 0;
    	for (;; ++cnt, --k) {
    		if (a > b)
    			swap (a, b);
    		if (!k)
    			return a;
    		if (cnt && mp.count (a)) {
    			cnt -= mp[a];
    			break;
    		}
            mp[a] = cnt;
            b -= a;
    		a += a;
    	}
    	k %= cnt;
    	while (k) {
    		if (a > b)
    			swap (a, b);
    		b -= a;
    		a += a;
    		--k;
    	}
    	if (a > b)
    		swap (a, b);
    	return a;
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif