#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>


using namespace std;

typedef long long ll;
typedef unsigned int ui;

#define mkp make_pair
#define F first
#define S second

const int N = 101;
int d[31][31][31][436];
int s[31 * 31 * 31 * 436], stq, enq;

class ABC {

	public:
	int to_int (const int &a, const int &b, const int &c, const int &sum) {
		return (sum | (a << 10) | (b << 15) | (c << 20));
	}
	
	public:
	pair <pair <int, int>, pair <int, int> > from_int (int x) {
		int c = x >> 20;
		x ^= (c << 20);
		int b = x >> 15;
		x ^= (b << 15);
		int a = x >> 10;
		x ^= (a << 10);
		int sum = x;
		return mkp (mkp (a, b), mkp (c, sum));
	}

    public:
	string get_ans (int a, int b, int c, int sum) {
		string res;

		while (a != 0 && b != 0 && c != 0 && sum != 0) {
			pair <pair <int, int>, pair <int, int> > v = from_int (d[a][b][c][sum]);
			int a1 = v.F.F, b1 = v.F.S, c1 = v.S.F, sum1 = v.S.S;	
			
			if (a == a1 + 1) {
				res += 'A';
			}
			
			else if (b == b1 + 1) {
				res += 'B';			
			}
			
			else {
				res += 'C';
			}
			a = a1;
			b = b1;
			c = c1;
			sum1 = sum;
		}
		reverse (res.begin(), res.end());
	}

    public:
    string createString (int N, int K) {
		d[0][0][0][0] = 0;
		s[enq++] = to_int (0, 0, 0, 0);
		while (stq < enq) {
			int temp = 0;
			pair <pair <int, int>, pair <int, int> > v = from_int (temp = s[stq++]);
			int a = v.F.F, b = v.F.S, c = v.S.F, sum = v.S.S;
			if (a + b + c == N && sum == K) {
				return get_ans (a, b, c, sum);
			}
			
			if (!d[a + 1][b][c][sum]) {
				d[a + 1][b][c][sum] = temp;
				s[enq++] = to_int (a + 1, b, c, sum);
			}
			if (!d[a][b + 1][c][sum + a]) {
				d[a][b + 1][c][sum + a] = temp;
				s[enq++] = to_int (a, b + 1, c, sum + a);
			}
			if (!d[a][b][c + 1][sum + a + b]) {
				d[a][b][c + 1][sum + a + b] = temp;
				s[enq++] = to_int (a, b, c + 1, sum + a + b);
			}
		}
		return "";
    }

};
