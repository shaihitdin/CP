#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class LuckySum {
	
	inline bool bit (const int &mask, const int &pos) {
		return (mask >> pos) & 1;
	}
	
	public:
    ll construct(string note) {
        int n = note.size ();
    	ll mx = 0, mn = 0;
        for (int i = 0; i < n; ++i) {
        	if (note[i] == '?') {
                if (i == 0)
                    mn = mn * 10 + 1;
            	else
                    mn = mn * 10 + 0;
            	mx = mx * 10 + 9;
            } else {
            	mx = mx * 10 + (note[i] - '0');
                mn = mn * 10 + (note[i] - '0');
            }
        }
    	reverse (note.begin (), note.end ());
        ll d[60000];
        bool was[60000];
        for (int i = 0; i < 60000; ++i)
            	was[i] = 0;
        int cnt = 0;
    	for (int i = 0; i < (1 << note.size ()); ++i) {
    		ll res = 0;
    		int now = 0;
            for (int j = 0; j < n; ++j) {
    			
                if (bit (i, j))
    				res = res * 10 + 4, now |= (1 << j);
    			else
    				res = res * 10 + 7;
                if (!was[now])
	                d[++cnt] = res, was[now] = 1;
            }
    	}
        ll ans = 1e18;
    	sort (d + 1, d + cnt + 1);
        for (int i = 1; i <= cnt; ++i) {
    		for (int j = (lower_bound (d + 1, d + cnt + 1, mn - d[i]) - d); j <= cnt && d[i] + d[j] <= min (ans - 1, mx); ++j) {
    			ll res = d[i] + d[j];
    			int pos = 0;
    			for (; pos < n && res; res /= 10, ++pos) {
    				if (note[pos] == '?')
    					continue;
    				if (note[pos] != '0' + (res % 10))
    					break;
    			}
    			if (res || pos < n)
    				continue;
                ans = min (ans, d[i] + d[j]);
            }
    	}
    	if (ans == 1e18)
	        return -1;
		return ans;
    }

};

inline ll rnd () {
	return rand () * rand () * rand () * rand ();
}

#ifdef LOCAL
int main () {
	
	for (int i = 1; i <= 100; ++i) {
		ll val = 1e14;
		val += (rnd ())
	}
	
	return 0;
}
#endif