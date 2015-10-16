#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

#define N 51
#define end can

using namespace std;
class Cdgame {
	
	public:
    int rescount(vector <int> a, vector <int> b) {
    	int sum1 = 0, sum2 = 0;
    	for (auto it : a)
    		sum1 += it;
    	for (auto it : b)
    		sum2 += it;
    
    	set <int> Set;
    	
    	for (auto it1 : a)
    		for (auto it2 : b)
    			Set.insert ((sum1 - it1 + it2) * (sum2 - it2 + it1));
    
    	return Set.size ();
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif