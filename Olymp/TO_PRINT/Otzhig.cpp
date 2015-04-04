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
#define INF 1000*1000*1000
const int N = 500;
struct node {
	int cost, a[N];
}cur, best, _next;
int n;
bool u1[N + N], u2[N + N];
double t, alpha;                 

/*
void setcost(node &curr)
{
	curr.cost = 0;
	for (int i = 1; i <= n ; i++)
		for (int j = i + 1; j <= n; j++)
			if (abs(i - j) == abs(curr.a[i] - curr.a[j]))
				curr.cost++;
}*/

void setcost (node &p) {  	
        memset (u1, 0, sizeof u1);
        memset (u2, 0, sizeof u2);
	p.cost = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (u1[i + p.a[i]] || u2[i - p.a[i] + 450]) {
			p.cost++;
		}
		u1[i + p.a[i]] = 1;
		u2[i - p.a[i] + 450] = 1;
	}
}

int main ()
{
//	freopen (fname"in","r",stdin);
//	freopen (fname"out","w",stdout);
	srand(time(0));
	cin >> n;

	for (int i = 1; i <= n; i ++ ) {
		cur.a[i] = i;
	}

	setcost(cur);

	t = n;
	alpha = 0.99;
	best = cur;

	while (cur.cost != 0) {
		_next = cur;
		for (int i = 0; i <= int(t); i ++ ) {
			swap (_next.a[rand() % n + 1], _next.a[rand() % n + 1]);
		}
		setcost(_next);
		double d = (int)(_next.cost - cur.cost);
		if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024) {
			cur = _next;			
		}
		setcost(cur);
		if (cur.cost < best.cost) best = cur;
		t *= alpha;
	}

	for (int i = 1; i <= n; i ++ ) {
		cout << best.a[i] << " ";
	}



	return 0;
}