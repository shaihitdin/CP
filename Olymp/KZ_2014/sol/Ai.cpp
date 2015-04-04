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
using namespace std;
const int INF = 1000000000;
inline bool is_prime(const long long &n)
{
        for(long long i = 2; i * i <= n; i++)
        {
                if(n % i == 0)
                {
                        return 0;
                }
        }
        return 1;
}
int main()
{
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
        long long n;
        cin >> n;
        if(n <= 13)
        {
                cout << -1;
                return 0;
        }
        long long val;
        if(n % 2 == 0)                                                
        {
                cout << "2 2 2 2 2 ";
                n -= 10;
        }
        else
        {
                cout << "2 2 2 2 3 ";
                n -= 11;
        }
        for (long long i = n - 2; i >= 2; i--)
        {
                if (is_prime(i))
                {
                	if (is_prime(n - i))
                    {
                    	cout << i << " " << n - i << endl;
                        return 0;
                    }
                }
        }
        //cerr << "QWE";
        return 0;
}