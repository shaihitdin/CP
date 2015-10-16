#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

pair <int, int> a[N], b[N];
pair <int, int> oa[N], ob[N];
int n;

inline int check (vector <pair <int, int> > &aa) {
	int sum = 0;
	for (int i = 0; i < aa.size (); ++i) {
		sum += oa[aa[i].first].first - ob[aa[i].second].first;
		if (abs(sum) > (n - i + 1) * 6) {
			return i;
		}
	}
	return aa.size ();
}

vector <pair <int, int> > tmp, ans;

inline void check () {
	tmp.resize (0);
	for (int i = 1; i <= n; ++i)
		tmp.push_back ({a[i].second, b[i].second});
	if (check (tmp) > check (ans))
		ans = tmp;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i].first;

	for (int i = 1; i <= n; ++i)
		cin >> b[i].first;
	
	
	for (int i = 1; i <= n; ++i)
		a[i].second = b[i].second = i;	                     
	             
	           sort(a+1,a+n+1);sort(b+1,b+n+1);long long as=0,bs=0;for(int i=1;i<=n;i++)as+=a[i].first,bs+=b[i].first;if(as>bs){reverse(b+1,b+n+1);}else{reverse(a+1,a+n+1);}for(int i=1;i<=n;i++)cout<<a[i].second<<' '<<b[i].second<<endl;
	           return 0;
}