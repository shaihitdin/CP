#include <iostream>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class ExploringNumbers {
    
	inline bool isprime (int x) {
		for (int i = 2; i * i <= x; ++i)
			if (x % i == 0)
				return 0;
		return 1;
	}
    
    inline int nx (int x) {
    	int res = 0;
    	while (x) {
    		int s = x % 10;
    		res += s * s;
    		x /= 10;
    	}
    	return res;
    }
    
    public:
    int numberOfSteps(int n) {
    	int x = n;
    	for (int i = 1; i < min (n, 10000); ++i) {
    		if (isprime (x))
    			return i;
    		x = nx (x);
    	}
    	return -1;
    }

};

#ifdef LOCAL
int main() {


}
#endif