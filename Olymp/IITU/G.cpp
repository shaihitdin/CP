#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define N 100101
using namespace std;
long long d[N], c[N], w[N];
int sz;
struct T
{	
	int mx, pos;
} t[500100];
int n;
void build()
{
	int p = 1;
	while(p < n)
	{
		sz += p;
		p *= 2;
	}
	for(int i = 1; i <= n; i++)
	{	
		t[i + sz].mx = c[i];
		t[i + sz].pos = i;
	}
	for(int i = sz; i >= 1; i--)
	{
		t[i].mx = max(t[i * 2].mx, t[i * 2 + 1].mx);
		if(t[i*2].mx == t[i * 2 + 1].mx)
		{
			t[i].pos = max(t[i * 2].pos, t[i * 2 + 1].pos);
		}
		else if(t[i * 2].mx > t[i * 2 + 1].mx)
		{
			t[i].pos = t[i * 2].pos;
		}
		else
		{
			t[i].pos = t[i * 2 + 1].pos;
		}
	}

}
T get(int l, int r)
{
	T ans;
	//cerr << l <<" >>  " << r << " " << sz<<endl;
	
	l += sz;
	r += sz;
	ans.mx = -100;
	ans.pos = 0;
	//cerr << l << " == " << r << endl;
	while(l < r)
	{
		//cerr << l << " - " << r << endl;
		if(t[l].mx > ans.mx)
			{
				ans = t[l];
			}
			else if(t[l].mx == ans.mx)
				ans.pos = max(ans.pos, t[l].pos);
			
		if(l % 2 == 1)
		{
			l++;
		}
		if(t[r].mx > ans.mx)
			{
				ans = t[r];
			}
			else if(t[r].mx == ans.mx)
				ans.pos = max(ans.pos, t[r].pos);
			
		if(r % 2 == 0)
		{
			r--;
		}
		l /= 2;
		r /= 2;
	}
	if(l == r)
	{
		if(t[l].mx > ans.mx)
			{
				ans = t[l];
			}
			else if(t[l].mx == ans.mx)
				ans.pos = max(ans.pos, t[l].pos);
	}
	return ans;
}
int main()
{            	
	freopen("bamboo.in", "r", stdin);
	freopen("bamboo.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i] >> w[i];
		d[i] = d[i - 1] + w[i];
	}
	build();
	T t1 = get(1, n);
	int pos = t1.pos;
	cerr << pos << endl;
	long long ans = 0;
	int added = 0;
	while(pos <= n)
	{
		//if(pos == 6) break;
		ans += c[pos] * (d[pos] - added);
		added = d[pos];
		//cerr << sz;
		if(pos == n)
			break;
		if(pos + 1 <= n)
		{
		    t1 = get(pos + 1, n);
		    pos = t1.pos;
		}
		else
		{
			pos = n;
        }
		//cerr << pos << endl;
	}
	//t1 = get(n, n);
	//cerr << t1.pos << endl;
	cout << ans;
	return 0;
}