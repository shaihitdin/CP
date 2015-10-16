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
        long long n;
        cin >> n;
        if (is_prime (n)) {
        	cout << 1 << "\n" << n;
			return 0;
        }
		if (n <= 10) {
        	    for (long long i = n - 2; i >= 2; i--)
        		{
                	if (is_prime(i))
                	{
                		if (is_prime(n - i))
                	    {
               		     	cout << 2 << "\n";
               		     	cout << i << " " << n - i;
               	         return 0;
               	     }
              	  }
	        }
		
		}
		cout << "3\n";
		int x = 2 + (n & 1);
		cout << x << " ";        	    
		n -= x;        	    
        	    for (long long i = n - 2; i >= 2; i--)
        		{
                	if (is_prime(i))
                	{
                		if (is_prime(n - i))
                	    {
               		     	cout << i << " " << n - i;
               	         return 0;
               	     }
              	  }
	        }
 		//cerr << "QWE";
        return 0;
}