/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

struct point {
	int x, y;
	int id;
	point () {
	
	}
};

ll operator ^ (const point &a, const point &b) {
	return (1ll * a.x * b.y) - (1LL * a.y * b.x);
}
             
bool vec_cmp (const point &a, const point &b) {
	ll cp = a ^ b;
	return (cp ? cp > 0 : a.x < b.x);
}
                          
inline bool cmp (const point &a, const point &b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int n;
int s1, s2;
point b[N];

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i].x >> b[i].y;
		b[i].id = i;
	}
	sort (b + 1, b + n + 1, cmp);
	sort (b + 1, b + n + 1, vec_cmp);
	cout << b[1].id << " " << b[2].id << " " << b[3].id;
	return 0;
}