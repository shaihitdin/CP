#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>                              
using namespace std;
#define fname "prizes"
#define ull unsigned long long
#define ll long long
#define INF 1000*1000*1000
const int N = 210;
double t, alpha;
int n, k, sum, ss[N]={0};
struct node {
	int cost, a[202];
	void setcost () {
		cost = 0;
		for (int i = 1; i <= n; ++i) ss[a[i]] += i;
		for (int i = 1; i <= k; ++i) cost += abs(sum - ss[i]),ss[i]=0;
	}
}cur, best, nxt;
int main ()
{
//	freopen (fname".in","r",stdin);
//	freopen (fname".out","w",stdout);
	srand(time(0));          
	cin >> n >> k;
	alpha = 0.99;
	t = n;
	sum = (n * (n + 1) / 2);
	if (sum % k != 0) {
		cout << 0;
		return 0;
	}
	sum /= k;
	int tek = 1;
	for (int i = 1; i <= n; ++i) {
		cur.a[i] = tek;
		tek++;
		if (tek > k) tek = 1;
	}
	cur.setcost();
	best = cur;
	int step = 0;	
	while (cur.cost != 0) {
		step++;
		if (step > 500000) {
                	cout << 0;
                	return 0;
		}
		nxt = cur;
		for (int i = 1; i <= int(t)+1; ++i) {
			swap (nxt.a[(rand() % n) + 1], nxt.a[(rand() % n) + 1]);
		}
		nxt.setcost();
		double d = (nxt.cost - cur.cost);
		if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024) {
			cur = nxt;			
		}
		cur.setcost();
//		if (cur.cost < best.cost) best = cur;
		t *= alpha;
	}

	for (int i = 1; i <= k; ++i  ) {
		for (int j = 1; j <= n; ++ j) {
			if (cur.a[j] == i) cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}