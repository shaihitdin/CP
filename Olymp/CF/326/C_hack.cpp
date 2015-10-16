#include <bits/stdc++.h>

using namespace std;

multiset <int> st;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf ("%d", &x);
	}

	while (st.size () > 1) {
		auto a = st.begin ();
		int x = *a;
		++a;
		int y = *a;
		if (x == y) {
			st.erase (st.find (x));
			st.erase (st.find (x));
			st.insert (x + 1);
		} else {
			st.erase (st.find (x));
			ans += 1;
		}
	}
	
	if (st.size () > 0)
		++ans;
	
	printf ("%d\n", ans);

	
	cerr << clock () * 1000 / CLOCKS_PER_SEC;
	
	return 0;
}