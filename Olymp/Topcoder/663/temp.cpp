#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class ABBA {
    
	
	char dp[1001][1001];
	string ans_st;

	public:
	inline bool dp_calc (const int &l, const int &r) {
		if (dp[l][r] != 0)
			return dp[l][r] - 1;
		dp[l][r] = Search (ans_st.substr (l, r - l + 1), 0);
		++dp[l][r];
		return dp[l][r] - 1;
	}
	
	public:
	inline bool Search (string a, const int &lvl) {
		if (a.size () > ans_st.size ())
			return 0;
		for (int i = 0; i + a.size () - 1 < ans_st.size (); ++i)
			if (!memcmp (&ans_st[i], &a[0], a.size ()))
				if (dp_calc (i, i + a.size () - 1))
					return 1;		
		if (lvl == 2)
			return 0;
		if (Search (a + 'A', lvl + 1))
			return 1;
		reverse (a.begin (), a.end ());
		if (Search ('B' + a, lvl + 1))
			return 1;
		return 0;
	}
	
	public:
    string canObtain(string initial, string target) {
    	ans_st = target;
    	dp[0][target.size () - 1] = 1;
    	if (Search (initial, 0))
    		return "Possible";
    	return "Impossible";
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif