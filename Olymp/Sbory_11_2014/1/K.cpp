#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <utility>
#include <stack>
#include <queue>
#define F first
#define S second
#define mp make_pair
#define file ""
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int N = 100001;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
	long long c, n, d = 0, cap;
	cin >> cap >> n;
	for(int i = 1; i <= n; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		d -= a;
		d += b;
		if(d < 0)
		{
			cout << "impossible";
			return 0;
		}
		else if(d != cap && c != 0)
		{
			cout << "impossible";
			return 0;
		}
		else if(d > cap) {
			cout << "impossible";
			return 0;
		}
	}
	if(d < 0)
		cout << "impossible";
	else
		cout << "possible";
	return 0;
}