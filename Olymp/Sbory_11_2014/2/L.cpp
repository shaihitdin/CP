#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "kthstr."
#define USE_MATH_DEFINES
#define mkp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;

const int N = 100100;
const int INF = 1e9 + 7;
const int max_val = 2e6;
const double eps = 0.00001;
int d[N][30];
struct node {
	int nx[N][29],sz;
	string get_ans (int &k) {
		string ans="";
		int vertex = 0;
		while (d[vertex][0] < k) {
			cerr << k << " ";
			for (int i = 0; i < 29; ++i) {
				if (k <= d[vertex][i]) {
					ans += ( (i + 'a') - 1);
					vertex = nx[vertex][i];
					break;
				}
				else
					k -= d[vertex][i];
			}
		}
		return ans;
	}
	void add_string (const string &s) {
		int vertex = 0;
		int c;
		for (int i = 0; i < s.size(); vertex = nx[vertex][c],++i) {
			c = (s[i] - 'a') + 1;
			if (!nx[vertex][c]) {
				nx[vertex][c] = ++sz;
			}
			++d[vertex][c];
		}
		++d[vertex][0];
	}

} trie;
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	int n;
	string s;
	cin >> n;
	int x;
	for (int i = 1; i <= n; ++i){
		cin >> s;
		if ('0' <= s[0] && s[0] <= '9')
			x = atoi(s.c_str());
		else
			x = -1;
		if (x == -1) {
			trie.add_string (s);
		}
		else {
			cout << trie.get_ans (x) << "\n";
		}
	}
	return 0;
}