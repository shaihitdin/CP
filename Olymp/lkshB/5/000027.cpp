//Solution by Daniyar Maminov                                                                                                                                                                     
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#define mp make_pair
#define f first
#define pb push_back
#define s second
#define ub upper_bound
#define lb lower_bound
#define inf 1000*1000*1000
using namespace std;

const int nn=(1<<30);

long long n, m, i, j, x, y;

char ch;

struct node
{
	int l, r;
	long long sum;
}t[3010101];


long long xx, yy, p, q, z;

int sz=2;

void upd(int vv, long long x, int v=1, int tl=0, int tr=nn-1)
{
	if (tl>tr) return ;
	if (tl==tr)
	{
		t[v].sum=x;
		return ;
	}
	int tm=(tl+tr)>>1;
	if (vv<=tm)
	{
		if (!t[v].l) t[v].l=sz++;
		upd(vv, x, t[v].l, tl, tm);
	}
	else
	{
		if (!t[v].r) t[v].r=sz++;
		upd(vv, x, t[v].r, tm+1, tr);
	}
	t[v].sum=t[t[v].l].sum+t[t[v].r].sum;
}	

long long sum(int l, int r, int v=1, int tl=0, int tr=nn-1)
{
	if (!v) return 0;
	if (l>tr || r<tl) return 0;
	if (l<=tl && tr<=r) return t[v].sum;
	int tm=(tl+tr)>>1;
	return sum(l, r, t[v].l, tl, tm)+sum(l, r, t[v].r, tm+1, tr);
}

int main()
{
	freopen ("in","r",stdin);
	freopen ("out","w",stdout);
	cin>>n>>m;
	p=91, q=47;
	for (i=1; i<=m; i++)
	{
		cin>>ch;
		scanf("%d%d", &x, &y);
		if (ch=='!')
		{
			upd((x+p)%n, (y+q)%1000000007);
		}
		else
		{
			if ((x+p)%n<(y+q)%n)
				z=sum((x+p)%n, (y+q)%n);
			else
				z=sum((y+q)%n, (x+p)%n);
			printf("%lld\n", z);
			p=(p*31+z)%1000000007; 
			q=(q*29+z)%1000000007;
		}
	}

	return 0;
}