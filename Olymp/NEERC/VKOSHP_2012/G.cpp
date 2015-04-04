#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int n, m, a, b[1000];
int main()
{
	freopen("loudcats.in","r",stdin);
	freopen("loudcats.out","w",stdout);
	cin >> n >> m >> a;
	for(int i = 1; i <= n * m; i++)
	{	
		cin >> b[i];
	}
	int ans = 0;
	for(int i = 1; i <= n * m; i++)
	{	
		if(i + m <= n * m)
		{
			if(b[i + m] > b[i] * 2)
			{   	
				ans += a;
			}
		}
	}
	cout << ans;
	return 0;

}