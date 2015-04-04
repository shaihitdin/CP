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
#define fname ""
#define ull unsigned long long
#define ll long long
#define INF 1000000000
const short N = 21;
struct node {
	short cost, a[N];
}cur, _next;
short n, m;
short ans;
short x[201], y[201];
double t, alpha;                 
 
 
void setcost (node &p) {  	
	p.cost = 0;
	for (short i = 1; i <= m; ++i) {
		short temp = p.a[x[i]] - p.a[y[i]];
		if (temp < 0)
			p.cost += (-temp);
		else
			p.cost += temp;
	}
}
///1457418132
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen (fname"in","r",stdin);
	freopen (fname"out","w",stdout);
	#endif
	srand(77747777);
	cin >> n >> m;
	for (short i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
	}
	
	for (short i = 1; i <= n; i ++ ) {
		cur.a[i] = i;
	}
 
	setcost(cur);
 
	t = n;
	alpha = 0.99;
	ans = cur.cost;
	int cnt;
	while (cur.cost != 0 && cnt <= 1220000) {
		_next = cur;
		for (short i = 0; i <= short(t); i ++ ) {
			swap (_next.a[rand() % n + 1], _next.a[rand() % n + 1]);
		}
		setcost(_next);
		double d = (short)(_next.cost - cur.cost);
		if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024) {
			cur = _next;			
		}
		setcost(cur);
		if (cur.cost < ans) ans = cur.cost;
		t *= alpha;
		++cnt;
	}
    cout << ans;
    return 0;
} 