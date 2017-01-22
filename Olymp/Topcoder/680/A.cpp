/// Oh, my dear

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;

class BearFair {
	
	public:
    string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
    	vector <pair <int, int> > a;
    	int q = upTo.size ();
    	for (int i = 0; i < q; ++i) {
    		a.emplace_back (make_pair (upTo[i], quantity[i]));
    	}
    	int now = 1;
    	vector <int> odd, even;
    	sort (a.begin (), a.end ());
    	
    	for (int i = 1; i < q; ++i)
    		if (a[i].first - a[i - 1].first < a[i].second - a[i - 1].second)
    			return "unfair";
    	
    	for (int i = 1; i < q; ++i) {
    		if (a[i].first - a[i - 1].first == a[i].second - a[i - 1].second) {
    		}
    	}
    	for (int i : odd)
    		u[i] = 1;
    	for (int i : even)
    		u
    	for (int i = 0; i < q; ++i) {
    		while (odd.size () + even.size () <= quantity[i]) {
    			if (odd.size () == even.size ()) {
    				if (now & 1)
    					odd.emplace_back ()
    			}
    			if (odd.size () < even.size ()) {
    			
    			} else {
    			
    			}
    		}
    	}
    }

};

#ifdef BROKEN
int main () {
	
	return 0;
}
#endif