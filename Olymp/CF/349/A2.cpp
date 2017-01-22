/// izizi

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

vector <string> ans;

int d[N];
string s;

inline int entry (const string &df, int st) {
	int res = 0;
	for (; st + df.size () <= s.size (); ++st) {
		bool flag = 1;
		for (int j = 0; j < df.size (); ++j)
			flag &= (df[j] == s[st + j]);
		res += flag;
	}			
	return res;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> s;

	d[s.size ()] = 1;
	
	for (int i = s.size () - 1; i > 4; --i) {
		int val1 = oo, val2 = oo;
		if (i + 2 <= s.size ()) {
			string q;
			q += s[i];
			q += s[i + 1];
			val1 = entry (q, i + 2);
		}
		if (i + 3 <= s.size ()) {
			string q;
			q += s[i];
			q += s[i + 1];
			q += s[i + 2];
			val2 = entry (q, i + 3);
		}
		if (!val1 && d[i + 2]) {
			string q;
			q += s[i];
			q += s[i + 1];
			ans.eb (q);
			d[i] = 1;
		}
		if (!val2 && d[i + 3]) {
			string q;
			q += s[i];
			q += s[i + 1];
			q += s[i + 2];
			ans.eb (q);
			d[i] = 1;
		}
	}
/*	
	for (int i = 0; i <= s.size (); ++i)
		cerr << d[i] << " ";
	
	cerr << "\n";
*/

	sort (ans.begin (), ans.end ());
	ans.resize (unique (ans.begin (), ans.end ()) - ans.begin ());
	
	cout << ans.size () << "\n";

	
	for (auto it : ans)
		cout << it << "\n";
	
	return 0;
}