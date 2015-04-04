/**
	���� ����������, � ���������� ��� �����. 
	�� �� ��������� �� ����� ���� ������. 
	� �� ������ ���� �� ����, �� ������, �� ���� ����� �����. 
	� �� ������ ������ � �� ���� ���������� �����. 
	� ���� ���� � ���� �� ����� �����. 
	� - ��� �� ����; 
	� - �������� �� �����; 
	� - �����, ������� ��������� �����; 
	� - ����, ������� �������� �������; 
	� - ���, ������� ����� ������; 
	� - ���, ������� �������� ������� �����. 
	� ����� ���� ����� � ����� ������� ������ � ��� ���� � �� ��� ��������.	
**/

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
#define file "growingtree."
using namespace std;
const int MOD = 1000000007;
const int N = 100001;
long long bin_pow (long long a, long long n) 
{
	long long res = 1;
	while (n)
	{
		if (n & 1) {
			res *= a;
			--n;
		}
		else {
			a *= a;
			n >>= 1;
		}
		if(res > MOD)
			res %= MOD;
	}
	return res;
}
long long dv(long long a, long long b)
{
//	return a / b;
	long long new_mod = MOD * b;
	return (a % new_mod) / b;
}
long long G_prog(long long i, long long a, long long q)
{
	return dv(a * (1 - bin_pow(q, i)), 1 - q);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
	long long n, k, t;
	cin >> n >> k >> t;
	cout << bin_pow(k, t * 2) + G_prog(t * 2, n - k, k);
	return 0;
}