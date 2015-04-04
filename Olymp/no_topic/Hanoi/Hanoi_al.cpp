#include<iostream>
#include<stdio.h>
using namespace std;
int m,h1=1,h2=2,h3=3;
void hanoi(int n,int i,int j,int k)
{
	if(n==1)
	{
		cout<<i<<" "<<j<<endl;
	}
	else
	{
		hanoi(n-1,i,k,j);
		cout<<i<<" "<<j<<endl;
		hanoi(n-1,k,j,i);
	}
}
int main()
{
/*
	freopen("hanoi.in","r",stdin);
	freopen("hanoi.out","w",stdout);
*/
//	ios_base::sync_with_stdio(0);
	cin>>m;
	hanoi(m,h1,h2,h3);
	return 0;
}
	