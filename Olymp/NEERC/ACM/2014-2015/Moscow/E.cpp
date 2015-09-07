#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int till = sqrt (1e15) + 1;
ll n, d;

inline int get_ans (const ll &base) {
	ll now = n;
	int ans = 0;
	while (now) {
		if (now % base == d)
			++ans;
		else
			break;
		now /= base;
	}
	return ans;
}

int main () {

    #ifdef LOCAL
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif
    
    cin >> n >> d;

    if (n == 0) {
    	if (d == 0) {
    		cout << "2 1";
    		return 0;
    	}
    	cout << "2 0";
    	return 0;
    }

    ll b_base, b_ans;

    b_base = 2, b_ans = get_ans (2);
    
    for (int i = 3; i < till; ++i) {
    	int get = get_ans (i);
    	if (get > b_ans) {
    		b_base = i;
    		b_ans = get;
    	}
    }
    
    if (n > till && get_ans (n - d) > b_ans) {
    	b_base = n - d;
    	b_ans = get_ans (n - d); 
    }

    if (d != 0 && n > till && get_ans ((n - d) / d) > b_ans) {
    	b_base = (n - d) / d;
    	b_ans = get_ans ((n - d) / d);
    }
    
    cout << b_base << " " << b_ans;
    
    return 0;
}