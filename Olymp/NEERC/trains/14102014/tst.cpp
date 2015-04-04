#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
using namespace std;
///tmppos 1 - both, 2 - homo, 3 - hetero, 4 - neither
map<int,int> mp;

int main(){
	ios_base::sync_with_stdio(0);
	mp[3]=0;
	mp.erase(3);
	cout<<++mp[3];
	return 0;
}